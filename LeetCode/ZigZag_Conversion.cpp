#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		// IMPORTANT: Please reset any member data you declared, as  
		// the same Solution instance will be reused for each test case.    

		if (nRows <= 1 || s.length() == 0)
			return s;

		string res = "";
		int len = s.length();
		for (int i = 0; i < len && i < nRows; ++i) {
			int indx = i;
			res += s[indx];

			for (int k = 1; indx < len; ++k) {
				//��һ�л����һ�У�ʹ�ù�ʽ1��  
				if (i == 0 || i == nRows - 1) indx += 2 * nRows - 2;

				//�м��У��ж���ż��ʹ�ù�ʽ2��3  
				else {
					if (k & 0x1)  indx += 2 * (nRows - 1 - i);  //����λ
					else indx += 2 * i;
				}

				//�ж�indx�Ϸ���  
				if (indx < len) res += s[indx];
			}
		}
		return res;
	}
};


//class Solution {
//public:
//	string convert(string s, int numRows) {
//		if (numRows == 1) return s;
//		string* res = new string[numRows];
//		int i = 0, j, gap = numRows - 2;
//		while (i < s.size()){
//			for (j = 0; i < s.size() && j < numRows; ++j) res[j] += s[i++];
//			for (j = gap; i < s.size() && j > 0; --j) res[j] += s[i++];
//		}
//		string str = "";
//		for (i = 0; i < numRows; ++i)
//			str += res[i];
//		return str;
//	}
//};