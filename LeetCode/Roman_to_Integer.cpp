#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int ret = toNumber(s[0]);
		for (int i = 1; i < s.length(); i++) {
			if (toNumber(s[i - 1]) < toNumber(s[i])) {
				ret += toNumber(s[i]) - 2 * toNumber(s[i - 1]);
			}
			else {
				ret += toNumber(s[i]);
			}
		}
		return ret;
	}

	int toNumber(char ch) {
		switch (ch) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		}
		return 0;
	}
};


//class Solution {
//public:
//	Solution() {
//		myMap = unordered_map<char, int>();
//		myMap['I'] = 1; myMap['V'] = 5;
//		myMap['X'] = 10; myMap['L'] = 50;
//		myMap['C'] = 100; myMap['D'] = 500;
//		myMap['M'] = 1000;
//	}
//
//	int romanToInt(string s) {
//		int result = 0;
//
//		int pre = 0;
//		for (int i = 0; i < s.size(); i++) {
//			if (i == 0) {
//				pre = myMap[s[i]];
//			}
//			else if (s[i] == s[i - 1]) {
//				pre += myMap[s[i]];
//			}
//			else if (myMap[s[i]] < myMap[s[i - 1]]) {
//				result += pre;
//				pre = myMap[s[i]];
//			}
//			else if (myMap[s[i]] > myMap[s[i - 1]]) {
//				result -= pre;
//				pre = myMap[s[i]];
//			}
//		}
//
//		result += pre;
//		return result;
//	}
//
//private:
//	unordered_map<char, int> myMap;
//};