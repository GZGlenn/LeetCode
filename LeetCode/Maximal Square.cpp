#include <vector>
#include <algorithm>

using namespace std;

// dynamic programing.  以当前点(x,y) = '1' 为右下角的最大正方形的边长
// f(x,y) = min( f(x-1,y), f(x,y-1), f(x-1,y-1)) + 1.

class Solution {
public:
	int getMin(int a, int b, int c) {
		int minVal = a;
		if (minVal > b) minVal = b;
		if (minVal > c) minVal = c;
		return minVal;
	}

	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;

		int rows = matrix.size();
		int cols = matrix[0].size();

		vector<vector<int>> dp(rows);
		for (int i = 0; i < rows; i++) {
			dp[i] = vector<int>(cols, 0);
		}

		int maxEdge = 0;
		for (int i = rows - 1; i >= 0; i--) {
			dp[i][cols - 1] = matrix[i][cols - 1] == '0' ? 0 : 1;
			if (maxEdge == 0 && dp[i][cols - 1] == 1) maxEdge = 1;
		}

		for (int j = cols - 1; j >= 0; j--) {
			dp[rows - 1][j] = matrix[rows - 1][j] == '0' ? 0 : 1;
			if (maxEdge == 0 && dp[rows - 1][j] == 1) maxEdge = 1;
		}

		for (int i = rows - 2; i >= 0; i--) {
			for (int j = cols - 2; j >= 0; j--) {
				if (matrix[i][j] == '0') continue;
				dp[i][j] = getMin(dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]) + 1;
				maxEdge = max(maxEdge, dp[i][j]);
			}
		}

		return maxEdge * maxEdge;
	}
};