struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//基本思路，因为已知每个层都是回文的（因为对称），所以BFS后，按照1,2,4,8,16...规模一一验证回文
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        stack<int> l,r;
        leftIter(root->left,l);
        rightIter(root->right,r);
        if(l.size()!=r.size()) return false;
        while(!l.empty()){
            if(r.top()==l.top()){
                l.pop();
                r.pop();
            }else{
                return false;
            }
        }
        return true;
    }
};