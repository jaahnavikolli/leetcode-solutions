#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // prev2 represents dp[i-2], prev1 represents dp[i-1]
        int prev2 = 0;
        int prev1 = 0;

        for (int money : nums) {
            // Calculate the max if we rob this house vs skipping it
            int current = max(prev1, money + prev2);
            
            // Update pointers for the next iteration
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};