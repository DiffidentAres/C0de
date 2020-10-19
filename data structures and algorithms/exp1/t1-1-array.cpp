#include <iostream>
using namespace std;

int m, n;

int main(){
    scanf("%d %d", &n, &m);
    int* a = new int[n+1];
    int* b = new int[m+1];
    for (int i = n; i >= 0; i--) scanf("%d", &a[i]);
    for (int i = m; i >= 0; i--) scanf("%d", &b[i]);
    int* ans = new int[m+n+1]();
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= m; j++)
                ans[i+j] = ans[i+j] + a[i] * b[j];
    for (int i = m+n; i >= 0; i--)
        if(ans[i] != 0) 
            printf("%d %d ", ans[i], i); 
    return 0;
}