#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
template <typename T> class TreeNode {
  public:
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T x, TreeNode *l = nullptr, TreeNode *r = nullptr)
        : val(x), left(l), right(r) {}
};

template <typename T> class Solution {};
// base template

template <> class Solution<int> {
  public:
    bool findTarget(TreeNode<int> *root, int k) {
        vector<int> treeVec;
        buildVec(root, k, treeVec);
        auto start = treeVec.begin();
        auto end = treeVec.end() - 1;
        while (start != end) {
            // cout << *start << " " << *end << endl;
            if (*start + *end == k) {
                return true;
            } else if (*start + *end < k) {
                start++;
            } else {
                end--;
            }
        }
        return false;
    }

  private:
    void buildVec(TreeNode<int> *root, int k, vector<int> &v) {
        if (root) {
            buildVec(root->left, k, v);
            v.push_back(root->val);
            buildVec(root->right, k, v);
        }
    }
};

int main() {
    Solution<int> s;
    auto node = new TreeNode<int>(
        5, new TreeNode<int>(3, new TreeNode<int>(2), new TreeNode<int>(4)),
        new TreeNode<int>(6, nullptr, new TreeNode<int>(7)));
    // simple testcase
    cout << s.findTarget(node, 28) << endl;
}