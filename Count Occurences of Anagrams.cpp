/*
Given a word S and a text C. Return the count of the occurences of anagrams of the word in the text.
*/

#include<bits/stdc++.h>
using namespace std;

int countOccurence(string, string);
bool isAnagram(string, string);

int main(){
	int t;
	string S, C;

	cin >> t;
	while(t--){
	    cin >> S >> C;
	    cout << countOccurence(S, C) << endl;
	}
	return 0;
}

int countOccurence(string S, string C){
    int count = 0, w = C.length();
    string temp;

    for(int i = 0; i <= S.length() - w; i++){
        temp = S.substr(i, w);
        if(isAnagram(temp, C))
            count++;
    }
    return count;
}

bool isAnagram(string a, string b){
    int flag;

    for(int i = 0; i < b.length(); i++){
        flag = 0;
        for(int j = 0; j < a.length(); j++){
            if(b[i] == a[j]){
                a[j] = '?';
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return false;
    }
    return true;
}
