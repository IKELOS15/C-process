
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
    int choice_temp;
    int item_num;
    
    printf("---------<전체 상품 입고수량 입력 1, 개별 상품 입력 2>---------\n입력: ");
    scanf("%d", &choice_temp);
    
    if(choice_temp == 1){
        for(int i = 0; i<size; i++)
        {
            printf("ID(%d) 입고 수량: ", i+1);
            scanf("%d", &temp);
            *(array+i) += temp;
        }
    }
    else if(choice_temp == 2){
        printf("상품의 번호: ");
        scanf("%d", &item_num);
        printf("ID(%d)의 입고된 갯수: ", item_num);
        scanf("%d", &temp);
        *(array+item_num-1) += temp;
        }
    else printf("-----상응하는 메뉴가 없습니다.------\n");
    
    
    printf("\n");
}
void array_out(int* array, int size) //판매 배열에 개입
{
    int temp;
    int choice_temp;
    int item_num;
    
    printf("------<전체 상품 판매수량 입력 1, 개별 상품 입력 2>------\n입력: ");
    scanf("%d", &choice_temp);
    
    if(choice_temp == 1){
        for(int i = 0; i<size; i++)
        {
            printf("ID(%d) 판매 수량: ", i+1);
            scanf("%d", &temp);
            *(array+i) += temp;
        }
    }
    else if(choice_temp == 2){
        printf("상품의 번호: ");
        scanf("%d", &item_num);
        printf("ID(%d)의 판매된 갯수: ", item_num);
        scanf("%d", &temp);
        *(array+item_num-1) += temp;
        }
    else printf("-----상응하는 메뉴가 없습니다.------\n");
    
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
        printf("ID(%d):  %d개 ", i+1,  *(array+i));
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
    printf("\n");
}
int sell_max_item_index(int* item, int size) // 최고 판매
{
    int temp = 0;
    for(int i = 1; i<size; i++)
    {
        if (item[temp] < item[i]) temp = i;
    }
    printf("가장 많이 판매된 상품: ID(%d), 판매량: %d\n", temp+1, item[temp]);
    //printf("\n");
    return temp;
}
int sell_min_item_index(int* item, int size) // 최저 판매 
{
    int temp = 0;
    for(int i = 1; i<size; i++)
    {
        if (item[temp] > item[i]) temp = i;
    }
    printf("가장 적게 판매된 상품: ID(%d), 판매량: %d\n", temp+1, item[temp]);
    printf("\n");
    return temp;
}
void item_leftover_warm(int* item, int size) //재고 부족@@@@
{
    printf("---------재고 부족---------\n");
    for(int i = 0; i<size; i++)
    {
        if(item[i] <= 2) printf("ID(%d): 재고 부족 / 잔여 재고(%d) \n", i+1, item[i]);
    }
    printf("\n");
}
void item_naming(char* array, int number)  //상품이름 입력
{
    int temp_ch;
    int i = 0;
    while((temp_ch = getchar()) != EOF){
        array[i++]= temp_ch;
    }
    array[i] = '\0';
    printf("%d ===== %s", i, array);
}

int main()
{
    int num = 0; // 상품 갯수
    int choice_num = 0; // 메뉴 선택
    int in_item[100] = {0}; //입고 
    int out_item[100] = {0}; //판매 
    char item_name[5][100] = {0};
    int leftover_item[100] = {0}; //잔여 재고 
    int sell_max = 0; //가장 많이 판매된 것(index)
    int sell_min = 0; //가장 적게 판매된 것(index)
    
    
    num = num_item(); //5개로 고정
    do{
        printf("------원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 상품 이름, 5. 종료) ------\n");
        printf("입력: ");
        scanf("%d", &choice_num);
        if(choice_num == 1){
            array_add(in_item, num);
        }
        else if(choice_num == 2){
            array_out(out_item, num);
        }
        else if(choice_num == 3){
            array_calculate(in_item, out_item, leftover_item, num);
            array_print_all(leftover_item, num);
            sell_per(in_item, out_item, num);
            sell_max = sell_max_item_index(out_item, num);
            sell_min = sell_min_item_index(out_item, num);
            item_leftover_warm(leftover_item, num);
        }
        else if(choice_num == 4){
            printf("%d", choice_num);
            for(int  i=0; i<num; i++){
                printf("%d", i);
                item_naming(item_name[i], num);
            }
        }
    } while(choice_num != 5);
    
    printf("EEEEEEEEEEEEEEEEEEEEEENNNNNNNN        NNNNNNNNDDDDDDDDDDDDD\n\        
    E::::::::::::::::::::EN:::::::N       N::::::ND::::::::::::DDD\n\     
    E::::::::::::::::::::EN::::::::N      N::::::ND:::::::::::::::DD\n\   
    EE::::::EEEEEEEEE::::EN:::::::::N     N::::::NDDD:::::DDDDD:::::D\n\  
      E:::::E       EEEEEEN::::::::::N    N::::::N  D:::::D    D:::::D\n\ 
      E:::::E             N:::::::::::N   N::::::N  D:::::D     D:::::D\n\
      E::::::EEEEEEEEEE   N:::::::N::::N  N::::::N  D:::::D     D:::::D\n\
      E:::::::::::::::E   N::::::N N::::N N::::::N  D:::::D     D:::::D\n\
      E:::::::::::::::E   N::::::N  N::::N:::::::N  D:::::D     D:::::D\n\
      E::::::EEEEEEEEEE   N::::::N   N:::::::::::N  D:::::D     D:::::D\n\
      E:::::E             N::::::N    N::::::::::N  D:::::D     D:::::D\n\
      E:::::E       EEEEEEN::::::N     N:::::::::N  D:::::D    D:::::D\n\ 
    EE::::::EEEEEEEE:::::EN::::::N      N::::::::NDDD:::::DDDDD:::::D\n\  
    E::::::::::::::::::::EN::::::N       N:::::::ND:::::::::::::::DD\n\
    E::::::::::::::::::::EN::::::N        N::::::ND::::::::::::DDD\n\     
    EEEEEEEEEEEEEEEEEEEEEENNNNNNNN         NNNNNNNDDDDDDDDDDDDD\n");
    
    
    return 0;
}