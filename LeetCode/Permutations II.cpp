#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty()) return vector<vector<int>>();

		sort(nums.begin(), nums.end());
		
		vector<vector<int>> result;
		for (int i = 0; i < nums.size(); i++) {
			vector<int> temp(nums);
			temp.erase(temp.begin() + i);
			vector<vector<int>> tmp = permuteUnique(temp);
		}

		return result;
	}

	void dfs(vector<int> &nums, vector<vector<int>> result, vector<int> curr, int start) {

	}
};