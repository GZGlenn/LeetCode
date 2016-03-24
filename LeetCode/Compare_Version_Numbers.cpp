#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		if (version1.empty() && version2.empty()) return 0;
		else if (version1.empty() && !version2.empty()) return -1;
		else if (!version1.empty() && version2.empty()) return 1;

		int ind1 = 0, ind2 = 0;
		while (ind1 < version1.size() && ind2 < version2.size()) {
			int data1 = getInt(version1, ind1);
			int data2 = getInt(version2, ind2);

			if (data1 > data2) return 1;
			else if (data1 < data2) return -1;
		}

		if (ind1 >= version1.size() && ind2 >= version2.size()) return 0;
		else if (ind1 < version1.size()) {
			while (ind1 < version1.size()) {
				int data = getInt(version1, ind1);
				if (data != 0) return 1;
			}
			return 0;
		}
		else {
			while (ind2 < version2.size()) {
				int data = getInt(version2, ind2);
				if (data != 0) return -1;
			}
			return 0;
		}
	}

	int getInt(string version, int &start) {
		string str;
		int end = version.find(".", start);
		if (end < 0) {
			string str = version.substr(start, version.size());
			start = version.size();
			return atoi(str.c_str());
		}
		else if (end == start) {
			start++;
			return 0;
		}
		else {
			str = version.substr(start, end);
			start = end + 1;
			return atoi(str.c_str());
		}
	}
};