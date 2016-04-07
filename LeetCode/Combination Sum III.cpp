#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		if (k == 0) return vector<vector<int>>();

		vector<vector<int>> result;
		backtrack(k, n, result, vector<int>(), 1);
		return result;
	}

	void backtrack(int k, int n, vector<vector<int>> &result, vector<int> curr, int start) {
		if (k == 1 && n > 9) return;
		if (n < 0) return;

		if (k == 0) {
			if (n == 0) result.push_back(curr);
			return;
		}

		for (int i = start; i <= 9; i++) {
			if (i > n) return;
			curr.push_back(i);
			backtrack(k - 1, n - i, result, curr, i + 1);
			curr.pop_back();
		}
	}
};