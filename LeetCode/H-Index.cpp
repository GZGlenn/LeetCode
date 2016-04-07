#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty()) return 0;

		sort(citations.begin(), citations.end());

		if (citations[citations.size() - 1] == 0) return 0;

		int paperNum = 0;
		for (int i = citations.size() - 1; i >= 0; i--) {
			paperNum++;
			if (paperNum == citations[i]) return paperNum;
			else if (paperNum > citations[i]) return min(paperNum-1, citations[i+1]);
		}

		return min(paperNum, citations[0]);
	}
};