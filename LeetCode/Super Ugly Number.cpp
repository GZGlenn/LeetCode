#include <vector>

using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		if (n <= 1) return n;
		if (primes.empty()) return 1;

		vector<int> dp(n, INT_MAX);
		vector<int> index(n, 0);
		vector<int> temp(primes);

		int minVal = 0;
		dp[0] = 1;
		for (int i = 1; i < n; i++) {

			minVal = INT_MAX;
			for (int j = 0; j < primes.size(); j++) {
				if (temp[j] < minVal) {
					minVal = temp[j];
				}
			}
			dp[i] = minVal;

			for (int j = 0; j < primes.size(); j++) {
				if (minVal == temp[j]) 
					temp[j] = dp[++index[j]] * primes[j];
			}
		}

		return dp[n - 1];
	}
};