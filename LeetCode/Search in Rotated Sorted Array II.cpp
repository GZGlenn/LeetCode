#include <vector>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty()) return false;
		if (nums.size() == 1 && nums[0] != target) return false;

		int left = 0, right = nums.size() - 1;

		while (left < right) {
			if (left == right - 1) {
				if (nums[left] != target && nums[right] != target) return false;
				else return true;
			}

			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return true;

			if (nums[mid] == nums[right] && nums[mid] == nums[left]) {
				return orderSearch(nums, target, left, right);
			}

			else if (nums[mid] < target) {
				if (nums[left] <= nums[mid]) left = mid + 1;
				else if (target <= nums[right]) left = mid + 1;
				else right = mid - 1;
			}

			else {
				if (nums[right] >= nums[mid]) right = mid - 1;
				else if (target <= nums[right]) left = mid + 1;
				else right = mid - 1;
			}
		}

		return nums[left] == target;
	}

	bool orderSearch(vector<int> &nums, int target, int l, int r) {
		for (int i = l; i <= r; i++) {
			if (nums[i] == target) return true;
		}
		return false;
	}
};