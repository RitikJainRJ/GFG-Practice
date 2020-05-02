void _pathSum(TreeNode *root, int sum, int curr, int &res, vector<int> &vec){
    if(!root)
        return;
    else{
        vec.push_back(root->val);
        curr += root->val;
        if(curr == sum)
            res++;
        int temp = curr;
        for(int i = 0; i < vec.size() - 1; i++){
            temp = temp - vec[i];
            if(temp == sum)
                res++;
        }
        _pathSum(root->left, sum, curr, res, vec);
        _pathSum(root->right, sum, curr, res, vec);
        vec.pop_back();
    }
}

int pathSum(TreeNode* root, int sum) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int res = 0, curr = 0;
    vector<int> vec;

    _pathSum(root, sum, curr, res, vec);
    return res;
}
