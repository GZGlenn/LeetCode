#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		if (k == 0) return;
		else {
			k = k % n;
			rotate(nums, 0, n - k - 1);
			rotate(nums, n - k, n - 1);
			rotate(nums, 0, n - 1);
		}
	}

	void rotate(vector<int>& nums, int start, int end) {
		while (start < end) {
			swap(nums[start++], nums[end--]);
		}
	}
};