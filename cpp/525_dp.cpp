class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    auto mem =
        vector<vector<bool>>(nums.size(), vector<bool>(nums.size(), true));
    // init memory to 0
    // for every i=j
    // dp
    int longest = 0;
    for (int i = 0; i < nums.size(); ++i) {
      mem[i][i] = false;
    }
    for (int dis = 1; dis < nums.size(); ++dis) {
      for (int j = 0; j < nums.size() - dis; j++) {
        int i = j + dis;
        bool valid = false;
        for (int k = j; k < i; ++k) {
          valid = valid || (mem[j][k] && mem[k + 1][i]);
        }
        int temp_len = 0;
        if (valid) temp_len = i - j + 1;
        if (nums[i] != nums[j] && mem[j + 1][i - 1]) {
          valid = true;
          temp_len = i - j + 1;
        }
        longest = max(longest, temp_len);
        mem[j][i] = valid;
      }
    }
    return longest;
  }
};