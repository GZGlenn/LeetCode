#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty()) return vector<vector<int>>(1, vector<int>());

		sort(nums.begin(),nums.end());

		int N = nums.size();
		vector<vector<int>> result;
		result.push_back(vector<int>());
		dfs(nums, result, vector<int>(), 0);
		return result;
	}

	void dfs(vector<int> &nums, vector<vector<int>> &result,
		vector<int> curr, int start) {
		if (start == nums.size()) return;

		for (int i = start; i < nums.size(); i++) {
			curr.push_back(nums[i]);
			result.push_back(curr);
			dfs(nums, result, curr, i+1);
			curr.pop_back();
		}
	}
};