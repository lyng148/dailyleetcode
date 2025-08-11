class Solution {
public:
   string mergeAlternately(string word1, string word2) {
        string res = "";
        int i1 = 0, i2 = 0;
        int totalLength = word1.length() + word2.length();

        for (int i = 0; i < totalLength; i++) {
            if (i % 2 == 0 && i1 < word1.length()) {
                res.push_back(word1[i1++]);
            }
            else if (i2 < word2.length()) {
                res.push_back(word2[i2++]);
            }
        }

        // Append remaining characters (if any)
        while (i1 < word1.length()) res.push_back(word1[i1++]);
        while (i2 < word2.length()) res.push_back(word2[i2++]);

        return res;
    }
};