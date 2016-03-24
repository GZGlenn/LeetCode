#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		if (n == 0) return "";

		string result = "";
		int temp;
		while (n > 26) {
			temp = (n - 1) % 26;
			result = char('A' + temp) + result;
			n = (n - 1) / 26;
		}

		if (n > 0) {
			result = char('A' + (n - 1)) + result;
		}

		return result;
	}
};