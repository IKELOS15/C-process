#include <stdio.h>

int main()
{
    int num = 0;
    int item[] ={};
    int sell_item = 0;
    int choise = 0;
    
    printf("상품의 갯수: ");
    scanf("%d", &num);
    printf("-----------------\n");
    
    for(int i = 0; i<num; i++)
    {
        // 입고
        printf("%d번 상품의 입고 수량: ",i+1);
        scanf("%d", &item[i]);
    }
    printf("-----------------\n");
    
    for(int i = 0; i<num; i++)
    {
        // 판매
        printf("%d번 상품의 판매 수량: ",i+1);
        scanf("%d", &sell_item);
        item[i] -= sell_item;
    }
    printf("-----------------\n");
    //선택 잔여
    printf("원하는 상품의 잔여수량을 알려드립니다: ");
    scanf("%d", &choise);
    printf("%d번 상품의 잔여 수량은 %d개 입니다.\n", choise, item[choise-1]);
    printf("-----------------\n");
    
    for(int i = 0; i<num; i++)
    {
        // 전체 잔여
        printf("%d번 상품의 잔여 수량: ",i+1);
        printf("%d\n", item[i]);
    }
    printf("-----------------\n");
    
    
    return 0;
}