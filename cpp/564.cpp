#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
class Solution {
  public:
    string nearestPalindromic(string n) {
        long len = n.size();
        if (n == "9") {
            return "8";
        }
        if (n == "10") {
            return "9";
        }
        if (n == "11") {
            return "9";
        }
        if (is999(n)) {
            return "1" + string(len - 1, '0') + "1";
        }
        long diff;
        if (len % 2 == 0 && n[len / 2] == '0' && n[len / 2 - 1] == '0') {
            diff = pow(10, len / 2 - 1);
        } else {
            diff = pow(10, len / 2);
        }
        long origin = stol(n);
        auto z = getPalin(n, 0);
        auto p = getPalin(n, diff);
        auto neg = getPalin(n, -diff);
        cout << z << " " << p << " " << neg << endl;
        long dis1 = abs(stol(z) - origin);
        long dis2 = abs(stol(p) - origin);
        long dis3 = abs(stol(neg) - origin);
        if (dis3 <= dis1 || dis1 == 0) {
            if (dis3 <= dis2) {
                return neg;
            } else {
                return p;
            }
        } else {
            if (dis1 <= dis2) {
                return z;
            } else {
                return p;
            }
        }
    }

  private:
    bool is999(string n) {
        for (auto i : n) {
            if (i != '9') {
                return false;
            }
        }
        return true;
    }
    string getPalin(string n, long diff) {
        long origin = stol(n);
        long changed = origin + diff;
        n = to_string(changed);
        long len = n.size();
        string s(n.begin(), n.begin() + len / 2);
        string s_r(s);
        reverse(s_r.begin(), s_r.end());
        if (len % 2 == 0) {
            return s + s_r;
        } else {
            string center = string(1, n[len / 2]);
            return s + center + s_r;
        }
    }
};

int main() {
    Solution s;
    cout << s.nearestPalindromic("10000");
}