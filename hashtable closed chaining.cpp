#include<bits/stdc++.h>
using namespace std;

class HashTable{
private:
    int cap;
    list<int> *arr;
    int size;

public:
    HashTable(int cap){
        this->cap = cap;
        arr = new list<int>[cap];
        size = 0;
    }

    void insert(int data){
        size++;
        int index = data % cap;
        arr[index].push_back(data);
    }

    void search(int data){
        if(size == 0){
            cout << "Empty" << endl;
            return;
        }
        int index = data % cap;
        bool flag = false;
        for(auto it = arr[index].begin(); it != arr[index].end(); it++)
            if(*it == data){
                cout << "Found" << endl;
                flag = true;
                break;
            }
        if(!flag)
            cout << "Not found" << endl;
    }

    void deleteData(int data);

    void display(){
        for(int i = 0; i < cap; i++){
            cout << i << ":- ";
            for(auto it = arr[i].begin(); it != arr[i].end(); it++)
                cout << *it << " ";
            cout << endl;
        }
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
    for(auto it = arr[index].begin(); it != arr[index].end(); it++)
        if(*it == data){
            cout << "Deleted" << endl;
            flag = true;
            arr[index].erase(it);
            break;
        }
    if(!flag)
        cout << "Not found" << endl;
}

int main(){
    HashTable h(7);

    h.insert(15);
    h.insert(11);
    h.insert(27);
    h.insert(8);
    h.display();

    h.search(8);
    h.search(9);
    h.search(15);

    h.deleteData(15);
    h.deleteData(27);
    h.deleteData(27);
    h.display();

    return 0;
}
