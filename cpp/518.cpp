#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int change(int amount, vector<int> &coins) {
		int N = coins.size();
		if (amount == 0)return 1;
		if (N == 0)return 0;
		int T = amount + 1;
		vector<vector<int>> mem(N, vector<int>(T, 0));
		for (int t = 0; t < T; t++)
		{
			for (int n = 0; n < N; n++)
			{
				if (t==0)
				{
					mem[n][t] = 1;
				}
				else if (n==0)
				{
					if (coins[n] <= t) {
						mem[n][t] = mem[n][t-coins[0]];
					}
	
				}
				else if (coins[n] > t)
				{
					mem[n][t] = mem[n - 1][t];
				}
				else
				{
					mem[n][t] =  mem[n - 1][t]+mem[n][t-coins[n]];
				}
			}
		}
		return mem[N - 1][amount];
	}
};

int main() {
	Solution s;
	vector<int> v = { 1, 2, 5 };
	return s.change(5, v);
}