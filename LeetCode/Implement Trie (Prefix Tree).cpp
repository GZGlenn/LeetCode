#include <string>
#include <vector>

using namespace std;

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		isEnd = false;
		child = vector<TrieNode*>(26);
		for (int i = 0; i < 26; i++) {
			child[i] = NULL;
		}
	}

	bool hasChild(int index) {
		if (index > this->child.size()) return false;
		if (this->child[index] == nullptr) return false;
		return true;
	}

	TrieNode* getChild(int index) {
		return this->child[index];
	}

	void setChild(int index, TrieNode* node) {
		if (index > this->child.size()) return;
		this->child[index] = node;
	}

	bool getIsEnd() {
		return this->isEnd;
	}

	void setIsEnd(bool isEnd) {
		this->isEnd = isEnd;
	}

	TrieNode* next(int index) {
		if (index > this->child.size()) return nullptr;
		return this->child[index];
	}

private:
	bool isEnd;
	vector<TrieNode*> child;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* node = this->root;
		for (int i = 0; i < word.size(); i++) {
			int index = word[i] - 'a';
			if (!node->hasChild(index)) {
				node->setChild(index, new TrieNode());
			}
			node = node->next(index);
		}
		node->setIsEnd(true);
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* node = root;
		for (int i = 0; i < word.length(); i++) {
			int index = word[i] - 'a';
			if (!node->hasChild(index)) return false;
			node = node->getChild(index);
		}
		if (node != nullptr && node->getIsEnd()) return true;
		return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* node = root;
		for (int i = 0; i < prefix.length(); i++) {
			int index = prefix[i] - 'a';
			if (!node->hasChild(index)) return false;
			node = node->getChild(index);
		}
		if (node != nullptr) return true;
		return false;
	}

private:
	TrieNode* root;
};