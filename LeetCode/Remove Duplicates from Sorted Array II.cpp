#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size(); 

		int newIndex = 0;
		int time = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[newIndex]) {
				time = 1;
				nums[++newIndex] = nums[i];
			}
			else if (time < 2) {
				time++;
				nums[++newIndex] = nums[i];
			}
		}
		return newIndex + 1;
	}
};