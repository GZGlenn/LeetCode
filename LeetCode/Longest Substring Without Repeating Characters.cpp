#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() <= 1) return s.length();

		int result = 0;
		int start = 0, end = 0;
		vector<int> pos(256, -1);

		while (end < s.length()) {
			int index = s[end];
			if (pos[index] < 0) {
				pos[index] = end;
				end++;
			}
			else {
				result = max(result, end - start);
				start = pos[index] + 1;
				pos[index] = end;
				end++;
				for (int i = 0; i < 256; i++) {
					if (pos[i] < start) pos[i] = -1;
				}
			}
		}
		result = max(result, end - start);

		return result;
	}
};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.length();
		int i = 0, j = 0;
		int maxLen = 0;
		bool exist[256] = { false };
		while (j < n) {
			if (exist[s[j]]) {
				maxLen = max(maxLen, j - i);
				while (s[i] != s[j]) {
					exist[s[i]] = false;
					i++;
				}
				i++;
				j++;
			}
			else {
				exist[s[j]] = true;
				j++;
			}
		}
		maxLen = max(maxLen, n - i);
		return maxLen;
	}
};