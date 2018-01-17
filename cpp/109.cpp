#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *sortedListToBST(ListNode *head) {
        auto v = this->listToVec(head);
        return this->helper(v, 0, v.size() - 1);
    }
    TreeNode *helper(vector<int> &v, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        auto *t = new TreeNode(v[mid]);
        t->left = helper(v, start, mid - 1);
        t->right = helper(v, mid + 1, end);
        return t;
    }

  private:
    vector<int> &listToVec(ListNode *head) {
        auto *v = new vector<int>();
        while (head) {
            v->push_back(head->val);
            head = head->next;
        }
        return *v;
    }
};

int main() {}