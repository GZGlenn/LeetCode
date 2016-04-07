#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;

		int left = 0, right = nums.size() - 1;
		while (left < right) {
			if (left == right - 1) {
				if (nums[left] == target) return left;
				else if (nums[right] == target) return right;
				else return -1;
			}

			int mid = left + (right - left) / 2;
			
			if (nums[mid] == target) return mid;
			else if (nums[left] <= nums[mid]) {
				if (nums[left] <= target && target < nums[mid]) {
					right = mid - 1;
				} 
				else {
					left = mid + 1;
				}
			}
			else {
				if (nums[mid] < target && target <= nums[right]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}
		if (nums[left] == target) return left;
		else return -1;
	}
};

class Solution1 {
public:
	int search(vector<int>& nums, int target) {
		// 初始问题，寻找[0, size -1]中的最小值
		int l = 0, r = nums.size() - 1;
		// 不断重复来缩小问题规模
		while (l < r) {
			// 取中点，分情况讨论
			int m = (l + r) / 2;
			// 情况1
			if (nums[l] < nums[r]) {
				r = l;
			}
			else {
				// 情况2.1
				if (nums[m] >= nums[l]) {
					l = m + 1;
				}
				// 情况2.2
				else {
					r = m;
				}
			}
		}
		// 将数组复位
		int j = l;
		vector<int> ordered;
		for (int i = 0; i < nums.size(); i++) ordered.push_back(nums[(l + i) % nums.size()]);
		// 二分查找target，记得还原为原本的坐标
		l = 0, r = nums.size() - 1;
		while (l < r) {
			int m = (l + r) / 2;
			if (ordered[m] == target) return (m + j) % nums.size();;
			if (ordered[m] > target) r = m - 1;
			if (ordered[m] < target) l = m + 1;
		}
		// 判断答案
		if (l == r && ordered[l] == target) return (l + j) % nums.size();
		return -1;
	}
};