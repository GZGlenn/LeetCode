#include <vector>

using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) {
		mNumMatrix.clear();
		if (matrix.empty()) return;

		int rows = matrix.size();
		int cols = matrix[0].size();

		mNumMatrix = vector<vector<int>>(rows);
		for (int i = 0; i < rows; i++) {
			mNumMatrix[i] = vector<int>(cols, 0);
		}

		mNumMatrix[0][0] = matrix[0][0];
		for (int i = 1; i < cols; i++) mNumMatrix[0][i] = mNumMatrix[0][i - 1] + matrix[0][i];
		for (int i = 1; i < rows; i++) mNumMatrix[i][0] = mNumMatrix[i - 1][0] + matrix[i][0];

		for (int i = 1; i < rows; i++) {
			for (int j = 1; j < cols; j++) {
				mNumMatrix[i][j] = mNumMatrix[i - 1][j] + mNumMatrix[i][j - 1]
					- mNumMatrix[i - 1][j - 1] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (row1 == 0 && col1 == 0) return mNumMatrix[row2][col2];
		if (row1 == 0) return mNumMatrix[row2][col2] - mNumMatrix[row2][col1 - 1];
		if (col1 == 0) return mNumMatrix[row2][col2] - mNumMatrix[row1 - 1][col2];
		return mNumMatrix[row2][col2] - mNumMatrix[row1 - 1][col2]
			- mNumMatrix[row2][col1 - 1] + mNumMatrix[row1 - 1][col1 - 1];
	}

private:
	vector<vector<int>> mNumMatrix;
};