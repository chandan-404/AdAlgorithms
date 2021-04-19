#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define txt 200
#define word 20

void prefixToSuffix(char *pat, int M, int *pps)
{
    int length = 0;
    pps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[length])
        {
            length++;
            pps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
                length = pps[length - 1];
            else
            {
                pps[i] = 0;
                i++;
            }
        }
    }
}
void KMPAlgorithm(char *text, char *pattern)
{
    int M = strlen(pattern);
    int N = strlen(text);
    int pps[M];
    prefixToSuffix(pattern, M, pps);
    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            printf("[+]Found pattern at index %d\n", i - j);
            j = pps[j - 1];
        }
        else if (i < N && pattern[j] != text[i])
        {
            if (j != 0)
                j = pps[j - 1];
            else
                i = i + 1;
        }
    }
}
int main()
{
    char text[txt], pattern[word];
    printf("[+]Enter a String: ");
    scanf("%s", text);
    printf("[+]Enter a Pattern: ");
    scanf("%s", pattern);
    KMPAlgorithm(text, pattern);
    return 0;
}