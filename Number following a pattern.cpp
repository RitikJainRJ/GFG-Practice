#include<bits/stdc++.h>
using namespace std;

void findSmallNum(string);

int main(){
	int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        findSmallNum(str);
        cout << endl;
    }
	return 0;
}

void findSmallNum(string str){
    int n = str.length();
    int arr[n + 1];
    int counter = 1;

    memset(arr, 0, sizeof(arr));
    int i, j = 0;
    while(j < n){
        if(str[j] == 'I'){
            i = j;
            while(j < n && str[j] == 'I')
                j++;
            for(int k = i; k < j; k++){
                arr[k] = counter;
                counter++;
            }
        }
        else if(str[j] == 'D'){
            i = j;
            while(j < n && str[j] == 'D')
                j++;
            for(int k = j; k >= i; k--){
                arr[k] = counter;
                counter++;
            }
            j++;
        }
    }
    if(arr[n] == 0)
        arr[n] = counter;
    for(int i = 0; i <= n; i++)
        cout << arr[i];
}
