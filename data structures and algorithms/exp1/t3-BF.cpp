#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str[10010];
    cin >> str;
    int len = strlen(str);
    bool find = false;
    for (int s = 1; s <= len/2; s++){
        bool find = true;
        if(len % s == 0) {
            for (int i = 0; i < s; i ++){
                int j = i + s;
                while (j < len){
                    if (str[i] != str[j]){
                        find = false;
                        break;
                    }
                    j += s;
                }
                if(find == false) break;
            }
            if (find) {
                cout << "True" << endl;
                return 0;
            }
        }
    }
    cout << "False" << endl;
    return 0;
}