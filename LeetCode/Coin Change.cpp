#include <vector>

using namespace std;

// dp����dp[i] Ϊ�һ�Ŀ��i���ٵ�Ӳ������
//���У�dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1��

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.empty()) return -1;
		
		vector<int> dp = vector<int>(amount+1,-1);
		dp[0] = 0;
		for (int i = 0; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (i + coins[j] <= amount && dp[i] >= 0 && 
					(dp[i + coins[j]] <= 0 || dp[i + coins[j]] > dp[i] + 1))
					dp[i + coins[j]] = dp[i] + 1;
			}
		}

		return dp[amount]; 
	}
};