#include <stdio.h>
#define MaxLen 1000
#include <string.h>
#define MaxLenSent 500

void reverse_sentence(const unsigned char* input, unsigned char* reversed, int start, int end) {
	int j = 0;
	for (int i = end - 1; i >= start; i--) {
		reversed[j++] = input[i];
	}
	reversed[j] = '\0';
}

int input(unsigned char(*arr)) {
	unsigned char t = ' ';
	int i = 0;
	while ((t = getchar()) && i < MaxLen) {
		if ((t == '\n') && i == 0)
			continue;
		if (t == '\n')
			break;
		arr[i] = t;
		i++;
	}
	if (i >= MaxLen) {
		printf("Error: Buffer overflow.");
		return -1;
	}
	return i;
}

void function1() {
	unsigned char a[MaxLen];
	unsigned char b[MaxLen];
	int list[256] = {0};
	int lenA = input(a);
	int lenB = input(b);
	if (lenA == -1 || lenB == -1)
		return;
	for (int i = 0; i < lenA; i++)
	{
		list[a[i]] = 1;
	}
	for (int i = 0; i < lenB; i++)
	{
		if (list[b[i]] != 1) {
			putchar(b[i]);
		}
	}
}

void function2() {
	unsigned char a[MaxLen];
	int lenA = input(a);

	if (lenA == -1)
		return;
	for (int i = 0; i < lenA; i++)
		printf("%d ", a[i]);
}

void function3() {
	unsigned char a[MaxLen];
	unsigned char b[MaxLen];
	int lenA = input(a);
	int lenB = input(b);
	
	if (lenA == -1 || lenB == -1)
		return;

	if (lenA != lenB)
	{
		printf("False");
		return;
	}

	for (int i = 0; i < lenA; i++)
	{
		if (a[i] != b[lenA - i - 1])
		{
			printf("False");
			return;
		}

	}
	printf("True");
}

void function4() {
	unsigned char a[MaxLen];
	int lenA = input(a);

	if (lenA == -1)
		return;

	if (a[0] >= 97 && a[0] <= 122)
		a[0] -= 32;

	for (int i = 1; i < lenA; i++)
		if (a[i - 1] == ' ') {
			if (a[i] >= 97 && a[i] <= 122)
				a[i] -= 32;
		}
		else {
			if (a[i] >= 65 && a[i] <= 90)
				a[i] += 32;
		}
	
	for (int i = 0; i < lenA; i++)
		printf("%c", a[i]);
}

void function9() {
	unsigned char inputArr[MaxLen];
	unsigned char reversed[MaxLenSent];
	unsigned char output[MaxLen];
	int len = input(inputArr);
	if (len == -1)
	return;

	int start = 0;
	int outIndex = 0;

	for (int i = 0; i <= len; i++) {
		if (inputArr[i] == '.' || inputArr[i] == '\0') {
			int end = i;
			reverse_sentence(inputArr, reversed, start, end);
			for (int j = start; j < end; j++) {
				output[outIndex++] = inputArr[j];
			}
			for (int j = 0; reversed[j] != '\0'; j++) {
				output[outIndex++] == reversed[j];
			}

			if (inputArr[i] == '.') {
				output[outIndex++] = '.';
				if (inputArr[i + 1] != '\0') {
					output[outIndex++] = ' ';
				}
			}
			start = i + 1;
			while (inputArr[start] == ' ') {
				start++;
			}
		}
		output[outIndex] = '\0';
		printf("%s\n", output);
}

void function5() {
	printf("  1 FUNCTION: The function accepts two strings through a line break \nand excludes from the second string all the characters that are in the \nfirst string.\n");
	printf("  2 FUNCTION: The function accepts a string and replaces each character \nwith its code. The codes are output, separated by a space, while each space \nin the original string is converted to a code in the resulting \nstring.\n");
	printf("  3 FUNCTION: The function accepts two strings and checks whether the \nfirst string is a reverse record of the second. The strings are supplied \nthrough a line break.\n");
	printf("  4 FUNCTION: The function accepts a string and converts it so that in \neach word the first letter is capitalized, and the rest are lowercase. A word \nis a set of letters and numbers, words are separated by at least \none space.");
}

int main(void) 
{
	printf("Course work for option 3.5, created by Yaroslav Kharchenko\n");
	int a;
	scanf("%d", &a);
	switch (a)
	{
	case 0:

		break;
	case 1:
		function1();
		break;
	case 2:
		function2();
		break;
	case 3:
		function3();
		break;
	case 4:
		function4();
		break;
	case 5:
		function5();
		break;
	case 9:
		function9();
		break;
	default:
		printf("Error: Can't find number of command.");
		break;
	}
	printf("\n\n");
	return 0;
}