
// DP Method
// Time Complexity: O(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {       
        int sum = 0;
        int ans = nums[0];
        
        for(int i=0; i<nums.size(); i++){
            if(sum >= 0)        // if sum is integer, it's able to add negative value.
                sum += nums[i];
            else
                sum = nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
