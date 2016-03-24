#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> &nums) {
		this->sum = vector<int>(nums.size(),0);
		for (int i = 0; i < nums.size(); i++) {
			if (i == 0) this->sum[i] = nums[i];
			else this->sum[i] = this->sum[i - 1] + nums[i];
		}
	}

	int sumRange(int i, int j) {
		if (i == 0) return this->sum[j];
		return this->sum[j] - this->sum[i-1];
	}

private:
	vector<int> sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);