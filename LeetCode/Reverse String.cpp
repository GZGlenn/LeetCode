#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		if (s.size() <= 1) return s;
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
			swap(s[i],s[j]);
		}
		return s;
	}
};