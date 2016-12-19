#include <cstdlib>
#include <cstdio>

void display(char *format, int high) { /*takes in format array and the input number*/
	for (int ii=1; ii<=high; ii++)  /*from the first number */
		printf(format,ii);
}

int main() {
	int high;
	char format2[6]="%1d\n";
	char format1[6]="%2d\n";
	char tmp[6]; /*The author intended for the code to take in a number user input 6 characters long */

	/*for (int i=0; i<=20; i++)
		printf(format2, i);*/
	
	printf("How should I go?  ");
	scanf("%s",tmp);
	
	high = atoi(tmp);
	
	if (high>9)
		display(format1,high);
	else
		display(format2,high);
}