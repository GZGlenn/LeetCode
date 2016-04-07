#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty()) return false;

		int step = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (step > 0) {
				step--;
				step = step > nums[i] ? step : nums[i];
//				if (step >= nums.size() - i) return true;
			}
			else return false;
		}
		return true;
	}
};