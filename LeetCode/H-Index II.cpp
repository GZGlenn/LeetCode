#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty()) return 0;
		if (citations.size() == 1) return min(1, citations[0]);

		int n = citations.size();
		int left = 0, right = citations.size() - 1;
		int maxH = 0;
		while (left < right) {
			int mid = left + (right - left) / 2;
			int paper = n - mid;
			if (citations[mid] == paper) return citations[mid];
			else if (citations[mid] > paper) {
				right = mid - 1;
				if (maxH < paper) maxH = paper;
			}
			else {
				left = mid + 1;
				if (maxH < citations[mid]) maxH = citations[mid];
			}
		}

		int paper = n - left;
		if (left == right && maxH < min(paper, citations[left]))
			maxH = min(paper, citations[left]);

		return maxH;
	}
};