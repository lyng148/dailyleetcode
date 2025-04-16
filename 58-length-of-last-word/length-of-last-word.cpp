class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        int res = 0;
        for (int i = length - 1; i >= 0; i--){
            if (s[i] == ' '){
                if (res != 0){
                    return res;
                }
                else continue;
            }
            else{
                res++;
                continue;
            }
        }
        return res;
    }
};