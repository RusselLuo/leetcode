#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;
int _plus(int x, int y) { return x + y; }
int _minus(int x, int y) { return x - y; }
int _times(int x, int y) { return x * y; }
int _divide(int x, int y) { return x / y; }
typedef int (*f)(int, int);
class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        unordered_map<string, f> m;
        m["+"] = &_plus;
        m["-"] = &_minus;
        m["*"] = &_times;
        m["/"] = &_divide;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (m.find(tokens[i]) == m.end())
            {
                s.push(stoi(tokens[i]));
            } //not a symbol
            else
            {
                int o2 = s.top();
                s.pop();
                int o1 = s.top();
                s.pop();
                f g = m[tokens[i]];
                int result = g(o1, o2);
                s.push(result);
            }
        }
        return s.top();
    }
};

int main()
{
    vector<string> v = {"2", "1", "+", "3", "*"};
    Solution s;
    cout << s.evalRPN(v);
}