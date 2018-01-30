#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(!envelopes.size()) return 0;
        sort(envelopes.begin(),envelopes.end());
        vector<int> N(envelopes.size());
        N[0] = 1;
        int totalMax = 1;
        for(int i = 1; i<N.size();++i){
            int max = 1;
            for(int j = 0;j<i;++j){
                int temp = 1;
                if(envelopes[i].first>envelopes[j].first&&envelopes[i].second>envelopes[j].second){
                    temp = N[j]+1;
                }
                max = temp>max?temp:max;
            }
            N[i] = max;
            totalMax = totalMax<max? max:totalMax;
        }
        return totalMax;
    }
};