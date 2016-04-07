#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) return 0;

		int left = 0, right = nums.size() - 1;

		while (nums[left] >= nums[right]) {
			if (right - left <= 1) {
				return nums[right];
			}

			int mid = left + (right - left) / 2;
			if (nums[left] == nums[mid] && nums[right] == nums[mid]) {
				return lineSearchMin(nums);
			}

			if (nums[mid] >= nums[left]) left = mid;
			else if (nums[mid] <= nums[right]) right = mid;
		}

		return nums[left];
	}

	int lineSearchMin(vector<int> &nums) {
		int result = INT_MAX;
		for (int i = 0; i < nums.size(); i++) {
			if (result > nums[i]) result = nums[i];
		}
		return result;
	}
};