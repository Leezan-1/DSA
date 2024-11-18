#include <stdio.h>
#include <string.h>

// C-style strings are arrays of characters declared like this:
char str[] = "Hello World!";

// They can also be declared as pointers:
const char *sttr = "Hello ,World!";

int main()
{
    printf("comapring %s and %s :  %c \n", str, sttr, strcmp(str, sttr));
    printf("W : %d | , : %d | W - , : %c\n", 'W', ',', 87 - 44);
    /*
        If the first differing character in str1 has a lower ASCII value than in str2, the result is negative.
        If it has a higher ASCII value, the result is positive.
        If the strings are identical, the result is 0.

        here, 'W' in str is greater than ',' in sttr so result is  positive
    */

    if (strcmp(str, sttr) != 0)
        printf("strings not equal\n");

    for (size_t i = 0; i < strlen(str) + 1; i++)
        printf("%c\t%c\n", str[i], sttr[i]);

    /*
        The str array stores \\0 in last element of array.
        therefore, the actual size of array is length of string + 1
    */

    return 0;
}