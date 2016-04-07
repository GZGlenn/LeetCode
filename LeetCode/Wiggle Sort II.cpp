#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		if (nums.size() < 1) return;

		sort(nums.begin(), nums.end());

		vector<int> temp(nums.size(), 0);
		int j = nums.size() - 1;
		for (int i = 1; i < nums.size(); i += 2, j--) {
			temp[i] = nums[j];
		}

		for (int i = 0; i < nums.size(); i += 2, j--) {
			temp[i] = nums[j];
		}

		nums = temp;
	}
};