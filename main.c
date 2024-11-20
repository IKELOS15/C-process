#include <stdio.h>

typedef struct _lotto{
    int number[6];
    int bonus;
    int NO;
}LOTTO;

void intLotto(LOTTO* l)
{
    for(int i=0; i<6; i++) l->number[i] = 0;
    l->bonus = 0;
    l->NO = 0;
}

LOTTO creatManual(int No){
    LOTTE l;
    
}
int main()
{
    printf("Hello World");

    return 0;
}
