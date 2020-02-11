#include<bits/stdc++.h>
using namespace std;

int maxWindow(string, int);

int main(){
	int t, k;
	string s;

	cin >> t;
	while(t--){
        cin >> s >> k;
        cout << maxWindow(s, k) << endl;
	}
	return 0;
}

int maxWindow(string s, int k){
    int hash_str[256] = {0};
    int i = 0, j, count = 0, max = -1;

    for(j = 0; j < s.length(); j++){
        hash_str[s[j]]++;
        if(hash_str[s[j]] == 1)
            count++;
        if(count == k + 1){
            int temp = j - i;
            if(max < temp)
                max = temp;
            while(1){
                hash_str[s[i]]--;
                if(hash_str[s[i]] == 0)
                    break;
                i++;
            }
            i++;
            count--;
        }
    }
    int temp = j - i;
    if(count == k && max < temp)
        max = temp;
    return max;
}
