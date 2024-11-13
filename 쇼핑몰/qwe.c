#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
typedef struct item{
    int ID;
    char name[100];
    int price;
    int store;
    int out;
    int totalsale;
} ITEM;
int item_count = 0;

void printLine(void){
    printf("=====================================\n");
}  //printLine();

void item_in(ITEM* p, int size)
{
    int id, store_num;
    printLine();
    if(item_count >= size){
        printf("새로운 상품 추가시 상품 갯수가 초과됩니다.\n");
        return;
    } 
    printf("상품ID: ");
    scanf("%d", &id);
    // 있을때
    for(int i=0; i<size; i++){
        if(p[i].ID == id){
            printf("해당 ID의 상품이 존재합니다. 상품명: %s, 잔여 재고: %d\n", p[i].name, p[i].store);
            printf("상품명 업데이트: ");
            scanf("%s", p[i].name);
            printf("판매가격 업데이트: ");
        scanf("%d", &p[i].price);
            printf("추가 입고 수량: ");
            scanf("%d", &store_num);
            p[i].store += store_num;
            printf("업데이트가 완료되었습니다.\n");
            printLine();
            return; //돌아가
        }
    }
    //없을때
    if(item_count<5){
        printf("상품을 추가합니다. ");
        p[item_count].ID = id;
        printf("상품명: ");
        scanf("%s", p[item_count].name); //p[item_count].name은 이미 문자열 배열의 주소
        printf("입고량: ");
        scanf("%d", &p[item_count].store);
        printf("판매가격: ");
        scanf("%d", &p[item_count].price);
        printf("상품 추가가 완료 되었습니다.\n");
        printLine();
        item_count++;
    }
    
    
}

void item_sell(ITEM* p, int size)
{
    int temp, id;
    
    printLine();
    printf("상품ID: ");
    scanf("%d", &id);
    for(int i=0; i<size; i++){
        if(p[i].ID == id){
            printf("ID(%d) 상품명(%s)의 판매량: ", p[i].ID, p[i].name);
            scanf("%d", &temp);
            p[i].out += temp;
            p[i].store -= temp;
            p[i].totalsale += temp*p[i].price;
            printLine();
            return;
        }
    }
    printf("해당 ID가 존재하지않습니다.\n");
    printLine();
}

void item_select_info(ITEM* p, int size)
{
    int id;
    
    printf("=====================================\n");
    printf("상품ID: ");
    scanf("%d", &id);
    for(int i=0; i<size; i++){
        if(p[i].ID == id){
            printf("상품명: %s\n", p[i].name);
            printf("가격: %d\n", p[i].price);
            printf("잔여재고: %d\n", p[i].store);
            printf("판매량: %d\n", p[i].out);
            printf("총 판매금액: %d\n", p[i].totalsale);
            printf("=====================================\n");
            return;
        }
    }
    printf("해당 ID가 존재하지않습니다.\n");
    printf("=====================================\n");
}


void all_print(ITEM* p, int size)
{
    printf("=====================================\n");
    if (item_count == 0) {
        printf("등록된 상품이 없습니다.\n");
        printf("=====================================\n");
        return;
    }

    printf("전체 상품 정보:\n");
    for (int i = 0; i < item_count; i++) {
        printf("ID: %d 상품명: %s 판매가격: %d 잔여재고: %d 판매량: %d 총 판매금액: %d\n", p[i].ID, p[i].name, p[i].price, p[i].store, p[i].out, p[i].totalsale);
    }
    printf("=====================================\n");
}

void item_write(ITEM* p)
{
    FILE* fp = fopen("item.bin", "wb");
    if (fp == NULL) printf("파일을 열 수 없습니다.\n");
    else    fwrite(p, sizeof(ITEM), item_count, fp);
    fclose(fp);
    printf("데이터가 item.bin 파일에 저장되었습니다.\n");
    printf("=====================================\n");
}

int load_item(ITEM* p, int max) 
{
    printf("=====================================\n");
    FILE* fp;
    int fsize, fcount;
    fp = fopen("item.bin", "rb");
    if (fp == NULL) {
        printf("파일이 존재하지않습니다.\n");
        printf("=====================================\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    fcount = fsize / sizeof(ITEM);
    rewind(fp);

    for (int i = 0; i < fcount && i < max; i++) {
        fread(&p[i], sizeof(ITEM), 1, fp);  // 아이템을 직접 읽음
    }
    fclose(fp);
    printf("데이터를 item.bin 파일에서 불러왔습니다.\n");
    printf("=====================================\n");
    return fcount;
}

void print_end()
{
    printf("    EEEEEEEEEEEEEEEEEEEEEENNNNNNNN        NNNNNNNNDDDDDDDDDDDDD\n\        
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
}


int main()
{
    ITEM item[SIZE] = {0};
    int choice = 0;
    
    do{
        printf("1. 입고, 2. 판매, 3. 개별현황. 4. 전체 출력, 5. 파일 불러오기, 6. 저장 + 종료,\n");
        printf("원하는 메뉴를 선택하세요: ");
        scanf("%d", &choice);
        if (choice == 1){
            item_in(item, SIZE);
        }
        else if (choice == 2){
            item_sell(item, SIZE);
        }
        else if (choice == 3){
            item_select_info(item, SIZE);
        }
        else if (choice == 4){
            all_print(item, SIZE);
        }
        else if (choice == 5){
            item_count = load_item(item, SIZE);
        }
        else if (choice == 6){
            item_write(item);
            print_end();
        }
        else{
            printf("상응하는 메뉴가 없습니다.");
        }
        
    }while(choice != 6);
}