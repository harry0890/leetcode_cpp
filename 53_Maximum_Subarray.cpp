
// DP Method (return one value at least version)
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


// If problem modify returning minimize value is 0
class Solution {
public:
    int maxSubArray(vector<int>& nums) {  
        int ans = 0, sum = 0;
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
            if (sum < 0) 
                sum = 0;
            if (sum > ans) 
                ans = sum;
        }
        return ans;
    }
};


