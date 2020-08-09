#include <stdio.h>

int main()
{
    char str[5] = "raman";
    int len = 5;
    int cpy_idx = 0 ; //index of the second string
    char str_cpy[5];
    for (int i=0 ; i<len ; i++)
    {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' )
        {
            str_cpy[cpy_idx] = str[i];
            cpy_idx++;
        }

    }
    str_cpy[cpy_idx] = '\0';
    printf("%s\n", str_cpy);

}
