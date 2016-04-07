#include <vector>

using namespace std;

// Gray Code 0 = 0, ��һ����toggle���ұߵ�bit(LSB), ����һ����toggle���ұ�
// ֵΪ ��1�� bit�����һ��bit��Ȼ���ظ�
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