#include <stdio.h>

char* format(char* word, int length);
int ok(char *dictionaryName, char *word, int dictWidth);

int main(void) {
	char *webster_16 = "/Users/Spencer/Documents/GitHub/Dictionary_C_bit/assignment2/webster_16";
    char* tiny_9 = "/Users/Spencer/Documents/GitHub/Dictionary_C_bit/assignment2/tiny_9";
	char* word = "zoo";
	int width = 16;

	printf("%d\n", ok(webster_16, word, width));

	return 0;
}