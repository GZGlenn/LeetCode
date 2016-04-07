#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		if (nums.empty()) return vector<int>();

		int myXor = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			myXor ^= nums[i];
		}

		int lowcase = myXor & -myXor;

		vector<int> vec1, vec2;

		for (int i = 0; i < nums.size(); i++) {
			if (lowcase & nums[i]) vec1.push_back(nums[i]);
			else vec2.push_back(nums[i]);
		}

		int data1 = searchSingleData(vec1);
		int data2 = searchSingleData(vec2);

		vector<int> result;
		result.push_back(data1); result.push_back(data2);

		return result;
	}

	int searchSingleData(vector<int> &vec) {
		int data = vec[0];
		for (int i = 1; i < vec.size(); i++) {
			data ^= vec[i];
		}
		return data;
	}
};