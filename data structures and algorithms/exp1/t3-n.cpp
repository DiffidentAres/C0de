#include <iostream>
#include <cstring>
using namespace std;

int Long[10010];
void GetLong(char* str){
    int i = 1, j = 0;
    Long[0] = -1;
    while (i < strlen(str)){
        if(j == -1 || str[i] == str[j]){
            Long[i++] = ++j;
        } else {
            j = Long[j];
        }
    }
}

int main(){
    char str[10010];
    scanf("%s", str);
    GetLong(str);
    int diff = strlen(str) - Long[strlen(str) - 1];
    int len = strlen(str);
    if(diff <= len / 2 && len % diff == 0) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}