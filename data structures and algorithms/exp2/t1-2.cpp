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

struct status{
    int ls, le, rs, re;
};

class stack{
private:
    node* data[10000];
    int top;
public:
    stack(){
        top = 0;
    }

    void Insert(node* s){
        data[++top] = s;
    }
    
    node* Pop(){
        return data[top--];
    }

    node* Top(){
        return data[top];
    }
    bool IsEmpty(){
        if (top == 0) return true;
        else return false;
    }
};

int main(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    stack s;
    node* root = new node;
    root->data = preorder[0];
    s.Insert(root);
    int index = 0;
    for (int i = 1; i < n; i++){
        int value = preorder[i];
        node* nd = s.Top();
        if (nd->data != inorder[index]) {
            node* newnd = new node;
            newnd->data = value; newnd->lchild = NULL; newnd->rchild = NULL;
            nd->lchild = newnd;
            s.Insert(newnd);
        } else {
            while (!s.IsEmpty() && s.Top()->data == inorder[index]){
                nd = s.Top();
                s.Pop();
                index++;
            }
            node* newnd = new node;
            newnd->data = value; newnd->rchild = NULL; newnd->lchild = NULL;
            nd->rchild = newnd;
            s.Insert(newnd);
        }
    }

    queue q;
    q.Insert(root);
    int cnt = 1;
    while(!q.IsEmpty()){
        node* t = q.front();
        cout << t->data << " ";
        if(t->lchild != NULL) q.Insert(t->lchild);
        if(t->rchild != NULL) q.Insert(t->rchild);
    }
    return 0;
}