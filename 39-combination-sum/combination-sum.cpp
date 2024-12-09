class Solution {
public:
    vector<vector<int>> res;
vector<int> curr;

static int comp(int a, int b){
    return a > b;
}

void addRes(){
    res.push_back(curr);
}

void tryy(vector<int> &candidates, int target){
    int size = candidates.size();
    for (int i = 0; i < size; i++){
        if (target >= candidates[i]){
            if (!curr.empty()){
                if (candidates[i] < curr.back())
                    continue;
            }
            curr.push_back(candidates[i]);
            target -= candidates[i];
            if (target == 0){
                addRes();
            }
            else
                tryy(candidates, target);
            curr.pop_back();
            target += candidates[i];
        }
    }    
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end(), comp);
    tryy(candidates, target);
    return res;
}
};