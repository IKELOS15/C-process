#include <stdio.h>

int main()
{
    char input[200] = "";
    int count_Cap[26] = {0};
    int count_Low[26] = {0};
    int count_Num[10] = {0};
    int count_temp = -1;
    int ch;
    int i=0;
    
    while((ch = getchar()) != EOF){
        input[i++] = ch;
    }
    
    i=0;
    while(input[i] != '\0'){
        if(input[i] >= 'A' && input[i] <= 'Z'){       //아스키코드 
            count_Cap[input[i] - 'A']++;            // ex) B - A = 1 -> count_Cap[1] 증가
        }
        else if(input[i] >= 'a' && input[i] <= 'z'){
            count_Low[input[i] - 'a']++;
        }
        else if(input[i] >= '0' && input[i] <= '9'){
            count_Num[input[i] - '0']++;
        }
        else count_temp++;                        //나머지 else -> temp++
        
        
        i++;
    }
    printf("입력문자열 : %s\n", input);
    printf("======Capitals======\n");
    for(int i=0; i<26; i++) printf("%c 출현횟수: %d\n", 'A'+i, count_Cap[i]);    
    printf("======Lowers======\n");
    for(int i=0; i<26; i++) printf("%c 출현횟수: %d\n", 'a'+i, count_Low[i]);
    printf("======Numbers======\n");
    for(int i=0; i<10; i++) printf("%c 출현횟수: %d\n", '0'+i, count_Num[i]);        // -1이유 -> 엔터?
    printf("기타문자 출현횟수: %d\n", count_temp);
    return 0;
}
