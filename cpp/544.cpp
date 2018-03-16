#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    void update_wall(vector<int>& len, vector<int>& bidx, vector<vector<int>>& wall){
        for(size_t i = 0; i < bidx.size(); ++i){
            if(len[i]==0){
                len[i] = wall[i][bidx[i]];
                bidx[i]++;
            }
        }
    }
    
    int move_line(vector<int>& len){
        int min = INT_MAX;
        for(auto i:len){
            if(min>i){
                min = i;
            }
        }
        for(auto &i:len){
            i-=min;
        }
        return min;
    }
    
    int leastBricks(vector<vector<int>>& wall) {
        int height = wall.size();
        int wall_len = 0;
        int min_cross = height;
        vector<int> right_len(height);
        vector<int> bidx(height);
        update_wall(right_len, bidx, wall);
        for(auto i: wall[0]){
            wall_len+=i;
        }
        int curr_pos = 0;
        while(true){
            int curr_cross = height;
            int step = move_line(right_len);
            for(int h = 0; h < height; ++h){
                if(right_len[h]==0){
                    curr_cross--;
                }
            }
            curr_pos+=step;
            if(curr_pos==wall_len)
                break;
            if(curr_cross<min_cross)
                min_cross=curr_cross;
            update_wall(right_len, bidx, wall);
        }
        return min_cross;
    }
};
