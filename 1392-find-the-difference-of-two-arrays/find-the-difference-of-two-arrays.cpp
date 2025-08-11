class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
  vector<vector<int>> res;
  set<int> set1, set2;
  set<int> res1, res2;

  for (int i = 0; i < nums1.size(); i++){
    set1.insert(nums1[i]);
  }        
  for (int i = 0; i < nums2.size(); i++){
    set2.insert(nums2[i]);
    if (!set1.count(nums2[i])) {
      res1.insert(nums2[i]);
    }
  }
  for (int i = 0; i < nums1.size(); i++){
    if (!set2.count(nums1[i])) {
      res2.insert(nums1[i]);
    }
  }
  vector<int> fres1(res1.begin(), res1.end());
  vector<int> fres2(res2.begin(), res2.end());
  res.push_back(fres2);
  res.push_back(fres1);
  return res;
}
};