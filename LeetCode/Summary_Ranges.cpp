#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result = vector<string>();
		if (nums.size() == 0) return result;

		int start = 0;
		while (start < nums.size()) {
			string str = int2string(nums[start]);
			int current = start + 1;
			for (; current < nums.size(); current++) {
				if (nums[current] == nums[current - 1] + 1) continue;
				else {
					current--;
					break;
				}
			}

			current = current<(nums.size() - 1) ? current : (nums.size() - 1);
			if (current == start) result.push_back(str);
			else {
				str += "->" + int2string(nums[current]);
				result.push_back(str);
			}

			start = current + 1;
		}
		return result;
	}

	string int2string(int data) {
		char* p = new char[10];
		sprintf(p, "%d", data);
		string s = p;
		return s;
	}
};