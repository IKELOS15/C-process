#include <stdio.h>
#include <string.h>

int main()
{
    char src[100];
    char dest[100];
    int result;
    
    gets(src);
    
    printf("src length = %d\n", strlen(src));    // 길이
    strcpy(dest, src);                            // 복사
    printf("src = %s, dest = %s\n", src, dest);
    gets(dest);
    printf("result = %d\n", strcmp(src, dest));    // 같으면 0
    
    return 0;
}
