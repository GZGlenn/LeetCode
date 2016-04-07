#include <string>
#include <vector>
#include <set>

using namespace std;

class TrieNode
{
public:
	bool isEnd;
	TrieNode *children[26];
	TrieNode() : isEnd(false)
	{
		for (int i = 0; i < 26; i++)
		{
			children[i] = NULL;
		}
	}
};

class WordDictionary {
public:

	WordDictionary(){
		codebook = new TrieNode();
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode* node = codebook;
		for (int i = 0; i < word.size(); i++) {
			int index = word[i] - 'a';
			if (node->children[index] == nullptr)
				node->children[index] = new TrieNode();
			node = node->children[index];
		}
		node->isEnd = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		if (codebook == nullptr) return false;
		if (word.empty() && !codebook->isEnd) return false;
		else if (word.empty() && codebook->isEnd) return true;

		return dfs(word, 0, codebook);
	}

	bool dfs(string &word, int start, TrieNode* node) {
		if (start == word.size()) return node->isEnd;
		if (word[start] == '.') {
			for (int i = 0; i < 26; i++) {
				if (node->children[i] && dfs(word, 1+start, node->children[i])) 
					return true;
			}
		}
		else {
			int index = word[start] - 'a';
			if (node->children[index] == nullptr) return false;
			
			return dfs(word, ++start, node->children[index]);
		}
		return false;
	}

private:
	TrieNode* codebook;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");




//class Trie
//{
//public:
//	Trie *next[26];
//	int flag;
//	Trie() :flag(0)
//	{
//		for (int i = 0; i<26; i++)
//			next[i] = 0;
//	}
//};
//class WordDictionary {
//
//private:
//	Trie *root;
//public:
//	WordDictionary(){
//		root = new Trie();
//	}
//	// Adds a word into the data structure.
//	void addWord(string word) {
//		Trie *p = root;
//		for (int i = 0; i<word.length(); i++)
//		{
//			if (p->next[word[i] - 'a'] == NULL)
//			{
//				p->next[word[i] - 'a'] = new Trie();
//			}
//			p = p->next[word[i] - 'a'];
//		}
//		p->flag = 1;
//	}
//
//	// Returns if the word is in the data structure. A word could
//	// contain the dot character '.' to represent any one letter.
//	bool search(string word) {
//		int n = word.length();
//		return searchHelp(word, 0, root, n);
//	}
//	bool searchHelp(string &word, int cur, Trie *root, int n)
//	{
//		if (root == NULL)
//			return false;
//		if (cur == n)
//		{
//			if (root->flag)
//				return true;
//			return false;
//		}
//		if (word[cur] == '.')
//		{
//			for (int i = 0; i<26; i++)
//			{
//				if (root->next[i])
//				if (searchHelp(word, cur + 1, root->next[i], n))
//					return true;
//				// return searchHelp(word,cur+1,root->next[i],n)
//				// is wrong.because maybe another node is ok
//			}
//		}
//		else
//		{
//			int temp = word[cur] - 'a';
//			if (root->next[temp])
//				return searchHelp(word, cur + 1, root->next[temp], n);
//			return false;
//		}
//
//		//	return false;
//	}
//};