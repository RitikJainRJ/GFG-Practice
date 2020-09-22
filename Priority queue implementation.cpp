#include<bits/stdc++.h>
using namespace std;

class PriQue{
private:
    int size;
    int n;
    int *nums;

    void decreaseKey(int ind){
        while(ind != 0){
            int p = (ind - 1) / 2;
            if(nums[p] < nums[ind]){
                swap(nums[p], nums[ind]);
                ind = p;
            }
            else
                break;
        }
    }

    void heapify(int ind){
        int left = 2 * ind + 1 < n ? 2 * ind + 1 : -1;
        int right = 2 * ind + 2 < n ? 2 * ind + 2 : -1;
        int m = ind;

        if(right != -1)
            m = nums[right] > nums[left] ? right : left;
        else if(left != -1)
            m = left;
        if(nums[ind] < nums[m]){
            swap(nums[ind], nums[m]);
            heapify(m);
        }
    }

public:
    PriQue(int size){
        this->size = size;
        n = 0;
        nums = new int[size];
    }

    void push(int x){
        if(n == size){
            cout << "PQ is Full" << endl;
            return;
        }
        nums[n++] = x;
        decreaseKey(n - 1);
    }

    void pop(){
        if(n == 0){
            cout << "PQ is Empty" << endl;
            return;
        }
        swap(nums[0], nums[n - 1]);
        n--;
        heapify(0);
    }

    void deleteKey(int ind){
        nums[ind] = INT_MAX;
        decreaseKey(ind);
        pop();
    }

    int top(){
        return nums[0];
    }
};

int main(){
    int n;

    cin >> n;
    PriQue pq(n);

    pq.push(2);
    pq.push(8);
    pq.push(1);
    pq.push(5);
    pq.deleteKey(0);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    pq.pop();
    return 0;
}
