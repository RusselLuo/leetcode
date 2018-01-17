#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, bool> m;
        for (auto i : nums1) {
            m[i] = true;
        }
        vector<int> ret;
        for (auto i : nums2) {
            if (m.find(i) != m.end()) {
                ret.push_back(i);
                m.erase(i);
            }
        }
        return ret;
    }
};