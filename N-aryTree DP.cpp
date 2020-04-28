#include<bits/stdc++.h>
using namespace std;

class NaryTree{
private:
    int n;
    vector<int> *arr;

public:
    NaryTree(int n){
        this->n = n;
        arr = new vector<int>[n];
    }

    void addEdge(int u, int v){
        arr[u].push_back(v);
    }

    int diameter(int u, int &res){
        if(arr[u].size() == 0)
            return 1;
        else{
            int max1 = 0, max2 = 0;
            for(int i = 0; i < arr[u].size(); i++){
                int temp = diameter(arr[u][i], res);
                if(temp > max1){
                    max2 = max1;
                    max1 = temp;
                }
                else if(temp > max2)
                    max2 = temp;
            }
            if(res < max1 + max2 + 1)
                res = max1 + max2 + 1;
            return max(max1, max2) + 1;
        }
    }

};

int main(){
    NaryTree root(13);
    int res = 0;

    root.addEdge(0, 1);
    root.addEdge(0, 2);
    root.addEdge(0, 3);
    root.addEdge(1, 4);
    root.addEdge(1, 5);
    root.addEdge(1, 6);
    root.addEdge(6, 7);
    root.addEdge(6, 9);
    root.addEdge(7, 8);
    root.addEdge(3, 10);
    root.addEdge(3, 11);
    root.addEdge(10, 12);
    root.diameter(0, res);
    cout << res << endl;
    return 0;
}
