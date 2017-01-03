#include <stdio.h>

int main(void)
{
	unsigned char a;

	a = 0b10001;
	printf("%d\n", 0b10001);
	printf("%d\n", a);
	printf("%d\n", 0b10001 ^ 0b111111);
	printf("%d\n", a ^ 0b111111);
	printf("%d\n", ~0b10001);
}
