#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		if (triangle.size() == 1) return triangle[0][0];

		vector<vector<int>> dp(triangle.size());
		
		for (int i = 0; i < triangle.size(); i++) {
			vector<int> temp(i+1, 0);
			dp[i] = temp;
		}
		dp[0][0] = triangle[0][0];

		for (int i = 1; i < triangle.size(); i++) {
			for (int j = 0; j < dp[i].size(); j++) {
				if (j == 0)
					dp[i][j] = dp[i - 1][j] + triangle[i][j];
				else if (j == dp[i].size() - 1)
					dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
				else
					dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}

		int result = INT_MAX;
		for (vector<int>::iterator iter = dp[dp.size() - 1].begin();
			iter != dp[dp.size() - 1].end(); iter++) {
			if (result > *iter) result = *iter;
		}
		return result;
	}
};