#include <vector>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0) return vector<string>(1, "");

		vector<string> result;
		dfs(result, "", 2 * n, 0, 0);
		return result;
	}

	void dfs(vector<string> &result, string str, int maxNum, int leftNum, int rightNum) {
		if (leftNum > maxNum / 2 || rightNum > maxNum / 2 || leftNum < rightNum)
			return;

		if (leftNum + rightNum == maxNum) {
			result.push_back(str);
			return;
		}

		dfs(result, str + '(', maxNum, leftNum + 1, rightNum);
		dfs(result, str + ')', maxNum, leftNum, rightNum + 1);
	}
};