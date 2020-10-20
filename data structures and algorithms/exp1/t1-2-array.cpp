#include <iostream>
using namespace std;

// 5 2
// 6 3 3 2 0 1 
// 1 0 1
// out: 6 3 3 2 -3 1 -1 0
//      3 1 2 0

// 2 3
// 2 1 0
// 3 2 1 0
// out: 0 0
//      2 2 1 1
int m, n;
int GetMax(int* a){
    for (int i = n; i >=0; i--){
        if (a[i] != 0) return i;
    }
    return 0;
}

int main(){
    scanf("%d %d", &n, &m);
    int* a = new int[n+1]();
    int* b = new int[m+1]();
    int* q = new int[n+1]();
    for (int i = n; i >= 0; i--) scanf("%d", &a[i]);
    for (int i = m; i >= 0; i--) scanf("%d", &b[i]);
    if (m > n){
        printf("0 0\n");
        for (int i = n; i >= 0; i--){
            if (a[i] != 0){
                printf("%d %d ", a[i], i);
            }
        }
        printf("\n");
        return 0;
    }
    int max = GetMax(a);
    while (max >= m){
        int c = a[max];
        q[max-m] += c;
        for (int i = m, j = max; i >=0; i--, j--){
            a[j] = a[j] - c*b[i];
        }
        max = GetMax(a);
    }
    for (int i = n-m; i >= 0; i--){
        if (q[i] != 0) {
            printf("%d %d ", q[i], i);
        }
    }
    printf("\n");
    for (int i = m-1; i >= 0; i--){
        if (a[i] != 0){
            printf("%d %d ", a[i], i);
        }
    }
    printf("\n");
    return 0;
}
