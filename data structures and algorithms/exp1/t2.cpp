#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

// 5
// 2 1 + 3 *
// out: 9

// 5
// 4 13 5 / +
// out: 6

// 13
// 10 6 9 3 + -11 * / * 17 + 5 +
// out 22

int n;
#define maxsize 10
struct stack{
    int num[maxsize];
    int top;
};

int pop(stack &s){
    return s.num[s.top--];
}

void push(stack &s, int data){
    s.num[++s.top] = data;
}

bool IsDigit(string s){
    if (s.length() == 1){
        if (s == "+" || s == "-" || s == "*" || s == "/") return false;
    }
    return true;
}

int main(){
    stack s;
    s.top = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        string t;
        cin >> t;
        if (IsDigit(t)){
            int data = stoi(t);
            push(s, data);
        } else {
            int d1 = pop(s);
            int d2 = pop(s);
            int ans;
            switch (t[0]){
                case '+':
                    ans = d2 + d1;
                    break;
                case '-':
                    ans = d2 - d1;
                    break;
                case '*':
                    ans = d2 * d1;
                    break;
                case '/':
                    ans = d2 / d1;
                    break;
            }
            push(s, ans);
        }
    }   
    cout << pop(s) << endl;
    return 0;
}