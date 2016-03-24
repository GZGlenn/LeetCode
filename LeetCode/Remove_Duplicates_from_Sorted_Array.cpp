#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int newIndex = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[newIndex]) {
				nums[++newIndex] = nums[i];
			}
		}
		return newIndex + 1;
	}
};