#include <stdio.h>

int main()
{
    int num = 0;
    int item[100] ={};
    int item_total = 0;
    int sell_item = 0;
    int sell_total = 0;
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
    
    //전체 입고 수량
    for(int i = 0; i<num; i++)
    {
        item_total += item[i];
    }
    
    for(int i = 0; i<num; i++)
    {
        // 판매
        printf("%d번 상품의 판매 수량: ",i+1);
        scanf("%d", &sell_item);
        item[i] -= sell_item;
        sell_total += sell_item;
       
    }
    printf("-----------------\n");
    
    for(int i = 0; i<num; i++)
    {
        // 전체 잔여
        printf("%d번 상품의 잔여 수량: ",i+1);
        printf("%d\n", item[i]);
    }
    printf("-----------------\n");
    
    //총 판매량
    
    float sell_per = ((float)sell_total / (float)item_total)*100;
    printf("총 판매수량: %d (판매율: %.3f%)", sell_total, sell_per);
    
    
    return 0;
}
