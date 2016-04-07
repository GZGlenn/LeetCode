#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

bool cmp(string &s1, string &s2) {
	return s1 + s2 > s2 + s1;
}

class Solution {
public:

	string largestNumber(vector<int>& nums) {
		if (nums.empty()) return "0";

		vector<string> vecStr(nums.size());
		for (int i = 0; i < nums.size(); i++) {
			vecStr[i] = to_string(nums[i]);
		}

		sort(vecStr.begin(), vecStr.end(), cmp);

		stringstream ss;
		for (vector<string>::iterator iter = vecStr.begin();
			iter != vecStr.end(); iter++) {
			ss << *iter;
		}

		string result;
		ss >> result; ss.clear();

		for (int i = 0; i < result.size(); i++) {
			if (result[i] != '0') return result;
		}
		return "0";
	}
};