class Solution {
public:
    std::vector<int> mem;
    std::vector<int> mark;

    int subMax(int i, std::vector<int>& nums) {
        if (i == 0) {
            mem[0] = nums[0];
            return mem[0];
        }

        if (mark[i] != -1) return mem[i];

        mem[i] = std::max(nums[i], subMax(i - 1, nums) + nums[i]);
        mark[i] = 1;
        return mem[i];
    }

    int maxSubArray(std::vector<int>& nums) {
        int n = nums.size();
        mem.resize(n, 0);       // Khởi tạo kích thước động
        mark.resize(n, -1);     // Đánh dấu chưa xử lý

        subMax(n - 1, nums);

        int maxx = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxx = std::max(maxx, mem[i]);
        }
        return maxx;
    }
};
