struct Solution {
    string longestPalindrome(string_view s) {
        auto extend = [=](int i, int evenLen, int d = 1) {
            for (; 0 <= i - d && i + d - evenLen < s.size(); ++d)
                if (s[i - d] != s[i + d - evenLen]) break;
            return s.substr(i - d + 1, 2 * d - 1 - evenLen);
        };
        string_view res = s.substr(0, 1);
        for (int i = 1; i < s.size(); ++i) {
            if (auto e = extend(i, 0); res.size() < e.size()) res = e;
            if (auto e = extend(i, 1); res.size() < e.size()) res = e;
        }
        return string{res};
    }
};