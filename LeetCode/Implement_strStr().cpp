#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.empty() && needle.empty()) return 0;
		
		int result = -1, k = 0, j = 0;
		int needleLen = needle.size();
		bool flag;
		for (int i = 0; haystack[i] != '\0'; i++) {
			flag = true;
			for (j = 0, k = i; needle[j] != '\0' && haystack[k] != '\0'; k++, j++) {
				if (haystack[k] == needle[j]) continue;
				else {
					flag = false;
					break;
				}
			}

			if (!flag) continue;
			else if (needle[j] != '\0') return -1;
			else return i;
		}

		return -1;
	}
};