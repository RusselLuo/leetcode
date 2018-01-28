#include <vector>
#include <climits>
using namespace std;


class Solution {
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int begin = 0, end = 0;
        int min = INT_MAX;
        int sum = nums[0];
        if (sum >= s)
            return 1;
        while (end != nums.size()) {
            if (sum < s) {
                end++;
                sum += nums[end];
                if (sum >= s && end - begin + 1 < min) {
                    min = end - begin + 1;
                }
            } else {
                sum -= nums[begin];
                begin++;
                if (sum >= s && end - begin + 1 < min) {
                    min = end - begin + 1;
                    if (min == 1)
                        return 1;
                }
            }
        }
        return min == INT_MAX ? 0 : min;
    }
};