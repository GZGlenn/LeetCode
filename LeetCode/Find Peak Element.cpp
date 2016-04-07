#include <vector>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return 0;
		else if (nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;

		if (nums[0] > nums[1]) return 0;
		if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

		int index = 1;
		while (index < nums.size() && nums[index - 1] >= nums[index]) index++;


		for (; index < nums.size() - 1 && nums[index] <= nums[index + 1]; index++);

		if (index == nums.size() - 1) return 0;
		else return index;
	}
};