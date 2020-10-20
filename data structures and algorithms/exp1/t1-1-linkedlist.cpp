#include <iostream>
using namespace std;

// 2 3 
// 2 1 0
// 3 2 1 0
// out: 6 5 7 4 4 3 1 2

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
    polynode* ans = new polynode; ans->next = NULL;
    polynode* i = a->next;
    while (i != NULL){
        polynode* j = b->next;
        while (j != NULL){
            int coef = i->coef * j->coef;
            int exp = i->exp + j->exp;
            InsertNode(coef, exp, ans);
            j = j->next;
        }
        i = i->next;
    }
    OutputPlolynoe(ans);
    return 0;
}