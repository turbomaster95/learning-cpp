#include <stdio.h>

int main() {
	char text1 = 'A';
	char *text2 = &text1;

	printf("%c\n", text1);
	printf("%c\n", *text2);

	return 0;
}
