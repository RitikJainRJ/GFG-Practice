#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int waterJug(int m, int n, int d){
    set<pii> visited;
    queue<pii> q;
    int res = 0, temp;

    visited.insert({0, 0});
    q.push({0, 0});
    while(!q.empty()){
        int size = q.size();

        while(size--){
            pii f = q.front();
            q.pop();

            if(f.first == d || f.second == d)
                return res;
            if(visited.find({0, f.second}) == visited.end())
                visited.insert({0, f.second}), q.push({0, f.second});
            if(visited.find({f.first, 0}) == visited.end())
                visited.insert({f.first, 0}), q.push({f.first, 0});
            if(visited.find({m, f.second}) == visited.end())
                visited.insert({m, f.second}), q.push({m, f.second});
            if(visited.find({f.first, n}) == visited.end())
                visited.insert({f.first, n}), q.push({f.first, n});
            temp = min(f.first, n - f.second);
            if(visited.find({f.first - temp, f.second + temp}) == visited.end())
                visited.insert({f.first - temp, f.second + temp}), q.push({f.first - temp, f.second + temp});
            temp = min(m - f.first, f.second);
            if(visited.find({f.first + temp, f.second - temp}) == visited.end())
                visited.insert({f.first + temp, f.second - temp}), q.push({f.first + temp, f.second - temp});
        }
        res++;
    }
    return -1;
}

int main(){
	int t, m, n, d;

	cin >> t;
	while(t--){
	    cin >> m >> n >> d;
	    cout << waterJug(m, n, d) << endl;
	}
	return 0;
}
