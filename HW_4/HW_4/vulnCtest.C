#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char** argv) {

	for (int i=0; i<100000000000; i++) {
		srand(i);
		if (rand()==728666055) {
			printf("%d", i);
			break;
		};
	};
}
