#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x;
    int y;
}POINT;

int inputmenu(void){
    int input;
    printf("1. 만들기, 2. 출력하기, 3. 클리어, 4. 파일저장, 5.파일로드, -1. 종료: ");
    scanf("%d", &input);
    return input;
}

POINT* makepoint(void){
    POINT* p = (POINT*)malloc(sizeof(POINT));
    p->x = rand() % 100;
    p->y = rand() % 100;
    return p;
}

void printpoint(POINT* p[], int size){
    for(int i=0; i<size; i++) 
        printf("x - %d, y - %d\n", p[i]-> x, p[i]->y);
}

void freepoints(POINT* p[], int size){
    for(int i=0; i<size; i++) 
        free(p[i]);
}

int saveFile(POINT* p[], int size){
    FILE* fp;
    fp = fopen("points.bin","ab");
    if(fp == NULL) return 0;
    for(int i=0; i<size; i++) 
        fwrite(p[i], sizeof(POINT), 1, fp);
    fclose(fp);
    return 1;
}

int loadFile(POINT* p[], int max){
    FILE* fp;
    int fsize, fcount;
    fp = fopen("points.bin","rb");
    if(fp == NULL) return 0;
    
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    fcount = fsize / sizeof(POINT);
    rewind(fp);
    
    for(int i=0; i<fcount; i++){
        if(i == max) break;
        p[i] = (POINT*)malloc(sizeof(POINT));
        fread(p[i], sizeof(POINT), 1, fp);
    }
    fclose(fp);
    return fcount;
}
int main()
{
    int menu;
    int count = 0;
    POINT* points[100];
    do{
        menu = inputmenu();
        switch(menu){
            case 1:
                points[count] = makepoint();
                count++;
                break;
            case 2:
                printpoint(points, count);
                break;
            case 3:
                system("clear"); // window - system("cls")
                break;
            case 4: //file save
                if(!saveFile(points, count)) printf("file open error...\n");
                else printf("file sriting succes...\n");
                break;
            case 5: //load file
                count = loadFile(points, 100);
                break;
            case -1:
                freepoints(points, count);
                printf("프로그램을 종료합니다.\n");
                break;
        }
    }while(menu > 0);
    
    return 0;
}

/*
    POINT* points;
    int count;
    scanf("%d", &count);
    
    points = (POINT*)malloc(sizeof(POINT) * count);
    
    for(int i=0; i<count; i++){
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    for(int i=0; i<count; i++){
        printf("x - %d, y - %d\n", points[i].x, points[i].y);
    }
    free(points);
*/