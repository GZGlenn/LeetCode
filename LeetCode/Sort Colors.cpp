#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.empty()) return;

		quickSort(nums, 0, nums.size() - 1);
	}

	void quickSort(vector<int>& nums, int l, int r) {
		if (l >= r) return;
		int key = nums[l];
		int left = l, right = r;
		while (l < r) {
			while (l < r && nums[r] >= key) r--;
			swap(nums[l], nums[r]);

			while (l < r && nums[l] <= key) l++;
			swap(nums[l], nums[r]);
		}
		nums[l] = key;

		quickSort(nums, left, l - 1);
		quickSort(nums, l + 1, right);
	}
};