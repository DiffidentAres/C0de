#include <iostream>
#include <fstream>
using namespace std;

int parent[20020];
int count[20020];

int Find(int x);
void Union(int x, int y);
void Init(int x);

int Find(int x){
    if (x != parent[x]){
        x = parent[x];
    }
    return x;
}

void Union(int x, int y){
    if(parent[x] == -1) {Init(x);}
    if(parent[y] == -1) {Init(y);}
    int fx = Find(x); int fy = Find(y);
    if(fx == fy) {return; }
    int cx = count[fx]; int cy = count[fy];
    if(cx > cy){
        parent[fy] = fx;
        count[fx] += count[fy];
    } else {
        parent[fx] = fy;
        count[fy] += count[fx];
    }
}

void Init(int x){
    parent[x] = x;
    count[x] = 1;
}

int main(){
    ifstream File("./problem3_sample.txt", ios::in);
    int a, b;
    File >> a >> b;
    for (int i = 0; i < a; i++){
        parent[i] = -1;
    }
    for (int i = 0; i < b; i++){
        int n; File >> n;
        int g1; File >> g1;
        Union(g1, g1);
        for (int j = 1; j < n; j++){
            int g; File >> g;
            Union(g, g1);
        }
    }
    cout << count[Find(0)] << endl;
    return 0;
}