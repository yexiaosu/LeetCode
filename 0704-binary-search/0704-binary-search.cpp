class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int i = 0;
        while (left <= right) {
            i = (right+left)/2;
            if (nums[i] == target) {
                return i;
            } else if (nums[i] < target) {
                left = i+1;
            } else {
                right = i-1;
            }
        }
        return -1;
    }
};