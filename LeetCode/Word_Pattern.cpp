#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> dic;
		istringstream sin(str);
		string tmp;
		while (sin >> tmp) dic.push_back(tmp);
		if (dic.size() != pattern.size()) return false;
		unordered_map<char, string> mp1;
		unordered_map<string, char> mp2;
		for (int i = 0; i < pattern.size(); ++i) {
			if (mp1.find(pattern[i]) == mp1.end()) {
				mp1[pattern[i]] = dic[i];
			}
			else if (mp1[pattern[i]] != dic[i]) {
				return false;
			}
			if (mp2.find(dic[i]) == mp2.end()) {
				mp2[dic[i]] = pattern[i];
			}
			else if (mp2[dic[i]] != pattern[i]) {
				return false;
			}
		}
		return true;
	}
};