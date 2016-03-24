#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";

		int minSize = strs[0].size();
		for (int i = 1; i < strs.size(); i++) {
			if (minSize > strs[i].size()) minSize = strs[i].size();
		}

		string prefix = "";
		char temp;
		int flag = 0;
		for (int ind = 0; ind < minSize; ind++) {
			flag = 0; temp = NULL;
			for (int i = 0; i < strs.size(); i++) {
				if (strs[i].size() < ind + 1) {
					flag = 1;
					break;
				}
				if (i == 0 && temp == NULL) temp = strs[i][ind];
				else if (strs[i][ind] != temp) {
					flag = 1;
					break;
				}
			}

			if (flag == 1) break;
			else prefix += temp;
		}
		return prefix;
	}
};