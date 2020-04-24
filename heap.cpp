#include<bits/stdc++.h>
using namespace std;

class Heap{
private:
    int *arr;
    int n;
    int size;

public:
    Heap(int n){
        this->n = n;
        size = 0;
        arr = new int[n];
    }

    void push(int data){
        if(size == n){
            cout << "Full" << endl;
            return;
        }
        size++;
        int i = size - 1;
        arr[i] = data;

        while(i != 0 && arr[(i - 1) / 2] < arr[i]){
            swap(arr[(i - 1) / 2], arr[i]);
            i = (i - 1) / 2;
        }
    }

    int pop(){
        if(size == 0){
            return -1;
        }
        if(size == 1){
            size--;
            return arr[0];
        }
        size--;
        int root = arr[0];
        arr[0] = arr[size];
        heapify(0);
        return root;
    }

    void heapify(int i){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int m = i;

        if(r < size && arr[l] < arr[r])
            m = r;
        else if(l < size)
            m = l;
        if(arr[i] < arr[m]){
            swap(arr[i], arr[m]);
            heapify(m);
        }
    }
};

int main(){
    Heap h(5);

    while(1){
        int a, b;
        cin >> a;
        switch(a){
            case 0: cin >> b;
                    h.push(b);
                    break;
            case 1: cout << h.pop() << endl;
                    break;
        }
    }
    return 0;
}
