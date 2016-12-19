#include <cstdlib>
#include <cstdio>

void display(char *format, int high) {
	for (int ii=1; ii<=high; ii++)
		printf(format,ii);
}

int main() {
	int high;
	char format2[6]="%1d\n";
	char format1[6]="%2d\n";
	char tmp[6];
	
	printf("How should I go?  ");
	scanf("%s",tmp);
	
	high = atoi(tmp);
	
	if (high>9)
		display(format1,high);
	else
		display(format2,high);
}
