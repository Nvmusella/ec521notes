#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <cstring>
#include "getpost.h"
#include <sys/resource.h>
 
using namespace std;

// CONSTANTS
int TOP_NUM; //CHANGE 1
int length; // CHANGE 2
char text[5000];  /* The text supplied by the user. */
//int length;       /* The length supplied by the user. */
//int TOP_NUM;      /* The number of entries to show the user. */

// CLASSES
class cStringMap {
  // implements a map from C-style strings to integers

public:
  int& operator[](char *key) { return data[key];}

  char *topValue() {
    static char *result;
    map<char *,int>::iterator iter;
    int maxSeen = -1;
    
    for (iter = data.begin(); iter != data.end(); iter++)
      if (iter->second > maxSeen) { // I found a value bigger than maxSeen
	maxSeen = iter->second;     // record the value
	result = iter->first;       // record the key that produced the value
      }

    return result;
  }

  void print() {
    map<char *,int>::iterator iter;
    for (iter = data.begin(); iter != data.end(); iter++)
      cout << iter->first << ": " << iter->second << endl;
    cout << endl;
  }

private:
  class cmp_str { // a class for comparing C-style strings
  public:
    bool operator()(char *a, char *b) { return strcmp(a,b) < 0; }
  };
  map<char *,int, cmp_str> data;
};


// FUNCTIONS
char **topValues(cStringMap &patterns) {
  // Returns the TOP_NUM keys with the highest values in <patterns>
  char **top_entries = new char *[TOP_NUM];
  char tmp[TOP_NUM];

  for (int ii=0; ii<TOP_NUM; ii++) {
    strncpy(tmp,patterns.topValue(),TOP_NUM); //CHANGE 3
    top_entries[ii]=patterns.topValue(); // extract the key with the largest value
    patterns[tmp]*=-1;         // make the value small so that we do not choose it again
  }

  // fix all negative numbers so that they are positive again, as they were initially
  for (int ii=0; ii<TOP_NUM; ii++)
    patterns[top_entries[ii]]*=-1;

  return top_entries;
}

void parse(cStringMap& patterns, int len, char *text) {
  /** Records in <patterns> the substrings of length <len> in <text>, and how often they appear. */

  for (int ii=0; ii<strlen(text) - len + 1; ii++) {
    char *substring = new char[len+1];
    strncpy(substring,text+ii,len); // copy a piece of <text> into <substring> CHANGE 4
    substring[len]=0;            // terminating character
    patterns[substring]++;       // tally this substring as seen
  }
}

int main()
{
  // initialize
  map<string,string> Get; // parameters from the server
  cStringMap patterns;    // patterns found in the text provided
  TOP_NUM = 10;

  //If this is run on the command line, uncomment the next line.
  //setenv("QUERY_STRING","len=1&text=hi%20there%20how%20are%20you?%20nmdfsdajkhfd%20",1);
  initializeGet(Get);
  length = atoi(Get["len"].c_str()); // the length inputted by the user
  strncpy(text,Get["text"].c_str(),5000);  // the text inputted by the user
  
  // set some limits on resource usage
  rlimit lim = {10,10};
  setrlimit(RLIMIT_CPU,&lim);

  // output the web page
  cout <<"Content-type: text/html"<<endl<<endl;
  cout << "<h1>" << TOP_NUM << " most common patterns of length " << length
       << ":</h1><code>" << endl;

  // populate the patterns class
  parse(patterns, length, text);
  
  // get the top TOP_NUM values
  char **result = topValues(patterns);

  // display the top values
  for (int ii=0; ii<TOP_NUM; ii++)
    cout << result[ii] << ": " << patterns[result[ii]] << "<BR>" << endl;
	
}

