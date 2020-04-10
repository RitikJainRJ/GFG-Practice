#include<bits/stdc++.h>
using namespace std;

int KMP(string, string);
void getLPS(int[], int, string);

int main(){
    int t;
    string txt, pat;

    cin >> t;
    while(t--){
        cin >> txt >> pat;
        cout << KMP(txt, pat) << endl;
    }
    return 0;
}

int KMP(string txt, string pat){
    int n = txt.length(), m = pat.length();
    int lps[m], count = 0;

    getLPS(lps, m, pat);
    int i = 0, j = 0;
    while(i < n){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j == m){
            count++;
            j = lps[j - 1];
        }
        else if(i < n && pat[j] != txt[i]){
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return count;
}

void getLPS(int lps[], int n, string str){
    int i = 1, len = 0;
    lps[0] = 0;

    while(i < n){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else
                len = lps[len - 1];
        }
    }
}
