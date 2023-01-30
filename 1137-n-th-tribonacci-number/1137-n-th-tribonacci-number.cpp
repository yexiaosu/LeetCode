class Solution {
public:
    int tribonacci(int n) {
        int t0 = 0, t1 = 1, t2 = 1;
        switch (n) {
            case 0:
                return t0;
            case 1:
                return t1;
            case 2:
                return t2;
            default:
                break;
        }
        for (int i = 3; i <= n; i++) {
            int tmp = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = tmp;
        }
        return t2;
    }
};