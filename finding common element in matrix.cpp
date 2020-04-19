#include<bits/stdc++.h>
using namespace std;

void commonEle(int[], int);
vector<int> intersection(vector<int>&, vector<int>&);

int main(){
	int t, arr[3];

	cin >> t;
	while(t--){
	    for(int i = 0; i < 3; i++)
	        cin >> arr[i];
	    commonEle(arr, 3);
	    cout << endl;
	}
	return 0;
}

void commonEle(int arr[], int n){
    vector<vector<int>> mat;

    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < arr[i]; j++){
            int t;
            cin >> t;
            temp.push_back(t);
        }
        mat.push_back(temp);
        temp.clear();
    }
    vector<int> res = mat[0];
    for(int i = 1; i < n; i++)
        res = intersection(res, mat[i]);
    vector<int>::iterator itr = unique(res.begin(), res.end());
    for(auto it = res.begin(); it != itr; it++)
        cout << *it << " ";
    if(res.size() == 0)
        cout << -1 << " ";
}

vector<int> intersection(vector<int> &A, vector<int> &B){
    int i = 0, j = 0;
    vector<int> res;

    while(i < A.size() && j < B.size()){
        if(A[i] < B[j])
            i++;
        else if(A[i] > B[j])
            j++;
        else{
            res.push_back(A[i]);
            i++;
            j++;
        }
    }
    return res;
}
