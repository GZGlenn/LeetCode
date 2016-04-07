#include <vector>

using namespace std;

// Gray Code 0 = 0, 下一项是toggle最右边的bit(LSB), 再下一项是toggle最右边
// 值为 “1” bit的左边一个bit。然后重复
class Solution {
public:
	vector<int> grayCode(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int size = 1 << n;
		vector<int> grayCodes;
		grayCodes.resize(size);

		for (int i = 0; i < size; i++){
			int gCode = i ^ i >> 1;
			grayCodes[i] = gCode;
		}

		return grayCodes;
	}
};