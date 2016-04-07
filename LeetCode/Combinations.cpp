#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (n <= 0 || k <= 0) return vector<vector<int>>();

		vector<vector<int>> result;
		backtrack(n, k, result, vector<int>(), 1);
		return result;
	}

	void backtrack(int n, int k, vector<vector<int>> &result, vector<int> curr, int start) {
		if (k == 0) {
			result.push_back(curr);
			return;
		}

		for (int i = start; i <= n; i++) {
			curr.push_back(i);
			backtrack(n, k - 1, result, curr, i + 1);
			curr.pop_back();
		}
	}
};