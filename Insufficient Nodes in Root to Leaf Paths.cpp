class Solution {
public:
    TreeNode* sufficientSubset(TreeNode *root, int limit) {
        if(root == nullptr)
            return nullptr;
        if(!root->left && !root->right){
            limit = limit - root->val;
            if(limit <= 0)
                return root;
            else
                return nullptr;
        }
        else{
            root->left = sufficientSubset(root->left, limit - root->val);
            root->right = sufficientSubset(root->right, limit - root->val);
            if(!root->left && !root->right)
                return nullptr;
            else
                return root;
        }
    }
};
