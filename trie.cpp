#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct trie {
	string definition;
	unordered_map<char, trie*> ch;
	void insert(string word, string meaning) {
		trie* ptr = this;
		for (auto c : word)
			if (ptr->ch[c])
				ptr = ptr->ch[c];
			else
				ptr = ptr->ch[c] = new trie;
		ptr->definition = meaning;
	}
	trie* searchPrefix(string prefix) {
		trie* ptr = this;
		for (auto c : prefix)
			if (ptr->ch[c])
				ptr = ptr->ch[c];
			else
				return nullptr;
		return ptr;
	}
	string search(string word) {
		trie* ptr = searchPrefix(word);
		return ptr ? ptr->definition : "Not found!";
	}
	void fuzzySearchPrefix(string prefix) {
		trie* ptr = searchPrefix(prefix);
		return void(ptr ? ptr->list(prefix) : 0);
	}
	void list(string prefix) {
		if (definition != "") 
			cout << std::left << setw(16) << prefix << '|' << definition << endl;
		for (auto p:ch) 
			if (p.second) 
				p.second->list(prefix + p.first);
	}
	
};
int main() {
	trie dict;
	ifstream fin;
	fin.open("dict.txt");
	string word, definition;
	while (fin >> word) {
		fin.get();
		getline(fin, definition);
		dict.insert(word, definition);
	}
	cout << "请输入要查找的单词：";
	string input;
	cin >> input;
	cout<<dict.search(input);
	dict.fuzzySearchPrefix("ba");
	return 0;
}