#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		stack<string> dic;
		int size = path.size();
		int p = 0;
		while (p < size) {
			while (p < size && path[p] == '/') p++;
			int start = p;
			while (p < size && path[p] != '/') {
				p++;
			}
			if (p == start) break;
			string tmp = path.substr(start, p - start);
			if (tmp == ".") continue;
			if (tmp == "..") {
				if (dic.size() > 0) dic.pop();
				continue;
			}
			dic.push(tmp);
		}
		string ans = "";
		stack<string> rev;
		while (dic.size() > 0) {
			rev.push(dic.top());
			dic.pop();
		}
		while (rev.size() > 0) {
			ans += ("/" + rev.top());
			rev.pop();
		}
		if (ans == "") ans = "/";
		return ans;
	}
};