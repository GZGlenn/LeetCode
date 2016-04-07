#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		if (input.empty()) return vector<int>(0);

		vector<int> result;

		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
				vector<int> leftResult = diffWaysToCompute(input.substr(0, i));
				vector<int> rightResult = diffWaysToCompute(input.substr(i + 1));

				for (int j = 0; j < leftResult.size(); j++) {
					for (int k = 0; k < rightResult.size(); k++) {
						if (input[i] == '+')
							result.push_back(leftResult[j] + rightResult[k]);
						else if (input[i] == '-')
							result.push_back(leftResult[j] - rightResult[k]);
						else if (input[i] == '*')
							result.push_back(leftResult[j] * rightResult[k]);
					}
				}
			}
		}

		if (result.empty()) result.push_back(atoi(input.c_str()));
		return result;
	}
};