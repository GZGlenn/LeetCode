#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (prerequisites.empty() || numCourses == 0) return 0;

		vector<vector<int>> courseInfo = vector<vector<int>>(numCourses);
		vector<int> inDegree = vector<int>(numCourses, 0);

		for (int i = 0; i < prerequisites.size(); i++) {
			courseInfo[prerequisites[i].first].push_back(prerequisites[i].second);
			inDegree[prerequisites[i].second]++;
		}

		queue<int> courseQueue;
		for (int i = 0; i < courseInfo.size(); i++) {
			if (inDegree[i] == 0)
				courseQueue.push(i);
		}

		while (!courseQueue.empty()) {
			int inCourse = courseQueue.front();
			courseQueue.pop();
			for (int i = 0; i < courseInfo[inCourse].size(); i++) {
				inDegree[courseInfo[inCourse][i]]--;
				if (inDegree[courseInfo[inCourse][i]] == 0)
					courseQueue.push(courseInfo[inCourse][i]);
			}
		}

		for (int i = 0; i < numCourses; i++) {
			if (inDegree[i] != 0) return false;
		}

		return true;
	}
};