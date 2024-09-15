#include <stdio.h>

int num_item() //상품 갯수 개입
{
    int temp = 0;
    printf("----------쇼핑몰 재고관리 프로그램입니다.----------\n");
    printf("상품의 갯수: ");
    scanf("%d", &temp);
    printf("\n");
    return temp;
}
void array_add(int* array, int size) //입고 배열에 개입
{
    int temp;
    printf("---------상품 입고 수량---------\n");
    for(int i = 0; i<size; i++)
    {
        printf("ID(%d) 입고 수량: ", i+1);
        scanf("%d", &temp);
        *(array+i) = temp;
    }
    printf("\n");
}
void array_out(int* array, int size) //판매 배열에 개입
{
    int temp;
    printf("---------상품 판매 수량---------\n");
    for(int i = 0; i<size; i++)
    {
        printf("ID(%d) 판매 수량: ", i+1);
        scanf("%d", &temp);
        *(array+i) = temp;
    }
    printf("\n");
}
void array_calculate(int* in, int* sell, int* fin, int size) // 남은 수량 계산
{
    for(int i = 0; i<size; i++)
    {
        *(fin+i) = *(in+i) - *(sell+i);
    }
}
void array_print_all(int* array, int size) //전체 출력
{
    printf("---------전체 잔여 수량---------\n");
    for(int i = 0; i<size; i++)
    {
        printf("ID(%d): %d개 ", i+1, *(array+i));
    }
    printf("\n");
    printf("\n");
}
void sell_per(int* in, int* out, int size) //판매량, 퍼센트
{
    printf("---------판매 정산---------\n");
    int in1 = 0;
    int out1 = 0;
    float per = 0;
    for(int i = 0; i<size; i++)
    {
        in1 += *(in+i);
        out1 += *(out+i);
    }
    per = ((float)out1/(float)in1)*100;
    printf("총 판매량: %d (판매율 %.2f%)", out1, per);
    printf("\n");
}

int main()
{
    int num = 0 ; // 상품 갯수
    int in_item[100] = {0}; //입고 수량
    int out_item[100] = {0}; //판매 수량
    int fin_item[100] = {0}; //잔여 재고 수량 
    int sell_max = 0; //가장 많이 판매된 것
    int sell_min = 0; //가장 적게 판매된 것
    
    num = num_item();
    array_add(in_item, num);
    array_out(out_item, num);
    array_calculate(in_item, out_item, fin_item, num);
    array_print_all(fin_item, num);
    sell_per(in_item, out_item, num);
    return 0;
}
