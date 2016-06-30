#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		if (secret.empty() || guess.empty()) return "";

		int A = 0, B = 0;

		unordered_map<char, pair<int, int> > statistic;
		for (int i = 0; secret[i] != '\0'; i++) {
			if (statistic.count(secret[i]) == 0)
				statistic[secret[i]] = pair<int, int>(1, 0);
			else
				statistic[secret[i]].first++;
		}

		for (int i = 0; secret[i] != '\0' && guess[i] != '\0'; i++) {
			if (secret[i] == guess[i]) {
				A++;
				statistic[secret[i]].second++;
			}
			else if (statistic.count(guess[i]) != 0 &&
				statistic[guess[i]].first > statistic[guess[i]].second) {
				statistic[guess[i]].second++;
				B++;
			}
		}

		for (unordered_map<char, pair<int, int> >::iterator iter = statistic.begin();
			iter != statistic.end(); iter++) {
			int diff = iter->second.second - iter->second.first;
			if (diff > 0) B = B - diff;
		}

		char *p = new char[4];
		sprintf(p, "%dA%dB", A, B);
		string result(p);
		return result;
	}
};

//class Solution {
//public:
//	string getHint(string secret, string guess) {
//		int cntA = 0, cntB = 0;
//		unordered_map<char, int> hash;
//		vector<bool> tag(secret.size(), false);
//		for (auto a : secret) {
//			++hash[a];
//		}
//		for (int i = 0; i < secret.size(); ++i) {
//			if (secret[i] == guess[i]) {
//				++cntA;
//				--hash[secret[i]];
//				tag[i] = true;
//			}
//		}
//		for (int i = 0; i < guess.size(); ++i) {
//			if (!tag[i] && hash[guess[i]] > 0) {
//				++cntB;
//				--hash[guess[i]];
//			}
//		}
//		return to_string(cntA) + "A" + to_string(cntB) + "B";
//	}
//};