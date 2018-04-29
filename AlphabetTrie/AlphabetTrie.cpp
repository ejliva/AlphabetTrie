// AlphabetTrie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Trie.h"

int main()
{
	Trie trie;

	//testing insert

	trie.insert("hello");
	trie.insert("data");
	trie.insert("structures");
	trie.insert("structures");
	trie.insert("hi");
	trie.insert("hi");

	//testing the number of nodes and words
	cout << "total nodes: " << trie.getsize() << endl;		//returns the number of nodes
	cout << "total words: " << trie.count() << endl;		//returns the number of words


	trie.insert("address");
	trie.insert("addressable");
	trie.insert("addressed");
	trie.insert("addressee");
	trie.insert("addressees");
	trie.insert("addresses");
	trie.insert("addressesing");

	//testing find function
	cout << "find address: " << trie.find("address") << endl;
	cout << "find ad: " << trie.find("ad") << endl;
	cout << "complete count for addr: " << trie.completeCount("addr") << endl;
	trie.complete("addr");

	//created object 2 that loads the dictionary
	//prompts the user for a prefix and find all completions
	Trie trie2;
	vector<string> words;
	trie2.read("wordlist.txt");
	cout << "Please enter a word prefix (or press enter to exit): ";
	string input;

	while (getline(cin, input)) {
		if (input == "") {
			break;
		}
		words = trie2.complete(input);
		if (words.size() == 0) {
			cout << "Error: no words are found." << endl;
		}
		else {
			cout << "There are " << trie2.completeCount(input) << " completions for the prefix " << "'" << input << "'." << " show completions? Yes" << endl;
			cout << "Completions" << endl;
			cout << "-----------" << endl;
			for (int i = 0; i <words.size(); i++) {
				cout << words[i] << endl;
			}
		}
		cout << "Please enter a word prefix (or press enter to exit): ";
	}

	system("pause");

	return 0;
}

