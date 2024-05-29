#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int length = strlen(s);
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    char str[N + 1];
    scanf("%s", str);

    char rev[N + 1];
    strcpy(rev, str);
    reverse(rev);

    if (strcmp(str, rev) == 0)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }

    return 0;
}