#include<bits/stdc++.h>
using namespace std;

int palinLess(int);
int createPalin(int, int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << palinLess(n) << endl;
	}
	return 0;
}

int palinLess(int n){
    int count = 0;

    for(int i = 1; i < n; i++)
        if(createPalin(i, 0) < n)
            count++;
        else
            break;
    for(int i = 1; i < n; i++)
        if(createPalin(i, 1) < n)
            count++;
        else
            break;
    return count;
}

int createPalin(int num, int isOdd){
    int palin = num;

    if(isOdd)
        num = num / 10;
    while(num){
        palin = palin * 10 + (num % 10);
        num = num / 10;
    }
    return palin;
}
