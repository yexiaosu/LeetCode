class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int pivot = (left + right) / 2;
            if (nums[pivot] == target) {
                return pivot;
            } else {
                if (nums[pivot] < nums[left]) {
                    if (nums[pivot] < target && target <= nums[right]) {
                        left = pivot + 1;
                    } else {
                        right = pivot - 1;
                    }
                } else {
                    if (nums[pivot] > target && target >= nums[left]) {
                        right = pivot - 1;
                    } else {
                        left = pivot + 1;
                    }
                }
            }
        }
        return -1;
    }
};