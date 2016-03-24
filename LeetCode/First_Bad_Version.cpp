#include <iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int low = 1; int high = n; int var = 0;
		while (low < high) {
			var = low + (high - low) / 2;
			if (isBadVersion(var)) {
				high = var;
			}
			else {
				low = var + 1;
			}
		}
		return low;
	}
};