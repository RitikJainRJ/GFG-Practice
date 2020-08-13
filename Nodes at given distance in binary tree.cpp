class solver{
private:
    void preorder(Node *root, Node *&t, int target, unordered_map<Node*, Node*> &um){
        if(!root)   return;
        else{
            if(root->data == target)
                t = root;
            if(root->left)
                um[root->left] = root;
            if(root->right)
                um[root->right] = root;
            preorder(root->left, t, target, um);
            preorder(root->right, t, target, um);
        }
    }

public:
    vector<int> KDistanceNodes(Node* root, int target, int k){
        unordered_map<Node*, Node*> um;
        unordered_set<Node*> visited;
        vector<int> res;
        queue<Node*> q;
        Node *t = nullptr;

        um[root] = nullptr;
        preorder(root, t, target, um);
        visited.insert(nullptr);
        visited.insert(t);
        q.push(t);
        while(!q.empty()){
            int size =  q.size();
            vector<int> ans;

            while(size--){
                Node *f = q.front();
                q.pop();

                ans.push_back(f->data);
                if(visited.find(f->left) == visited.end())
                    visited.insert(f->left), q.push(f->left);
                if(visited.find(f->right) == visited.end())
                    visited.insert(f->right), q.push(f->right);
                if(visited.find(um[f]) == visited.end())
                    visited.insert(um[f]), q.push(um[f]);
            }
            if(k == 0){
                res = ans;
                break;
            }
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
