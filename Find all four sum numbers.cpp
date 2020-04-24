#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

void fourSum(int, int);

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        fourSum(n, k);
        cout << endl;
    }
    return 0;
}

void fourSum(int n, int k){
    int arr[n];
    multimap<int, pii> mm;
    set<vector<int>> os;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            mm.insert({arr[i] + arr[j], {i, j}});
    for(auto it1 = mm.begin(); it1 != mm.end(); it1++){
        int x = k - it1->first;
        auto itr = mm.equal_range(x);
        for(auto it2 = itr.first; it2 != itr.second; it2++){
            int a = it1->second.first, b = it1->second.second, c = it2->second.first, d = it2->second.second;
            if((a != c && a != d) && (b != c && b != d)){
                vector<int> temp;
                temp.push_back(arr[a]);
                temp.push_back(arr[b]);
                temp.push_back(arr[c]);
                temp.push_back(arr[d]);
                sort(temp.begin(), temp.end());
                os.insert(temp);
            }
        }
    }
    if(os.empty())
        cout << -1;
    for(auto it = os.begin(); it != os.end(); it++){
        vector<int> temp = *it;
        for(int i = 0; i < temp.size(); i++)
            cout << temp[i] << " ";
        cout << '$';
    }
}
