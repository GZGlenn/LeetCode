#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.empty() && t.empty()) return true;

		unordered_map<char, char> firstMap;
		unordered_map<char, char> secondMap;
		for (int i = 0; s[i] != '\0'; ++i) {
			if (firstMap.count(s[i]) == 0 && secondMap.count(t[i]) == 0) {
				firstMap[s[i]] = t[i];
				secondMap[t[i]] = s[i];
			}
			else if (firstMap.count(s[i]) != 0 && secondMap.count(t[i]) == 0) {
				if (firstMap[s[i]] != t[i]) return false;
				secondMap[t[i]] = s[i];
			}
			else if (firstMap.count(s[i]) == 0 && secondMap.count(t[i]) != 0) {
				if (secondMap[t[i]] != s[i]) return false;
				firstMap[s[i]] = t[i];
			}
			else if (firstMap[s[i]] != t[i] || secondMap[t[i]] != s[i]) return false;
		}
		return true;
	}
};

//class Solution {
//public:
//	bool isIsomorphic(string s, string t) {
//		if (s.length() != t.length()) return false;
//		unordered_map<char, char> mp;
//		for (int i = 0; i < s.length(); ++i) {
//			if (mp.find(s[i]) == mp.end()) mp[s[i]] = t[i];
//			else if (mp[s[i]] != t[i]) return false;
//		}
//		mp.clear();
//		for (int i = 0; i < s.length(); ++i) {
//			if (mp.find(t[i]) == mp.end()) mp[t[i]] = s[i];
//			else if (mp[t[i]] != s[i]) return false;
//		}
//		return true;
//	}
//};