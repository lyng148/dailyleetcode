class Solution {
public:
    vector<vector<int>> res;
vector<int> curr;

void addRes() {
    res.push_back(curr);
}

void tryy (int j, int n, vector<int> &nums, vector<bool> mark){
    for (int i = 0; i < n; i++) {
        if (!mark[i]){
            curr.push_back(nums[i]);
            mark[i] = true;
            if (j == nums.size() - 1){
                addRes();
            }
            else 
                tryy(j + 1, n, nums, mark);
            curr.pop_back();
            mark[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> mark (n + 1, false);
    tryy(0, n, nums, mark);
    return res;
}

};