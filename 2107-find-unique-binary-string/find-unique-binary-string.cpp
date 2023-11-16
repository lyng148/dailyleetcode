struct Solution {
    string findDifferentBinaryString(vector<string>& ns) {
        return accumulate(begin(ns), end(ns), string{}, [i=0](auto&& s, auto& n) mutable { return s += "10"[n[i++]-'0']; });
    }
};