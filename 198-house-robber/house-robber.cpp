class Solution {
public:
    int rob(vector<int>& nums) {
        int prevRob = 0;
        int currRob = 0;
        for (int house : nums) {
            int tmp = currRob;
            currRob = max(prevRob + house, currRob);
            prevRob = tmp;
        }
        return currRob;
    }
};