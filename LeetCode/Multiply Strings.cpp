#include <string>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.empty() || num2.empty()) return "";
		if (num1[0] == '0' || num2[0] == '0') return "0";

		string result;
		int temp = 0, pos1 = 0, carry = 0;
		for (int i = num1.size() - 1; i >= 0; i--) {
			int position = pos1;
			for (int j = num2.size() - 1; j >= 0; j--) {
				temp = (num1[i] - '0') * (num2[j] - '0') + carry;
				if (position < result.length()) {
					temp = temp + result[position] - '0';
					result[position] = temp % 10 + '0';
				}
				else {
					result.append(1, temp % 10 + '0');
				}

				carry = temp / 10;
				position++;
			}

			if (carry != 0) result.append(1, carry + '0');

			pos1++;
			carry = 0;
		}

		reverse(result.begin(), result.end());

		return result;
	}
};