#include "strings.h"

int slen(char *str)
{
    int len;
    for (int i = 0; str[i] != '\0'; i++)
        len = i;
    return len;
}

char *scpy(char *str)
{
    int i;
    int len = slen(str);
    char *scopy = (char *)malloc((len + 1) * sizeof(char));
    for (i = 0; str[i] != '\0'; i++)
        scopy[i] = str[i];

    scopy[i] = '\0';
    return scopy;
}

int scmp(char *s1, char *s2)
{
    int i, flag = 0;
    for (i = 0; (s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0'; i++);
    if (s1[i] < s2[i])
        flag = -1;
    else if (s1[i] > s2[i])
        flag = 1;
    return flag;
}

int schr(char *str, char delim)
{
    int i, indx = -1;
    for (i = 0; (str[i]) != '\0' && (str[i] != delim); i++);
    if (str[i] == delim)
        indx = i;

    return indx;
}

int stok(char *str, char delim, char **ptr)
{
    char *suf = str;
    ptr[0] = str;
    int i, j = 1;
    while ((i = schr(suf, delim)) >= 0)
    {
        suf[i] = '\0';
        suf = suf + i + 1;
        ptr[j] = suf;
        j++;
    }
    return j;
}

int scspn(char *str, char *fbs)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (schr(fbs, str[i]) >= 0)
        {
            break;
        }
    }
    return i;
}

