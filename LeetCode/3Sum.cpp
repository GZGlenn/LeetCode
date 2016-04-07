#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.empty()) return vector<vector<int>>();

		sort(nums.begin(), nums.end());

		vector<vector<int>> result = vector<vector<int>>();
		for (int i = 0; i < nums.size() - 1; i++) {
			if (i != 0 && nums[i] == nums[i - 1]) continue;
			int left = i + 1, right = nums.size() - 1;
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					vector<int> temp = vector<int>();
					temp.push_back(nums[i]);
					temp.push_back(nums[left]);
					temp.push_back(nums[right]);
					result.push_back(temp);
					left++;
					while (left < right && nums[left] == nums[left - 1]) left++;

					right--;
					while (left < right && nums[right] == nums[right + 1]) right--;
				}
				else if (sum > 0) right--;
				else left++;
			}
		}
		return result;
	}
};