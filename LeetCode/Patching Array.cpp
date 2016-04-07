#include <vector>

using namespace std;

class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		int cnt = 0, i = 0;
		for (long known_sum = 1; known_sum <= n;) {
			if (i < nums.size() && nums[i] <= known_sum) {
				known_sum += nums[i++];
			}
			else {
				known_sum <<= 1;
				cnt++;
			}
		}
		return cnt;
	}
};