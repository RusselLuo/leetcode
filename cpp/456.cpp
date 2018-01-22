#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    bool find132pattern(vector<int> &nums) {
        int third = INT_MIN;
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < third)
                return true;
            else {
                // nums[i]>=third
                while (!s.empty() && nums[i] > s.top()) {
                    // make sure the element on the top of the stack is larger
                    // than third. Pop all elements smaller than current element.
                    third = s.top();
                    s.pop();
                }
            }
            //what push in the stack is always larger than current third
            s.push(nums[i]);
        }
        return false;
    }
};
/*
Stack s consists of sorted elements that larger than thrid. When current element is smaller than third element,
a 132 pattern is found. If current element is larger than or equal to
third element, pop elements in stack until all element smaller then current element are poped out.
*/