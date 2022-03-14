#include <stdio.h>
#include <stdlib.h>
 
int main ()
{
    int code;
    int n;
    printf("Введите 0 или 1. 0 - кодирование, 1 - декодирование");
    scanf("%d", &code);
    if (code == 1) || (code == 0)
    {
        int * a = (int*) malloc(n*sizeof(int));
        for (int i = 0; i < n; i++)
            {
            printf("%d ", i);
            scanf("%d", &a[i]);
            }
    }
    else (return(0));

}
