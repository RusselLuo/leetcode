#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> allSplit(string prefix, string& s, int pos, int step) {
    if (step == 4) {
      if (pos == s.size()) {
        return vector<string>{prefix};
      } else {
        return vector<string>();
      }
    } else {
      vector<string> ss;
      for (int i = 1; i < 4; ++i) {
        if (pos + i <= s.size()) {
          string nextRange(s.begin() + pos, s.begin() + pos + i);
          int parsed = stoi(nextRange);
          if (parsed <= 255 &&
              (parsed >= pow(10, i - 1) || (parsed == 0 && i == 1))) {
            string next_prefix;
            if (prefix.size() != 0)
              next_prefix = prefix + "." + nextRange;
            else
              next_prefix = prefix + nextRange;
            auto split = allSplit(next_prefix, s, pos + i, step + 1);
            ss.insert(ss.end(), split.begin(), split.end());
          }
        }
      }
      return ss;
    }
  }
  vector<string> restoreIpAddresses(string s) { return allSplit("", s, 0, 0); }
};