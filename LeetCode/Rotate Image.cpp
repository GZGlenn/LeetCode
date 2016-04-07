#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty()) return;
		int rows = matrix.size();

		for (int i = 0; i < rows / 2; i++) {
			for (int j = 0; j < (rows + 1) / 2; j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[rows - 1 - j][i];
				matrix[rows - 1 - j][i] = matrix[rows - 1 - i][rows - 1 - j];
				matrix[rows - 1 - i][rows - 1 - j] = matrix[j][rows - 1 - i];
				matrix[j][rows - 1 - i] = temp;
			}
		}

		return;
	}
};