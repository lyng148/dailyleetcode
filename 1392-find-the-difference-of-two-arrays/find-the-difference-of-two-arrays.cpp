class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        unordered_set<int> res1, res2;

        for (int n : nums2)
            if (!set1.count(n)) res1.insert(n);

        for (int n : nums1)
            if (!set2.count(n)) res2.insert(n);

        vector<int> fres1(res1.begin(), res1.end());
        vector<int> fres2(res2.begin(), res2.end());

        return {fres2, fres1};
    }
};
