#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

int countMaxDigit(int, int, bool[]);

int main(){
	int t, l, r;
	bool sieve[MAX + 1];

	memset(sieve, true, sizeof(sieve));
	for(int i = 2; i * i <= MAX; i++)
	    if(sieve[i] == true)
	        for(int j = i * i; j <= MAX; j = j + i)
	            sieve[j] = false;
	cin >> t;
	while(t--){
	    cin >> l >> r;
	    cout << countMaxDigit(l, r, sieve) << endl;
	}
	return 0;
}

int countMaxDigit(int l, int r, bool sieve[]){
    int arr[10] = {0}, m = 0, res;
    bool flag = false;

    for(int i = max(2, l); i <= r; i++)
        if(sieve[i] == true){
            int k = i;
            while(k){
                int temp = k % 10;
                arr[temp]++;
                k = k / 10;
            }
            flag = true;
        }
    for(int i = 0; i < 10; i++){
        if(arr[i] >= m){
            m = arr[i];
            res = i;
        }
    }
    if(flag == false)
        return -1;
    return res;
}
