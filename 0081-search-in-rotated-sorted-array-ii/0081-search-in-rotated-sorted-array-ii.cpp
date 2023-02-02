class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int pivot = (left + right) / 2;
            if (nums[pivot] == target) {
                return true;
            } else {
                if (nums[pivot] == nums[left] && nums[pivot] == nums[right]) {
                    left++;
                    right--;
                } else if (nums[pivot] < nums[left]) {
                    if (target > nums[pivot] && target <= nums[right]) {
                        left = pivot + 1;
                    } else {
                        right = pivot - 1;
                    }
                } else {
                    if (target < nums[pivot] && target >= nums[left]) {
                        right = pivot - 1;
                    } else {
                        left = pivot + 1;
                    }
                }
            }
        }
        return false;
    }
};