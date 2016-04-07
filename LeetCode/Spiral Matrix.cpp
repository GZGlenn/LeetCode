#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) return vector<int>();

		vector<int> result = vector<int>();

		int row_num = matrix.size();
		int col_num = matrix[0].size();

		if (row_num == 1 && col_num == 1) return vector<int>(1, matrix[0][0]);

		int row_start = 0, row_end = row_num - 1;
		int col_start = 0, col_end = col_num - 1;

		while (row_start < row_end && col_start < col_end) {
			for (int i = col_start; i <= col_end; i++) result.push_back(matrix[row_start][i]);
			for (int i = row_start + 1; i <= row_end; i++) result.push_back(matrix[i][col_end]);
			for (int i = col_end - 1; i >= col_start; i--) result.push_back(matrix[row_end][i]);
			for (int i = row_end - 1; i >= row_start + 1; i--) result.push_back(matrix[i][col_start]);
			row_start++; row_end--;
			col_start++; col_end--;
		}
		if (row_start == row_end && col_start == col_end) result.push_back(matrix[row_start][col_start]);

		if (row_start < row_end && col_start == col_end) {
			for (int i = row_start; i <= row_end; i++) result.push_back(matrix[i][col_start]);
		}

		if (col_start < col_end && row_start == row_end) {
			for (int i = col_start; i <= col_end; i++) result.push_back(matrix[row_start][i]);
		}

		return result;
	}
};