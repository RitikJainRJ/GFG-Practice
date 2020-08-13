#include<bits/stdc++.h>
#define N 30
using namespace std;

int bfs(int *arr){
    bool visited[N + 1] = {false};
    int res = 0;
    queue<int> q;

    visited[1] = true;
    q.push(1);
    while(!q.empty()){
        int size = q.size();

        while(size--){
            int f = q.front();
            q.pop();

            if(f == N)
                return res;
            for(int i = 1; i <= 6; i++){
                if(f + i <= N && visited[f + i] == false){
                    visited[f + i] = true;
                    if(f + i == arr[f + i])
                        q.push(f + i);
                    else{
                        visited[arr[f + i]] = true;
                        q.push(arr[f + i]);
                    }
                }
            }
        }
        res++;
    }
    return -1;
}

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    int arr[N + 1];

	    for(int i = 0; i <= N; i++)
	        arr[i] = i;
	    for(int i = 0; i < n; i++){
	        int a, b;
	        cin >> a >> b;
	        arr[a] = b;
	    }
	    cout << bfs(arr) << endl;
	}
	return 0;
}
