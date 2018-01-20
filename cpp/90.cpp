#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        // first sort nums to avoid different representations of a same set
        findAllSubset(nums, 0, {});
        return powerset;
    }
    void findAllSubset(const vector<int> &nums, int curr, vector<int> sub) {
        if (curr == nums.size()) {
            string s(sub.begin(), sub.end());
            if (sset.find(s) == sset.end()) {
                sset.insert(move(s));
                powerset.push_back(move(sub));
            }
        } else {
            findAllSubset(nums, curr + 1, sub);
            sub.push_back(nums[curr]);
            findAllSubset(nums, curr + 1, sub);
        }
    }

  private:
    unordered_set<string> sset;
    vector<vector<int>> powerset;
};

int main() {
    Solution s;
    vector<int> v{1, 2, 2};
    s.subsetsWithDup(v);
}