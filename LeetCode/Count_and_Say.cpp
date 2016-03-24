#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	string unguarded_convert(const string &say) {
		stringstream ss;
		int count = 0;
		char last = say[0];

		for (size_t i = 0; i <= say.size(); ++i) {
			if (say[i] == last)
				++count;
			else {
				ss << count << last;
				count = 1;
				last = say[i];
			}
		}

		return ss.str();
	}

	string countAndSay(int n) {
		if (n <= 0) return string();
		string say = "1";

		for (int i = 1; i < n; ++i) 
			say = unguarded_convert(say);
		
		return say;
	}
};

//class Solution {
//public:
//	string countAndSay(int n) {
//		if (n == 0) return "1";
//		string result = "1";
//		for (int i = 1; i < n; i++) {
//			makeResult(result);
//		}
//		return result;
//	}
//
//	void makeResult(string& str) {
//		int preNum = 1;
//		string temp = "";
//		for (int i = 1; i < str.size(); i++) {
//			if (str[i] == str[i - 1]) preNum++;
//			else {
//				temp += to_string(preNum) + str[i - 1];
//				preNum = 1;
//			}
//		}
//
//		str = temp + to_string(preNum) + str[str.size() - 1];
//	}
//};