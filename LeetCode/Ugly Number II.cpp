#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int getMin(int a, int b, int c) {
		int minVal = a;
		if (minVal > b) minVal = b;
		if (minVal > c) minVal = c;
		return minVal;
	}

	int nthUglyNumber(int n) {
		if (n == 1) return 1;

		int *dp = new int[n];
		memset(dp, 0, sizeof(int)* n);

		dp[0] = 1;

		int factor2 = 2, factor3 = 3, factor5 = 5;
		int index2 = 0, index3 = 0, index5 = 0;

		for (int i = 1; i < n; i++) {
			int minValue = getMin(factor2, factor3, factor5);
			dp[i] = minValue;

			if (minValue == factor2) factor2 = 2 * dp[++index2];
			if (minValue == factor3) factor3 = 3 * dp[++index3];
			if (minValue == factor5) factor5 = 5 * dp[++index5];
		}

		return dp[n - 1];
	}
};