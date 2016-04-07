#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty()) return 0;

		int minLen = INT_MAX;
		int i = 0, j = 0, sum = 0;
		while (i <= j && j < nums.size()) {
			sum += nums[j];
			while (i <= j && sum >= s) {
				minLen = minLen >(j - i + 1) ? (j - i + 1) : minLen;
				sum -= nums[i];
				i++;
			}
			j++;
		}
		return minLen == INT_MAX ? 0 : minLen;
	}
};