#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> myMap = unordered_map<int, int>();
		for (int i = 0; i < nums.size(); ++i) {
			if (myMap.find(nums[i]) != myMap.end() && i - myMap[nums[i]] <= k) return true;
			else myMap[nums[i]] = i;
		}
		return false;
	}

};