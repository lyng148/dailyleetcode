class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0;
        int map1[32] = {0};
        int map2[32] = {0};
        if (s1.length() != s2.length()){
            return false;
        }
        int length = s1.length();
        for (int i = 0; i < length; i++){
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
            if (s1[i] != s2[i])
                diff++;
        }
        if (diff > 2) return false;
        for (int i = 0; i < 32; i++){
            if (map1[i] != map2[i])
                return false;
        }
        return true;
    }
};