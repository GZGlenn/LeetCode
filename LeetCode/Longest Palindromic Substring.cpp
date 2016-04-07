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
// n(o)ʱ�����ĵ��������㷨
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
		// tΪ��������ַ�����pΪ��¼���ȵ�����    
		memset(p, 0, sizeof(int) * (N<<1));
		// mxΪ���жϻ��Ĵ����ұ�λ�ã�idΪ�м�λ�ã�mmax��¼p���������ֵ    
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
		// �Ϊmmax - 1    
		return s.substr(right / 2 - mmax / 2, mmax - 1);
	}
};