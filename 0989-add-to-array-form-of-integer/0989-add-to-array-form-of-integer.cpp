class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int remain = k;
        for (int i = num.size()-1; i >= 0; i--) {
            int tmp = num[i] + remain;
            ans.push_back(tmp % 10);
            remain = tmp / 10;
        }
        while (remain != 0) {
            int tmp = remain;
            ans.push_back(tmp % 10);
            remain = tmp / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};