class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> finalRes;
        vector<int> newNums;
        for (int num : nums){
            newNums.push_back(num);
        }
        int size = newNums.size();
        sort(newNums.begin(), newNums.end());
        for (int i = 0; i < size; i++){
            vector<int> currRes;
            int target = -newNums[i];
            int left = i + 1;
            int right = size - 1;
            while (left < right) { 
                if (newNums[left] + newNums[right] == target) { 
                    currRes.push_back(newNums[i]);
                    currRes.push_back(newNums[left]);
                    currRes.push_back(newNums[right]);
                    res.insert(currRes);
                    currRes.clear();
                    left++;
                    right--;
                }
                else if (newNums[left] + newNums[right] > target){
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        for (vector<int> vec : res) { 
            finalRes.push_back(vec);
        }
        return finalRes;
    }
};