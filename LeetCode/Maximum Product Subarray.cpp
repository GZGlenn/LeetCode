#include <vector>
#include <algorithm>

using namespace std;

// 动态规划题最核心的步骤就是要写出其状态转移方程
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];

		int local_max = nums[0];
		int local_min = nums[0];
		int global_val = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			int temp = local_max;
			local_max = max(max(local_max * nums[i], nums[i]), local_min * nums[i]);
			local_min = min(min(local_min * nums[i], nums[i]), temp * nums[i]);
			global_val = max(global_val, local_max);
		}
		return global_val;
	}
};