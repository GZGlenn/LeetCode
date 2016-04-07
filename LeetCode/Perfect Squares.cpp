#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// dp
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp = vector<int>(n+1,0);
		dp[1] = 1;

		for (int i = 2; i <= n; i++) {
			int j = 1, minStep = INT_MAX;
			while (j*j <= i) {
				if (j*j == i) {
					minStep = 1;
					break;
				}
				minStep = min(minStep, dp[i - j*j] + 1);
				++j;
			}
			dp[i] = minStep;
		}

		return dp[n];
	}
};