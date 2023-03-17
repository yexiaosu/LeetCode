class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0, max_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr_sum += nums[i];
            max_sum = i == 0 ? curr_sum : max(max_sum, curr_sum);
            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }
        return max_sum;
    }
};