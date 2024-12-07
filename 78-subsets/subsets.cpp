class Solution {
public:
    vector<vector<int>> res;

// Hàm đệ quy sinh các tập hợp con
void generateSubsets(int index, vector<int> &nums, vector<int> &current) {
    if (index == nums.size()) {
        res.push_back(current); // Thêm tập hợp con hiện tại vào kết quả
        return;
    }
    // Không chọn phần tử hiện tại
    generateSubsets(index + 1, nums, current);

    // Chọn phần tử hiện tại
    current.push_back(nums[index]);
    generateSubsets(index + 1, nums, current);
    current.pop_back(); // Quay lui
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> current;
    generateSubsets(0, nums, current);
    return res;
}

};
