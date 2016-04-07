#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

		vector<vector<int>> courseInfo = vector<vector<int>>(numCourses);
		vector<int> inDegree = vector<int>(numCourses, 0);

		for (int i = 0; i < prerequisites.size(); i++) {
			courseInfo[prerequisites[i].second].push_back(prerequisites[i].first);
			inDegree[prerequisites[i].first]++;
		}

		queue<int> courseQueue;
		for (int i = 0; i < courseInfo.size(); i++) {
			if (inDegree[i] == 0)
				courseQueue.push(i);
		}

		vector<int> result = vector<int>();
		while (!courseQueue.empty()) {
			int course = courseQueue.front();
			courseQueue.pop();

			for (int i = 0; i < courseInfo[course].size(); i++) {
				inDegree[courseInfo[course][i]]--;
				if (inDegree[courseInfo[course][i]] == 0)
					courseQueue.push(courseInfo[course][i]);
			}

			result.push_back(course);
		}

		if (result.size() != numCourses) result.clear();
		return result;
	}
};