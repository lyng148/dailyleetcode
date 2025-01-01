class Solution {
public:
    int maxScore(string s) {
        int size = s.length();
        int one = 0, maxRes = 0, zero = 0;
        for (int i = 0; i < size; i ++){
            if (s[i] == '1') one++;
        }
        for (int i = 0; i < size - 1; i++){
            if (s[i] == '0'){
                zero++;
            }
            else 
                one--;
            maxRes = max(maxRes, zero + one);
        }
        return maxRes;
    }
};