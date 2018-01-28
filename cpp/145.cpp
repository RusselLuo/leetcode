#include <set>
#include <stack>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        set<TreeNode *> finished;
        stack<TreeNode *> s;
        vector<int> ret;
        if (!root)
            return ret;
        s.push(root);
        s.push(root);
        while (!s.empty()) {
            auto *curr = s.top();
            s.pop();
            if (finished.find(curr) != finished.end()) {
                ret.push_back(curr->val);
                continue;
            } else {
                finished.insert(curr);
            }
            if (curr->right) {
                s.push(curr->right);
                s.push(curr->right);
            }
            if (curr->left) {
                s.push(curr->left);
                s.push(curr->left);
            }
        }
        return ret;
    }
};