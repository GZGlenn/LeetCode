#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.length();
		int longestBegin = 0;
		int maxLen = 1;
		bool table[1000][1000] = { false };
		for (int i = 0; i < n; i++) {
			table[i][i] = true;
		}
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1]) {
				table[i][i + 1] = true;
				longestBegin = i;
				maxLen = 2;
			}
		}
		for (int len = 3; len <= n; len++) {
			for (int i = 0; i < n - len + 1; i++) {
				int j = i + len - 1;
				if (s[i] == s[j] && table[i + 1][j - 1]) {
					table[i][j] = true;
					longestBegin = i;
					maxLen = len;
				}
			}
		}
		return s.substr(longestBegin, maxLen);
	}
};

// http://blog.csdn.net/yzl_rex/article/details/7908259
// n(o)时间消耗的最大回文算法
class Solution1 {
public:
	string longestPalindrome(string s) {
		int N = s.length();
		int* p = new int[N << 1];
		string t = "$";
		for (char ch : s) {
			t += '#';
			t += ch;
		}
		t += '#';
		// t为处理过的字符串，p为记录长度的数组    
		memset(p, 0, sizeof(int) * (N<<1));
		// mx为已判断回文串最右边位置，id为中间位置，mmax记录p数组中最大值    
		int mx = 0, id = 0, mmax = 0;
		int len = t.length();
		int right = 0;
		for (int i = 1; i < len; i++) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			while (t[i + p[i]] == t[i - p[i]])
				p[i]++;
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
			if (mmax < p[i]) {
				mmax = p[i];
				right = i;
			}
		}
		// 最长为mmax - 1    
		return s.substr(right / 2 - mmax / 2, mmax - 1);
	}
};