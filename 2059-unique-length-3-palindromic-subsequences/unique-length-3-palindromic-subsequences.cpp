class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int tmp[27][2];
        for(int i = 0 ; i < 27 ; i++){
            tmp[i][0] = - 1;
            tmp[i][1] = - 1;
        }
        int res = 0;
        for(int i  = 0 ; i < s.size() ; i++){
            if(tmp[s[i] - 97][0] == -1) tmp[s[i] - 97][0] = i;
            else tmp[s[i] - 97][1] = i;
        }
        for(int i = 0 ; i < 27 ; i++){
            if(tmp[i][0] == -1 || tmp[i][1] == -1) continue;
            int a[27] = {};
            for(int j = tmp[i][0] + 1 ; j < tmp[i][1] ; j++){
                if(a[s[j] - 97] == 0){
                    res++;
                    a[s[j] - 97]++;
                }
            }
        }
        return res;
    }
};