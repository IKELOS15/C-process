#include <stdio.h>

// 전역 변수 선언
int itemCount = 0;   // 현재 등록된 상품의 수

// 구조체 선언
struct item {
    int ID;            // 상품 ID
    char name[100];    // 상품명
    int price;         // 판매 가격
    int stock;         // 입고량 (재고)
    int sold;          // 판매량
    int totalSales;    // 총 판매금액
} ITEMS[5];

// 입고 함수
void itemstore() {
    int id, quantity, price;
    char name[100];
    
    printf("상품 ID 입력: ");
    scanf("%d", &id);

    // 기존 상품이 있는지 확인
    for (int i = 0; i < itemCount; i++) {
        if (ITEMS[i].ID == id) {
            // 기존 상품이 있을 경우 재고 업데이트
            printf("기존 상품입니다. 상품명: %s, 현재 재고: %d\n", ITEMS[i].name, ITEMS[i].stock);
            printf("추가할 입고량 입력: ");
            scanf("%d", &quantity);
            ITEMS[i].stock += quantity;
            printf("입고가 완료되었습니다. 현재 재고: %d\n", ITEMS[i].stock);
            return;
        }
    }

    // 새로운 상품 추가
    if (itemCount < 5) {
        ITEMS[itemCount].ID = id;
        printf("새로운 상품입니다. 상품명을 입력하세요: ");
        scanf("%s", ITEMS[itemCount].name);
        printf("입고량을 입력하세요: ");
        scanf("%d", &quantity);
        printf("판매가격을 입력하세요: ");
        scanf("%d", &price);

        ITEMS[itemCount].stock = quantity;
        ITEMS[itemCount].price = price;
        ITEMS[itemCount].sold = 0;
        ITEMS[itemCount].totalSales = 0;

        itemCount++;
        printf("상품이 등록되었습니다.\n");
    }
    else {
        printf("더 이상 상품을 추가할 수 없습니다.\n");
    }
}

// 판매 함수
void itemsold() {
    int id, quantity;

    printf("판매할 상품 ID 입력: ");
    scanf("%d", &id);

    // 상품이 존재하는지 확인
    for (int i = 0; i < itemCount; i++) {
        if (ITEMS[i].ID == id) {
            printf("판매할 수량 입력: ");
            scanf("%d", &quantity);

            if (quantity > ITEMS[i].stock) {
                printf("재고가 부족합니다. 현재 재고: %d\n", ITEMS[i].stock);
                return;
            }

            // 재고 감소 및 판매 정보 업데이트
            ITEMS[i].stock -= quantity;
            ITEMS[i].sold += quantity;
            ITEMS[i].totalSales += quantity * ITEMS[i].price;

            printf("상품 [%s] 판매 완료. 남은 재고: %d\n", ITEMS[i].name, ITEMS[i].stock);
            return;
        }
    }
    printf("존재하지 않는 상품 ID입니다.\n");
}

// 개별 상품 정보 출력 함수
void singleitem() {
    int id;
    printf("상품 ID 입력: ");
    scanf("%d", &id);

    // 해당 ID의 상품 정보를 출력
    for (int i = 0; i < itemCount; i++) {
        if (ITEMS[i].ID == id) {
            printf("상품명: %s\n", ITEMS[i].name);
            printf("가격: %d\n", ITEMS[i].price);
            printf("재고: %d\n", ITEMS[i].stock);
            printf("판매량: %d\n", ITEMS[i].sold);
            printf("총 판매금액: %d\n", ITEMS[i].totalSales);
            return;
        }
    }
    printf("존재하지 않는 상품 ID입니다.\n");
}

// 전체 상품 정보 출력 함수
void allitem() {
    if (itemCount == 0) {
        printf("등록된 상품이 없습니다.\n");
        return;
    }

    printf("\n전체 상품 정보:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d\n 상품명: %s\n 가격: %d\n 재고: %d\n 판매량: %d\n 총 판매금액: %d\n", ITEMS[i].ID, ITEMS[i].name, ITEMS[i].price, ITEMS[i].stock, ITEMS[i].sold, ITEMS[i].totalSales);
    }
}

// 메인 함수
int main() {
    int menu = 0;

    while (1) {
        printf("원하는 메뉴를 선택하세요: 1.입고, 2.판매, 3.개별현황, 4.전체현황, 5.종료: ");
        scanf("%d", &menu);
        if (menu == 1) {
            itemstore();
        } else if (menu == 2) {
            itemsold();
        } else if (menu == 3) {
            singleitem();
        } else if (menu == 4) {
            allitem();
        } else if (menu == 5) {
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("잘못된 메뉴 선택입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}
