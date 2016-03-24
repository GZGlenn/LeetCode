#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (x < 0)
			return false;
		if (x == 0)
			return true;

		int base = 1;
		while (x / base >= 10)
			base *= 10;

		while (x)
		{
			int leftDigit = x / base;
			int rightDigit = x % 10;
			if (leftDigit != rightDigit)
				return false;

			x -= base * leftDigit;
			base /= 100;
			x /= 10;
		}

		return true;
	}
};