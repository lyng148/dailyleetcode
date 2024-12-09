class Solution {
public:
    vector<string> _2 = {"a", "b", "c"};
    vector<string> _3 = {"d", "e", "f"};
    vector<string> _4 = {"g", "h", "i"};
    vector<string> _5 = {"j", "k", "l"};
    vector<string> _6 = {"m", "n", "o"};
    vector<string> _7 = {"p", "q", "r", "s"};
    vector<string> _8 = {"t", "u", "v"};
    vector<string> _9 = {"w", "x", "y", "z"};

    vector<string> res;
    string curr = "";

    void addRes() {
        res.push_back(curr);
    }

    void tryy(int k, string digits) {
        char currChar = digits[k];
        if (currChar != '7' && currChar != '9') {
            for (int i = 0; i < 3; i++) {
                if (currChar == '2') {
                    curr.append(_2[i]);
                } else if (currChar == '3') {
                    curr.append(_3[i]);
                } else if (currChar == '4') {
                    curr.append(_4[i]);
                } else if (currChar == '5') {
                    curr.append(_5[i]);
                } else if (currChar == '6') {
                    curr.append(_6[i]);
                } else if (currChar == '8') {
                    curr.append(_8[i]);
                }
                if (k == digits.length() - 1) {
                    addRes();
                } else
                    tryy(k + 1, digits);
                curr.pop_back();
            }
        } else {
            for (int i = 0; i < 4; i++) {
                if (currChar == '7') {
                    curr.append(_7[i]);
                } else
                    curr.append(_9[i]);
                if (k == digits.length() - 1) {
                    addRes();
                } else
                    tryy(k + 1, digits);
                curr.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        tryy(0, digits);
        return res;
    }
};
