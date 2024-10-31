#include <stdio.h>
#include <string.h>
struct Item{
    int id;
    char name[100];
    int quantity;
    int selling_price;
} X[5];
char ri[100] = "kelos_sr_1.0.3";
int main()
{
    strcpy(X[0].name , "ikelos_smg_1.0.3");
    printf("아이템: %s\n", X[0].name);
    strcpy(X[1].name , "ikelos_sr_1.0.3");
    printf("아이템: %s\n", X[1].name);
    strcpy(X[2].name , "ikelos_sg_1.0.3");
    printf("아이템: %s\n", X[2].name);
    for(int i=0; i<5; i++){
        if (strcmp(ri, X[i].name) != 0){
            printf("Id: %d sadsadsaddad\n", i);
        }
        else break;
    }
    printf("wqeqeewwq");
    return 0;
}
