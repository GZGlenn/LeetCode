#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> hashMap;
		for (auto s : strs) {
			string tmp(s);
			sort(tmp.begin(),tmp.end());
			hashMap[tmp].push_back(s);
		}

		vector<vector<string>> result;
		for (unordered_map<string, vector<string>>::iterator iter = hashMap.begin();
			iter != hashMap.end(); iter++) {
			vector<string> temp = iter->second;
			sort(temp.begin(), temp.end());
			result.push_back(temp);
		}

		return result;
	}
};