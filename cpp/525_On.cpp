class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        auto sums = vector<int>(nums.size()*2+1,-2);
        sums[0+nums.size()] = -1;
        if(sums.size()<2)
            return 0;
        for(auto &i: nums){
            if(i==0)
                i=-1;
        }
        int max = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum+=nums[i];
            int pos = sum+nums.size();
            if(sums[pos]==-2){
                sums[pos] = i;
            }else if(max<i-sums[pos]){
                max = i-sums[pos];
            }
        }
        return max;
    }
};

/*
原理：
使用一个2n+1长度的数组来存放对应的和第一次出现的地方，并初始化成-2，和为0的出现位置是-1.
对整个数组进行一次遍历，将所有的0变为-1. （这样才能出现0和1）
如果已经出现过的和再次出现，那么证明这两个位置之间0和1出现次数一样。并取最大的那个距离。
*/