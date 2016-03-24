#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		if (n < 2) return 0;

		bool* b = new bool[n];
		for (int i = 0; i < n; i++) b[i] = true;

		b[0] = false; b[1] = false;
		for (int i = 2; i <= sqrt(n); i++) {
			if (b[i]) {
				for (int j = i * i; j < n; j = j + i) {
					b[j] = false;
				}
			}
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			if (b[i]) result++;
		}

		return result;
	}
};