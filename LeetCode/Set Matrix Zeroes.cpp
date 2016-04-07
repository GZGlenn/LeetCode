#include <vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		if (rows == 0) return;

		int cols = matrix[0].size();

		int row = -1, col = -1;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] == 0) {
					row = i;
					col = j;
					break;
				}
			}
			if (row != -1) break;
		}

		if (row == -1) return;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i == row && j == col) continue;
				if (matrix[i][j] == 0) {
					matrix[row][j] = 0;
					matrix[i][col] = 0;
				}
			}
		}

		for (int i = 0; i < rows; i++) {
			if (i != row && matrix[i][col] == 0) {
				for (int j = 0; j < cols; j++)
					matrix[i][j] = 0;
			}
		}

		for (int i = 0; i < cols; i++) {
			if (i != col && matrix[row][i] == 0) {
				for (int j = 0; j < rows; j++) {
					matrix[j][i] = 0;
				}
			}
		}

		for (int i = 0; i < rows; i++) matrix[i][col] = 0;
		for (int j = 0; j < cols; j++) matrix[row][j] = 0;
		return;
	}
};