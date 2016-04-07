#include <vector>
#include <algorithm>

using namespace std;

// 最大子串和问题（Maximum Subarray）
// 把数组分割成所有和都是负的子串，最大子串必定是其中某一个的前缀
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];

		int sum = 0;
		int maxsum = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if (sum > maxsum) maxsum = sum;
			if (sum < 0) sum = 0;
		}
		return maxsum;
	}
};

class Solution1 {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];

		int result = INT_MIN;
		int left = 0, right = 0;
		int curSum = 0;

		while (left <= right && right < nums.size()) {
			curSum += nums[right];
			if (result < curSum) result = curSum;
			if (curSum < 0) {
				curSum = 0;
				left = right + 1;
			}
			right++;
		}
		return result;
	}
};