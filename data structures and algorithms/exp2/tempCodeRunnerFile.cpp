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