#include <stdio.h>

int main()
{
    char message[5] = {'a', 'b', 'c', '\0', 'e'};
    char message2[5] = {'a', 'b', 'c', 'd', '\0'};
    
    printf("message = %s, message2 = %s", message, message2);
    
    return 0;
}