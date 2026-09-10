class Solution {
public:
    pair<int,int>dfs(TreeNode*root, int sum , int totalcnt, int &cnt ){
        if(!root) return {0,0};
        auto left=dfs(root->left, sum , totalcnt, cnt);
        auto right=dfs(root->right, sum, totalcnt, cnt);
        int totalAvg=(left.first+right.first+root->val)/(left.second+right.second+1);
        if(root->val==totalAvg) cnt++;
        return {left.first+right.first+root->val, left.second+right.second+1};

    }

    int averageOfSubtree(TreeNode* root) {
    int cnt=0;
    dfs(root, 0,0,cnt);
    return cnt;
        
    }
};