#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.empty()) return 0;
		if (tokens.size() == 1) return atoi(tokens[0].c_str());

		stack<int> s;
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i].size() == 1 && (tokens[i][0] == '+' ||
				tokens[i][0] == '-' || tokens[i][0] == '*' ||
				tokens[i][0] == '/')) {
				int data2 = s.top(); s.pop();
				int data1 = s.top(); s.pop();
				int result = 0;
				if (tokens[i][0] == '+') result = data1 + data2;
				else if (tokens[i][0] == '-') result = data1 - data2;
				else if (tokens[i][0] == '*') result = data1 * data2;
				else if (tokens[i][0] == '/') result = data1 / data2;
				s.push(result);
			}
			else {
				s.push(atoi(tokens[i].c_str()));
			}
		}
		return s.top();
	}
};