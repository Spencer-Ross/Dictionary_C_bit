#include <stdio.h>
#include <stdlib.h>
int ok(char *dictionaryName, char *word, int length);
int main (int argc, char **argv)
{
    char *webster_16 = "/Users/Spencer/Documents/GitHub/Dictionary_C_bit/assignment2/webster_16";
    char* tiny_9 = "/Users/Spencer/Documents/GitHub/Dictionary_C_bit/assignment2/tiny_9";
    int test0 = ok(webster_16, "featherbeddingss", 16);
    printf("6962:%i\n", test0);
    int test1 = ok(tiny_9, "featherbeddingss", 9);
    printf("6:%i\n", test1);
    int test2 = ok(webster_16, "zoo", 16);
    printf("20422:%i\n", test2);
    int test3 = ok(tiny_9, "zoo", 9);
    printf("-9:%i\n", test3);
    int test4 = ok(webster_16, "abc", 16);
    printf("16:%i\n", test4);
    int test5 = ok(tiny_9, "abc", 9);
    printf("-1:%i\n", test5);
    int test6 = ok(webster_16, "fi sh", 16);
    printf("-7048:%i\n", test6);
    int test7 = ok(tiny_9, "fi sh", 9);
    printf("7:%i\n", test7);
    int test8 = ok(webster_16, "000", 16);
    printf("-1:%i\n", test8);
    int test9 = ok(tiny_9, "000", 9);
    printf("-1:%i\n", test9);
    int test10 = ok(webster_16, "a b c ", 16);
    printf("1:%i\n", test10);
    int test11 = ok(tiny_9, "a b c ", 9);
    printf("-1:%i\n", test11);
    int test12 = ok(webster_16, "readable", 16);
    printf("??:%i\n", test12);
    int test13 = ok(tiny_9, "readable", 9);
    printf("??:%i\n", test13);
    return 0;
}