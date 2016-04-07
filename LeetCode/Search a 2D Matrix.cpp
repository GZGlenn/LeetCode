#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;

		int rows = matrix.size();
		int cols = matrix[0].size();

		int row = 0;
		for (; row < rows; row++) {
			if (matrix[row][0] <= target && matrix[row][cols - 1] >= target) break;
		}

		if (row == rows) return false;

		int left = 0, right = cols - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (matrix[row][mid] == target) return true;
			else if (matrix[row][mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return false;
	}
};