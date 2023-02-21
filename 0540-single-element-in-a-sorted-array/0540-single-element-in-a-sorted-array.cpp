class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int p = (l + r) / 2;
            bool higherEven = ((r - p) % 2 == 0);
            if (nums[p] == nums[p + 1]) {
                higherEven ? (l = p + 2) : (r = p - 1);
            } else if (nums[p] == nums[p - 1]) {
                higherEven ? (r = p - 2) : (l = p + 1);
            } else {
                return nums[p];
            }
        }
        return nums[l];
    }
};