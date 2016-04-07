#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;

		unordered_map<int, UndirectedGraphNode*> myMap;
		queue<UndirectedGraphNode*> myQueue;
		myQueue.push(node);
		while (!myQueue.empty()) {
			UndirectedGraphNode* temp = myQueue.front();
			myQueue.pop();
			if (myMap.find(temp->label) == myMap.end()) {
				UndirectedGraphNode* new_node = new UndirectedGraphNode(temp->label);
				myMap.insert(pair<int, UndirectedGraphNode*>(temp->label, new_node));
				for (int i = 0; i < temp->neighbors.size(); i++) {
					myQueue.push(temp->neighbors[i]);
				}
			}
		}

		myQueue.push(node);
		while (!myQueue.empty()) {
			UndirectedGraphNode* temp = myQueue.front();
			myQueue.pop();

			UndirectedGraphNode* new_node = myMap[temp->label];

			if (new_node->neighbors.empty() && !temp->neighbors.empty()) {
				for (int i = 0; i < temp->neighbors.size(); i++) {
					UndirectedGraphNode* temp_node = myMap[temp->neighbors[i]->label];
					(new_node->neighbors).push_back(temp_node);
					myQueue.push(temp->neighbors[i]);
				}
			}
		}

		return myMap[node->label];
	}
};


class Solution1 {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL)
		{
			return NULL;
		}
		map<int, UndirectedGraphNode*> nodes;
		queue<UndirectedGraphNode*> q;

		q.push(node);

		while (!q.empty())
		{
			UndirectedGraphNode* tmp = q.front();
			q.pop();
			if (nodes.find(tmp->label) == nodes.end())
			{
				UndirectedGraphNode* new_node = new UndirectedGraphNode(tmp->label);
				nodes.insert(pair<int, UndirectedGraphNode*>(new_node->label, new_node));
				for (int i = 0; i<tmp->neighbors.size(); i++)
				{
					q.push(tmp->neighbors[i]);
				}
			}
		}

		q.push(node);
		while (!q.empty())
		{
			UndirectedGraphNode* tmp = q.front();
			q.pop();
			UndirectedGraphNode* existingnode = nodes[tmp->label];
			if (existingnode->neighbors.empty() && !tmp->neighbors.empty())
			{
				for (int i = 0; i<tmp->neighbors.size(); i++)
				{
					existingnode->neighbors.push_back(nodes[tmp->neighbors[i]->label]);
					q.push(tmp->neighbors[i]);
				}
			}
		}

		return nodes[node->label];
	}
};