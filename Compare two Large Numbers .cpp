/*
You will be given two numbers A and B. Your task is to print 1 if A < B, print 2 if A > B
and print 3 if A = B.
*/
#include<bits/stdc++.h>
using namespace std;

void compare(string, string);

int main(){
	int t;
	string A, B;

	cin >> t;
	while(t--){
	    cin >> A >> B;
	    compare(A, B);
	    cout << endl;
	}
	return 0;
}

void compare(string A, string B){
    while(1){
        if(A[0] == '0')
            A.erase(A.begin());
        else
            break;
    }
    while(1){
        if(B[0] == '0')
            B.erase(B.begin());
        else
            break;
    }
    if(A.length() > B.length()){
        cout << 2;
        return;
    }
    else if(A.length() < B.length()){
        cout << 1;
        return;
    }
    else{
        for(int i = 0; i < A.length(); i++){
            if((A[i] - '0') > (B[i] - '0')){
                cout << 2;
                return;
            }
            else if((A[i] - '0') < (B[i] - '0')){
                cout << 1;
                return;
            }
        }
        cout << 3;
        return;
    }
}
