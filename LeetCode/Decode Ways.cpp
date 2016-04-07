#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0) return 0;
		if (s.size() == 1) return s[0] == '0' ? 0 : 1;
		else if (s.size() == 2)
			return (s[0] != '0' && s[1] != '0') + (s[0] != '0' &&
			charToInt(s[0]) * 10 + charToInt(s[1]) <= 26);

		vector<int> dp(s.size(),0);
		dp[0] = s[0] == '0' ? 0 : 1;
		dp[1] = (s[0] != '0' && s[1] != '0') + (s[0] != '0' &&
			charToInt(s[0]) * 10 + charToInt(s[1]) <= 26);

		for (int i = 2; i < s.size(); i++) {
			if (s[i] != '0') dp[i] += dp[i - 1];
			if (s[i - 1] != '0' &&  charToInt(s[i - 1]) * 10 + charToInt(s[i]) <= 26)
				dp[i] += dp[i - 2];
		}

		return dp[s.size() - 1];
	}

	int charToInt(char c) {
		return c - '0';
	}
};