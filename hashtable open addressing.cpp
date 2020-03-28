#include<bits/stdc++.h>
using namespace std;

class HashTable{
private:
    int cap;
    int *arr;
    int size;

public:
    HashTable(int cap){
        this->cap = cap;
        arr = new int[cap];
        size = 0;

        for(int i = 0; i < cap; i++)
            arr[i] = 0;
    }

    void insert(int data){
        if(size == cap){
            cout << "Full" << endl;
            return;
        }
        size++;
        int index = data % cap;
        while(arr[index] != 0 && arr[index] != -1){
            index = (index + 1) % cap;
        }
        arr[index] = data;
    }

    void search(int data){
        if(size == 0){
            cout << "Empty" << endl;
            return;
        }
        int index = data % cap;
        bool flag = false;
        int count = cap;
        while(arr[index] != 0 && count--){
            if(arr[index] == data){
                cout << "Found at index " << index << endl;
                flag = true;
                break;
            }
            index = (index + 1) % cap;
        }
        if(!flag)
            cout << "Not found" << endl;
    }

    void deleteData(int data);

    void display(){
        for(int i = 0; i < cap; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void HashTable::deleteData(int data){
    if(size == 0){
        cout << "Empty" << endl;
        return;
    }
    size--;
    int index = data % cap;
    bool flag = false;
    int count = cap;
    while(arr[index] != 0 && count--){
        if(arr[index] == data){
            arr[index] = -1;
            cout << "Deleted" << endl;
            flag = true;
            break;
        }
        index = (index + 1) % cap;
    }
    if(!flag)
        cout << "Not found" << endl;
}

int main(){
    HashTable h(7);

    h.insert(76);
    h.insert(93);
    h.insert(40);
    h.insert(47);
    h.insert(10);
    h.insert(55);
    h.insert(4);
    h.display();

    h.search(47);
    h.search(55);
    h.search(93);
    h.search(3);

    h.deleteData(47);
    h.deleteData(93);
    h.deleteData(4);
    h.display();
    h.search(9);
    h.deleteData(9);

    return 0;
}
