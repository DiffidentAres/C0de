#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str[10010];
    cin >> str;
    int len = strlen(str);
    for (int s = 1; s <= len/2; s++){
        bool find = 1;
        if(len % s == 0) {
            for (int i = 0; i < s; i ++){
                int j = i + s;
                while (j < len){
                    if (str[i] != str[j]){
                        find = 0;
                        break;
                    }
                    j += s;
                }
                if(find == 0) break;
            }
            if (find) {
                cout << "True" << endl;
                return 0;
            }
            if (s == len/2 && !find){
                cout << "False" << endl;
                return 0;
            }
        }
    }
    return 0;
}