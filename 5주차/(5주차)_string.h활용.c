#include <stdio.h>
#include <string.h>

int main()
{
    char src[100];
    char dest[100];
    int result;
    
    gets(src);
    
    printf("src length = %d\n", strlen(src));
    strcpy(dest, src);
    printf("src = %s, dest = %s\n", src, dest);
    gets(dest);
    printf("result = %d\n", strcmp(src, dest));
    
    return 0;
}
