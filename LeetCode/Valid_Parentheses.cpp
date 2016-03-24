#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.empty()) return true;
		stack<char> myStack;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') myStack.push(s[i]);
			else if (s[i] == ')') {
				if (myStack.empty()) return false;
				char top = myStack.top();
				if (top != '(') return false;
				myStack.pop();
			}
			else if (s[i] == ']') {
				if (myStack.empty()) return false;
				char top = myStack.top();
				if (top != '[') return false;
				myStack.pop();
			}
			else if (s[i] == '}') {
				if (myStack.empty()) return false;
				char top = myStack.top();
				if (top != '{') return false;
				myStack.pop();
			}
		}
		if (myStack.empty()) return true;
		else return false;
	}
};