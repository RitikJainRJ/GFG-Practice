#include<bits/stdc++.h>
using namespace std;

class NaryTree{
private:
    int n;
    vector<int> *arr;

    int getHeight(int u){
        if(arr[u].size() == 0){
            return 1;
        }
        int m = 0;
        for(int i = 0; i < arr[u].size(); i++)
            m = max(m, 1 + getHeight(arr[u][i]));
        return m;
    }

public:
    NaryTree(int n){
        this->n = n;
        arr = new vector<int>[n];
    }

    void addEdge(int u, int v){
        arr[u].push_back(v);
    }

    int diameter(int u){
        if(arr[u].size() == 0){
            return 1;
        }
        int max1 = 0, max2 = 0, m;
        for(int i = 0; i < arr[u].size(); i++){
            int temp = getHeight(arr[u][i]);
            if(temp > max1){
                max2 = max1;
                max1 = temp;
            }
            else if(temp > max2)
                max2 = temp;
        }
        m = max1 + max2 + 1;
        for(int i = 0; i < arr[u].size(); i++){
            int temp = diameter(arr[u][i]);
            m = max(m, temp);
        }
        return m;
    }

};

int main(){
    NaryTree root(13);
    int e;

    cin >> e;
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        root.addEdge(a, b);
    }
    cout << root.diameter(0) << endl;
    return 0;
}
