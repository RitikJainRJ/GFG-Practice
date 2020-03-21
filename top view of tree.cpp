void topView(Node *root){
    queue<Node*> q;
    unordered_map<Node*, int> um;
    map<int, int> result;
    unordered_set<int> us;

    q.push(root);
    um[root] = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node *temp = q.front();
            q.pop();
            int dis = um[temp];
            if(us.find(dis) == us.end()){
                result[dis] = temp->data;
                us.insert(dis);
            }
            if(temp->left){
                q.push(temp->left);
                um[temp->left] = dis - 1;
            }
            if(temp->right){
                q.push(temp->right);
                um[temp->right] = dis + 1;
            }
        }
    }
    for(auto it = result.begin(); it != result.end(); it++)
        cout << it->second << " ";
}
