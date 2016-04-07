#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

	void split(string &preorder, char delim, vector<string>& vec){
		int pos = preorder.find_first_of(delim);
		if (pos != string::npos){
			int pre = 0;
			while (pos != string::npos){
				string tmp = preorder.substr(pre, pos - pre);
				vec.push_back(tmp);
				pre = pos + 1;
				pos = preorder.find_first_of(delim, pre);
			}
			if (pre < preorder.size()){
				vec.push_back(preorder.substr(pre));
			}
		}
		else{
			vec.push_back(preorder);
		}
	}

	bool isValidSerialization(string preorder) {
		if (preorder == "")   return true;
		bool flag = true;
		vector<string> vec;
		split(preorder, ',', vec);

		stack<string> st;
		st.push(vec[0]);
		int k = 1;
		while (!st.empty() && k < vec.size()){
			if (vec[k][0] == '#'){
				string tmp = st.top();
				while (tmp[0] == '#' && st.size() >= 2){
					st.pop();
					string dig = st.top();
					//cout << dig << endl;
					if (dig[0] == '#'){
						return false;
					}
					st.pop();
					if (!st.empty()) tmp = st.top();
				}
				st.push("#");
			}
			else{
				st.push(vec[k]);
			}
			++k;
		}
		//cout << st.size() << ": " << st.top() << endl; 
		if (st.size() == 1 && st.top() == "#")   return true;
		return false;
	}
};


// 观察先序遍历的结果，当出现叶节点时，就会出现两个"#"，
// 因为叶节点没有子节点。此时可以将该叶节点消除，即用一个"#"代替，
// 一层层向上归并消除直至根节点，最终只剩一个"#"。可以用栈来实现该过程。
// 以样例1为例来演示下该"归并"过程：
class Solution1 {
public:

	string getSubString(string preoder, int &start) {
		int pos = preoder.find(",", start);
		string result = "";
		if (pos >= preoder.size() || pos < 0) {
			result = preoder.substr(start, preoder.size() - start);
			start = preoder.size();
		}
		else {
			result = preoder.substr(start, pos - start);
			start = pos + 1;
		}
		return result;
	}

	bool isValidSerialization(string preorder) {
		if (preorder.empty()) return false;

		stack<string> s = stack<string>();

		for (int i = 0; i < preorder.size();) {
			string subStr = getSubString(preorder, i);
			if (subStr.empty()) break;
			if (strcmp(subStr.c_str(), "#") == 0) {
				while (!s.empty() && strcmp(s.top().c_str(), "#") == 0) {
					s.pop();
					if (s.empty()) return false;
					s.pop();
				}
				s.push("#");
			}
			else {
				s.push(subStr);
			}
		}

		if (s.size() == 1 && strcmp(s.top().c_str(), "#") == 0) return true;
		else return false;
	}
};