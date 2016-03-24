#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int> &num) {
		if (num.empty()) {
			return 0;
		}
		int res = 0; int length = num.size();
		if (1 == length) 
			return num[0];

		if (length >= 3) 
			num[2] = num[0] + num[2];

		for (int i = 3; i < length; i++) {
			if (num[i - 2] > num[i - 3]) num[i] += num[i - 2];
			else num[i] += num[i - 3];
		}
		return (num[length - 2] > num[length - 1]) ? num[length - 2] : num[length - 1];
	}

	//int rob(vector<int>& nums) {
	//	int result = 0;
	//	int taken = 0;
	//	int notaken = 0;

	//	for (int i = 0; i < nums.size(); i++) {
	//		taken = notaken + nums[i];
	//		notaken = result;
	//		result = max(taken, notaken);
	//	}

	//	return result;
	//}
};