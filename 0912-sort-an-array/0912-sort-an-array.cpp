class Solution {
    void merge(vector<int>& nums, int left, int right, int mid, vector<int> &tempArr) {
        if (nums[mid] <= nums[mid+1]) {
            return;
        }
        int start1 = left;
        int start2 = mid + 1;
        int n1 = mid - left + 1;
        int n2 = right - mid;
        for (int i = 0; i < n1; i++) {
            tempArr[start1 + i] = nums[start1 + i];
        }
        for (int i = 0; i < n2; i++) {
            tempArr[start2 + i] = nums[start2 + i];
        }
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (tempArr[start1 + i] <= tempArr[start2 + j]) {
                nums[k] = tempArr[start1 + i];
                i += 1;
            } else {
                nums[k] = tempArr[start2 + j];
                j += 1;
            }
            k += 1;
        }
        while (i < n1) {
            nums[k] = tempArr[start1 + i];
            i += 1;
            k += 1;
        }
        while (j < n2) {
            nums[k] = tempArr[start2 + j];
            j += 1;
            k += 1;
        }
    }
    
    void mergeSort(vector<int>& nums, int left, int right, vector<int> &tempArr) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid, tempArr);
        mergeSort(nums, mid+1, right, tempArr);
        merge(nums, left, right, mid, tempArr);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temporaryArray(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temporaryArray);
        return nums;
    }
};