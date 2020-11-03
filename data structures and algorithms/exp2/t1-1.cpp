#include <iostream>
using namespace std;

int preorder[10000];
int inorder[10000];
struct node{
    int data;
    node* lchild;
    node* rchild;
};

class queue {
private:
    node* data[1000];
    int head, tail;
public:
    queue (){
        head = 0;
        tail = 0;
    }

    bool IsEmpty(){
        if (head == tail){
            return true;
        } else {
            return false;
        }
    }

    void Insert(node* n){
        data[tail++] = n;
    }

    node* front(){
        return data[head++];
    }

};

node* CreateTree(int ps, int pe, int is, int ie){
    if(ps > pe || is > ie ) {return NULL;}
    node* newnode = new node;
    newnode->data = preorder[ps];
    int i;
    for (i = is; i <= ie; i++){
        if (preorder[ps] == inorder[i]) break;
    }
    newnode->lchild = CreateTree(ps+1, ps+i-is, is, i-1);
    newnode->rchild = CreateTree(ps+i-is+1, pe, i+1, ie);
    return newnode;
}


int main(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) {cin >> preorder[i];}
    for (int i = 0; i < n; i++) {cin >> inorder[i];}
    node* tree = CreateTree(0, n-1, 0, n-1);
    queue q;
    q.Insert(tree);
    int cnt = 1;
    while(!q.IsEmpty()){
        node* t = q.front();
        cout << t->data << " ";
        if(t->lchild != NULL) q.Insert(t->lchild);
        if(t->rchild != NULL) q.Insert(t->rchild);
    }
    return 0;
}