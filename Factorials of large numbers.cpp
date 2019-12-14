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
        int size = dq.size();
        int c = 0;
        for(int j = size - 1; j >= 0; j--){
            int temp, ld;
            temp = i * dq[j] + c;
            ld = temp % 10;
            dq[j] = ld;
            c = temp / 10;
        }
        if(c != 0)
            dq.push_front(c);
    }
    for(int i = 0; i < dq.size(); i++)
        cout << dq[i];
}
