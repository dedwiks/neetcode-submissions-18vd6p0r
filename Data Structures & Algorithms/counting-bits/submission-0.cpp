class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int num = 0; num <= n; num++) {
            for (int i = 0; i < 32; i++) {
                if ((1 << i) & num) {
                    res[num]++;
                }
            }
        }
        return res;
    }
};
