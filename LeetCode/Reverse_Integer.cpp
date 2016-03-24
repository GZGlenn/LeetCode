#include <iostream>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		double s = 0;
		int flag = 1;

		if (x == 0) return 0;
		if (x<0)
		{
			flag = -1;
			x = x*(-1);
		}

		while (x>0){
			s = s * 10 + x % 10;
			x = x / 10;
		}
		s = s*flag;
		return (s > INT_MAX || s < INT_MIN ? 0 : s);

	}
};