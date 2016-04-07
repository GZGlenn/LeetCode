#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.empty()) return 0;

		int bitmap[32] = {0};
		int res = 0;

		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < nums.size(); j++) {
				bitmap[i] += (nums[j] >> i) & 1;
			}
			res |= (bitmap[i] % 3) << i;
		}

		return res;
	}
};