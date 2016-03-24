#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int left1 = min(A, C); int right1 = max(A, C);
		int bottom1 = min(B, D); int top1 = max(B, D);

		int left2 = min(E, G); int right2 = max(E, G);
		int bottom2 = min(F, H); int top2 = max(F, H);

		int left = max(left1, left2); int right = min(right1, right2);
		int bottom = max(bottom1, bottom2); int top = min(top1, top2);

		int commonArea = 0;
		if (left >= right || bottom >= top) commonArea = 0;
		else commonArea = (right - left) * (top - bottom);

		int area1 = (right1 - left1) * (top1 - bottom1);
		int area2 = (right2 - left2) * (top2 - bottom2);
		return area1 + area2 - commonArea;
	}
};