#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.empty()) return 0;
		
		sort(nums.begin(),nums.end());

		int diff = INT_MAX, sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			int left = i + 1, right = nums.size();
			while (left < right) {
				sum = nums[left] + nums[right] + nums[i];
				
				if (sum > target) right--;
				else if (sum < target) left++;
				else return sum;

				if (abs(sum - target) < abs(diff))
					diff = sum - target;
			}
		}

		return diff + target;
	}
};