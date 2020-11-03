#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

class heap{
private:
    int data[10000];
    int size;
public:
    heap();
    void Insert(int);
    int GetMin();
    void DelMin();
    int GetSize();
};

heap::heap(){
    size = 0;
}

void heap::Insert(int x){
    size = size + 1;
    int i = size - 1;
    data[i] = x;
    while(i != 0 && data[i/2] > data[i]){
        swap(data[i], data[i/2]);
        i /= 2;
    }
}

int heap::GetMin(){
    if(size > 0){
        return data[0];
    }
    return -1;
}

void heap::DelMin(){
    data[0] = data[size-1];
    size --;
    int i = 0;
    while (true){
        int small = i;
        int l = 2 * i; int r = 2 * i + 1;
        if(l <= size-1 && data[l] < data[i]){
            small = l;
        } 
        if(r <= size-1 && data[r] < data[small]){
            small = r;
        }
        if(i != small){
            swap(data[i], data[small]);
            i = small;
        }else{
            break;
        }
    }
}

int heap::GetSize(){
    return size;
}

int main(){
    heap h;
    int x;
    while(cin >> x){
        h.Insert(x);
    }
    int ans = 0;
    while(h.GetSize() > 1){
        int t1 = h.GetMin();
        int t2 = h.GetMin();
        h.DelMin(); h.DelMin();
        h.Insert(t1+t2);
        ans = ans + t1 + t2; 
    }
    cout << ans << endl;
    return 0;
}