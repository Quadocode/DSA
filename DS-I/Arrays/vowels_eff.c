#include <stdio.h>

int main(){
    char str[5] = "raman";
    int len = 5 ; 
    for(int i = 0 ; i < len ; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' )
        {
            for (int j = i ; j < 5 ; j++)
                str[j] = str[j+1];
            len--;
            i--;
        }
    }
    printf("%s\n",str);
}

