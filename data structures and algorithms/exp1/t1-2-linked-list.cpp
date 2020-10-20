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

struct polynode{
    int coef;
    int exp;
    polynode* next;
};
int m, n;

void GetPolynode(int n, polynode* a){
    polynode* q = a;
    for(int i = n; i >= 0; i--){
        int coef; scanf("%d", &coef);
        if(coef != 0){
            polynode* p = new polynode;
            p->coef = coef; p->exp = i; p->next = NULL;
            q->next = p; q = p;
        }
    }
}

void OutputPlolynoe(polynode* a){
    polynode* p = a->next;
    while(p!=NULL){
        printf("%d %d ", p->coef, p->exp);
        p = p->next;
    }
    printf("\n");
}

void InsertNode(int coef, int exp, polynode* a){
    if (a->next == NULL){
        polynode* p = new polynode;
        p->coef = coef; p->exp = exp; p->next = NULL;
        a->next = p;
    } else {
        polynode* q = a;
        polynode* p = a->next;
        while (p != NULL){
            if(p->exp == exp){
                p->coef += coef;
                return ;
            } else if (p->exp < exp){
                polynode* newnode = new polynode;
                newnode->coef = coef;
                newnode->exp = exp;
                newnode->next = p;
                q->next = newnode;
                return;
            } 
            q = p; p = p->next;
        }
        polynode* newnode = new polynode;
        newnode->coef = coef; newnode->exp = exp; newnode->next = NULL;
        q->next = newnode;
        return ;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    polynode* a = new polynode; a->next = NULL;
    polynode* b = new polynode; b->next = NULL;
    GetPolynode(n, a);
    GetPolynode(m, b);
    if (m > a->next->exp){
        printf("0 0\n");
        OutputPlolynoe(a);
        return 0;    
    }
    polynode* t = new polynode; t->next = NULL;
    while (a->next->exp >= b->next->exp){
        int coef = a->next->coef;
        int exp = a->next->exp - b->next->exp;
        InsertNode(coef, exp, t);
        polynode* p = b->next;
        while (p != NULL){
            int newcoef = -1 * coef * p->coef;
            int newexp = exp + p->exp;
            InsertNode(newcoef, newexp, a);
            p = p->next;
        }
        a = a->next;
    }
    OutputPlolynoe(t);
    OutputPlolynoe(a);
    return 0;
}