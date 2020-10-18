#include <iostream>
#include <cstring>
using namespace std;

void GetNext(char* str, int next[]){
    int i = 0, j = -1, len = strlen(str);
    next[0] = -1;
    while (i < len){
        if (j == -1 || str[i] == str[j]){
            i++; j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int main(){
    char str[] = "abaabcac";
    int next[100];
    GetNext(str, next);
    for (int i = 0; i < strlen(str); i++){
        cout << next[i] << endl;
    }
    return 0;
}