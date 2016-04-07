#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	Solution() {
		mMap = unordered_map<char, vector<char>>();
		mMap['2'] = vector<char>(3); mMap['2'][0] = 'a'; mMap['2'][1] = 'b'; mMap['2'][2] = 'c';
		mMap['3'] = vector<char>(3); mMap['3'][0] = 'd'; mMap['3'][1] = 'e'; mMap['3'][2] = 'f';
		mMap['4'] = vector<char>(3); mMap['4'][0] = 'g'; mMap['4'][1] = 'h'; mMap['4'][2] = 'i';
		mMap['5'] = vector<char>(3); mMap['5'][0] = 'j'; mMap['5'][1] = 'k'; mMap['5'][2] = 'l';
		mMap['6'] = vector<char>(3); mMap['6'][0] = 'm'; mMap['6'][1] = 'n'; mMap['6'][2] = 'o';
		mMap['7'] = vector<char>(4); mMap['7'][0] = 'p'; mMap['7'][1] = 'q'; mMap['7'][2] = 'r'; mMap['7'][3] = 's';
		mMap['8'] = vector<char>(3); mMap['8'][0] = 't'; mMap['8'][1] = 'u'; mMap['8'][2] = 'v';
		mMap['9'] = vector<char>(4); mMap['9'][0] = 'w'; mMap['9'][1] = 'x'; mMap['9'][2] = 'y'; mMap['9'][3] = 'z';
	}

	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return vector<string>();
		if (digits.find('0') != string::npos ||
			digits.find('1') != string::npos)
			return vector<string>();

		vector<string> result;
		dfs(digits, result, "", 0);
		return result;
	}

	void dfs(string digits, vector<string> &result, string curr, int start) {
		if (start == digits.size()) {
			result.push_back(curr);
			return;
		}

		char digit = digits[start];
		for (int i = 0; i < mMap[digit].size(); i++) {
			curr.push_back(mMap[digit][i]);
			dfs(digits, result, curr, start + 1);
			curr.pop_back();
		}
	}

private:
	unordered_map<char, vector<char>> mMap;
};