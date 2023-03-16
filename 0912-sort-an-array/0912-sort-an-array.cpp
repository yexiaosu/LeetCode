class Solution {
    void merge(vector<int>& nums, vector<int>& left, vector<int>& right) {
        if (left.back() <= right.front()) {
            int k = 0;
            for (int i = 0; i < left.size(); i++) {
                nums[k] = left[i];
                k++;
            }
            for (int i = 0; i < right.size(); i++) {
                nums[k] = right[i];
                k++;
            }
        }
        int i = 0, j = 0, k = 0;
        while (i != left.size() && j != right.size()) {
            if (right[j] >= left[i]) {
                nums[k] = left[i];
                i++;
            } else {
                nums[k] = right[j];
                j++;
            }
            k++;
        }
        if ((left.begin() + i) == left.end()) {
            for (j = j; j < right.size(); j++) {
                nums[k] = right[j];
                k++;
            }
        } else {
            for (i = i; i < left.size(); i++) {
                nums[k] = left[i];
                k++;
            }
        }
    }
    
    void mergeSort(vector<int>& nums) {
        if (nums.back() >= nums.front() && nums.size() <= 2) {
            return;
        }
        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());
        mergeSort(left);
        mergeSort(right);
        merge(nums, left, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }
};