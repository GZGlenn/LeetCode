#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix = vector<vector<int>>(n);
		for (int i = 0; i < n; i++) {
			matrix[i] = vector<int>(n);
		}

		int start_id = 0, end_id = n - 1;
		int value = 1;
		while (start_id < end_id) {
			for (int i = start_id; i <= end_id; i++) matrix[start_id][i] = value++;
			for (int i = start_id + 1; i <= end_id; i++) matrix[i][end_id] = value++;
			for (int i = end_id - 1; i >= start_id; i--) matrix[end_id][i] = value++;
			for (int i = end_id - 1; i >= start_id + 1; i--) matrix[i][start_id] = value++;
			start_id++;
			end_id--;
		}

		if (n % 2 == 1) matrix[start_id][start_id] = value;
		return matrix;
	}
};