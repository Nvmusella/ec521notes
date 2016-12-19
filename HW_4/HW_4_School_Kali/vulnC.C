#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char** argv) {
    srand(time(NULL));
    if (rand()==728666055) // sometime before the homework deadline
        cout << "ec521" << endl;
}
