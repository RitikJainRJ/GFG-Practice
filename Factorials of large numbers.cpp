/*
Given an integer, the task is to find factorial of the number
*/
#include<bits/stdc++.h>
using namespace std;

void factorial(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    factorial(n);
	    cout << endl;
	}
	return 0;
}

void factorial(int n){
    deque<int> dq;

    dq.push_back(1);
    for(int i = 2; i <= n; i++){
        int m = dq.size();
        int c = 0;
        for(int j = m - 1; j >= 0; j--){
            int temp;
            temp = i * dq[j] + c;
            dq[j] = temp % 10;
            c = temp / 10;
        }
        while(c != 0){
            int temp = c % 10;
            dq.push_front(temp);
            c /= 10;
        }
    }
    for(int i = 0; i < dq.size(); i++)
        cout << dq[i];
}
