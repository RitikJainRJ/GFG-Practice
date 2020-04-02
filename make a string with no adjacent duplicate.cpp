#include<bits/stdc++.h>
using namespace std;

struct Node{
    char c;
    int f;

    Node(char ch, int fre) : c{ch}, f{fre} {}
};

class myComp{
public:
    int operator()(const Node &a, const Node &b){
        return a.f < b.f;
    }
};

string noAdj(string);

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        cout << noAdj(str) << endl;
    }
    return 0;
}

string noAdj(string str){
    string res;
    priority_queue<Node, vector<Node>, myComp> pq;
    unordered_map<char, int> um;

    for(int i = 0; i < str.length(); i++){
        um[str[i]]++;
    }
    for(auto it = um.begin(); it != um.end(); it++)
        pq.push(Node(it->first, it->second));
    while(!pq.empty()){
        if(pq.size() == 1 && pq.top().f > 1){
            return "Not possible";
        }
        Node temp1 = pq.top();
        pq.pop();
        if(!pq.empty()){
            Node temp2 = pq.top();
            pq.pop();
            res = res + temp1.c + temp2.c;
            (temp2.f)--;
            if(temp2.f > 0)
                pq.push(temp2);
        }
        else
            res = res + temp1.c;
        (temp1.f)--;
        if(temp1.f > 0)
        pq.push(temp1);
    }
    return res;
}
