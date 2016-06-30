#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() < 2) return false;

		unordered_map<int, bool> my_set;
		for (int i = 0; i < nums.size(); i++) {
			if (my_set.find(nums[i]) != my_set.end()) {
				return true;
			}
			my_set[nums[i]] = 1;
		}

		return false;
	}
};