#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

// constants
const char* usernames[] = {"hack", "me", "if", "you", "can","!!!!!!!!!"};
const char* passwords[] = {"O", "znotq", "znkxkluxk", "O", "ngiq", "'"}; // hashed passwords
const int USER_SIZE=9; // maximum number of characters for a username
const int PASS_SIZE=9; // maximum number of characters for a password
const int NUM_USERS=6; // the number of usernames in the system

// functions
int getUserID(char user[USER_SIZE]) {
    for (int ii=0; ii<NUM_USERS; ii++)
        if (strncmp(user, usernames[ii],USER_SIZE)==0)
            return ii; // I found the username
}

char *garble(char *pass) {
    int length = strlen(pass);
    static char *garbled = new char[length];
    for (int ii=0; ii<length; ii++)
        garbled[ii] = pass[ii] + 6;
    return garbled;
}

bool checkPass(int userID, char pass[PASS_SIZE]) {
    return strncmp(passwords[userID],garble(pass),PASS_SIZE)==0;
}

int main(int argc, char **argv) {
    char user[USER_SIZE]; // the username
    char pass[PASS_SIZE]; // the password
    int userID;    // the user ID corresponding to <user>
    
    do {
        system("date"); // prints a time stamp
        cout << "Username: "; scanf("%s", user); userID = getUserID(user);
        cout << "Password: ";	scanf("%s", pass);
        
        if (checkPass(userID,pass)) {
            cout << "Welcome " << user << ".  You may now use the system." << endl;
            exit(1);
        }
        else
            cout << "Wrong password!  Please try again." << endl;
    } while (1);
}#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

// constants
const char* usernames[] = {"hack", "me", "if", "you", "can","!!!!!!!!!"};
const char* passwords[] = {"O", "znotq", "znkxkluxk", "O", "ngiq", "'"}; // hashed passwords
const int USER_SIZE=9; // maximum number of characters for a username
const int PASS_SIZE=9; // maximum number of characters for a password
const int NUM_USERS=6; // the number of usernames in the system

// functions
int getUserID(char user[USER_SIZE]) {
    for (int ii=0; ii<NUM_USERS; ii++)
        if (strncmp(user, usernames[ii],USER_SIZE)==0)
            return ii; // I found the username
}

char *garble(char *pass) {
    int length = strlen(pass);
    static char *garbled = new char[length];
    for (int ii=0; ii<length; ii++)
        garbled[ii] = pass[ii] + 6;
    return garbled;
}

bool checkPass(int userID, char pass[PASS_SIZE]) {
    return strncmp(passwords[userID],garble(pass),PASS_SIZE)==0;
}

int main(int argc, char **argv) {
    char user[USER_SIZE]; // the username
    char pass[PASS_SIZE]; // the password
    int userID;    // the user ID corresponding to <user>
    
    do {
        system("date"); // prints a time stamp
        cout << "Username: "; scanf("%s", user); userID = getUserID(user);
        cout << "Password: ";   scanf("%s", pass);
        
        if (checkPass(userID,pass)) {
            cout << "Welcome " << user << ".  You may now use the system." << endl;
            exit(1);
        }
        else
            cout << "Wrong password!  Please try again." << endl;
    } while (1);
}