class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1, curr = 0;
        while (curr <= r) {
            if (nums[curr] == 2) {
                swap(nums[curr], nums[r]);
                r--;
            } else if (nums[curr] == 0) {
                swap(nums[curr], nums[l]);
                l++;
                curr++;
            } else {
                curr++;
            }
        }
    }
};