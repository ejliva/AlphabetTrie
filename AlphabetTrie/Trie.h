#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#define ALPHABET_SIZE 26

using namespace std;


class Trie
{
	//Trie node class
	struct Node {
		char letter;
		struct Node* children[ALPHABET_SIZE];
		bool endofWord;
		int prefixCount;
	};//end of Trie Node class

private:
	Node* root = NULL;
	int countNodes;
	int wordCount;

public:
	Trie();
	~Trie();

	bool insert(string);
	int count();
	int getsize();
	bool find(string);
	int completeCount(string);
	vector<string> complete(string);
	bool read(string);

};//end of Trie class.


