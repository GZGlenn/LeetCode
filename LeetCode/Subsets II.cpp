#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.empty()) return vector<vector<int>>();

		sort(nums.begin(), nums.end());

		vector<bool> isUsed(nums.size(), false);

		vector<vector<int>> result;
		result.push_back(vector<int>());
		dfs(nums, isUsed, result, vector<int>(), 0);
		return result;
	}

	void dfs(vector<int> &nums, vector<bool> &isUsed, vector<vector<int>> &result,
		vector<int> curr, int start) {
		if (start >= nums.size()) return;

		for (int i = start; i < nums.size(); i++) {
			if (i != 0 && nums[i] == nums[i - 1] && !isUsed[i - 1]) continue;
			curr.push_back(nums[i]);
			isUsed[i] = true;
			result.push_back(curr);
			dfs(nums, isUsed, result, curr, i + 1);
			curr.pop_back();
			isUsed[i] = false;
			
		}
	}
};