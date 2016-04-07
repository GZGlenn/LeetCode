#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return 1;

		vector<int> result(1, nums[0]);

		for (int i = 1; i < nums.size(); i++) {
			if (result[result.size() - 1] < nums[i]) {
				result.push_back(nums[i]);
			}
			else {
				int index = searchFirstBigIndex(result, nums[i]);
				result[index] = nums[i];
			}
		}
		return result.size();
	}

	int searchFirstBigIndex(vector<int> &result, int target) {
		int left = 0;
		int right = result.size() - 1;
		int mid = left;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (result[mid] == target) return mid;
			else if (result[mid] < target) left = mid + 1;
			else if (result[mid] > target) right = mid - 1;
		}

		return left;
	}
};



// dp[i] 从0-i的最大递增子序列
class Solution1 {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return 1;

		int maxLen = 1;
		vector<int> dp(nums.size(), 1);

		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					maxLen = max(maxLen, dp[i]);
				}
			}
		}
		
		return maxLen;
	}
};