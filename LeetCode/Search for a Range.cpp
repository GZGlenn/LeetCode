#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return vector<int>();

		int left = getPos(nums, target, 0);
		if (left == -1) return vector<int>(2, -1);
		
		int right = getPos(nums, target, 1);

		vector<int> result(2);
		result[0] = left; result[1] = right;
		return result;
	}

	int getPos(vector<int> &nums, int target, int isRight) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				if (isRight && (mid == nums.size() - 1 || nums[mid + 1] != target)) return mid;
				else if (isRight) left = mid + 1;
				else if (!isRight && (mid == 0 || nums[mid - 1] != target)) return mid;
				else if (!isRight) right = mid - 1;
			}
			else if (nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}

		return -1;
	}
};