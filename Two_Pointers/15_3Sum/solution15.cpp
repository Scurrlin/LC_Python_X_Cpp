#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) {
                    k--;
                } else if (total < 0) {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }
        
        return res;
    }
};

// Runtime1: 59ms, beats 74.02%
// Memory1: 27.46MB, beats 73.90%

// Runtime2: 65ms, beats 53.08%
// Memory2: 27.44MB, beats 73.90%

// Runtime3: 61ms, beats 66.81%
// Memory3: 27.45MB, beats 73.90%

// Runtime reduced by a factor of 10 to not skew data visualization