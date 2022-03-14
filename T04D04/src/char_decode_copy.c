#include <stdio.h>
#include <stdlib.h>
 
int main ()
{
    int code;
    int n;
    char ch;
    // printf("Введите 0 или 1. 0 - кодирование, 1 - декодирование\n");
    // scanf("%d", &code);

    // if (code != 1 && code != 0)
    // {
    //     printf("Не верный символ %d\n", code);
    //     return 0;
    // }
    
    scanf("%c", &ch);
    
    int ascii = ch;
    printf("%d ", ascii);
    return 0;

}
