#include<bits/stdc++.h>
using namespace std;

int countNPalin(int);
int createPalin(int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << countNPalin(n) << endl;
    }
    return 0;
}

int countNPalin(int n){
    int isOdd, s, count = 0, m = n;
    if(n % 2 == 0){
        isOdd = 0;
        n = n / 2;
        s = 1;
        n--;
        while(n--)
            s = s * 10;
    }
    else{
        isOdd = 1;
        n = n / 2;
        s = 1;
        while(n--)
            s = s * 10;
    }
    int e = 9;
    m--;
    while(m--){
        e = e * 10 + 9;
    }
    for(int i = s; i <= e; i++)
        if(createPalin(i, isOdd) <= e)
            count++;
        else
            break;
    return count;
}

int createPalin(int num, int isOdd){
    int palin = num;

    if(isOdd)
        num /= 10;
    while(num){
        palin = palin * 10 + (num % 10);
        num /= 10;
    }
    return palin;
}
