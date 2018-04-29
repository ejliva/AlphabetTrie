#include "stdafx.h"
#include "Trie.h"


Trie::Trie()
{
	root = new Node();
	root->prefixCount = 0;
	root->endofWord = false;
	int countNodes = 0;
	int wordCount = 0;
}


Trie::~Trie()
{
	delete root;
}

/*This inserts a new word into the trie. Duplicates are not allowed
returns true if word is successfully inserted and false if word could not be inserted.
Best-case time complexity: Theta(n)
Worst-case time complexity: Theta(n)
Where n is the length of string.*/
bool Trie::insert(string word)
{
	Node* current = root;
	for (int i = 0; i < word.length(); i++) {
		if (current->children[word[i] - 'a'] == NULL)
			current->children[word[i] - 'a'] = new Node();
		current->children[word[i] - 'a']->prefixCount++;
		current = current->children[word[i] - 'a'];
		countNodes++;
	}
	current->endofWord = true;
	wordCount++;
	return true;
}

/*This function returns the total number of nodes in the trie
Return the number of nodes in this trie.
Best-case time complexity: Theta(1)
Worst-case time complexity: Theta(1)
*/
int Trie::count()
{
	return wordCount;
}

/*This function returns the total number of nodes in the trie
Return the number of nodes in this trie.
Best-case time complexity: Theta(1)
Worst-case time complexity: Theta(1)
*/
int Trie::getsize()
{
	return countNodes;
}

/*This function returns true if the word is found. Returns false if word not found.
Best - case time complexity : Theta(n)
Worst - case time complexity : Theta(n)
Where n is the length of string.*/
bool Trie::find(string word)
{
	Node* current = root;

	for (int i = 0; i < word.length(); i++) {
		if (current->children[word[i] - 'a'] == NULL)
			return false;
		current = current->children[word[i] - 'a'];
	}
	return current->endofWord;
}

/*This function should return the number of words in the dictionary that begin with the given input string.
If no matching words are found, the function should return 0.
Best - case time complexity : Theta(n)
Worst - case time complexity : Theta(n)
Where n is the length of string.
*/
int Trie::completeCount(string word)
{
	Node* current = root;
	for (int i = 0; i < word.length(); i++) {
		if (current->children[word[i] - 'a'] == NULL)
		{
			//returns 0 of no matching words are found.
			return 0;
		}
		else
		{
			current = current->children[word[i] - 'a'];
		}
	}
	return current->prefixCount;
}

/*this function will read the wordlist
Best - case time complexity : Theta(n)
Worst - case time complexity : Theta(n)
Where n is the number of lines*/
bool Trie::read(string textfile) {

	ifstream infile(textfile);
	if (!infile.good()) {
		// The file doesn't exist.
		return false;
	}//end if
	string line;
	while (getline(infile, line)) {
		insert(line);
	}//end of while
	return true;
}

/*This function should return a C++ vector of string containing all of the words in the dictionary that begin with the given input string.
For each word found in the trie, there will be one value in the vector.
If no matching words are found the function should return an empty vector.
Best-case time complexity: Theta(n)
Worst-case time complexity: Theta(n)
where n is the length*/
vector<string> Trie::complete(string word)
{

	Node* current = root;
	for (int i = 0; i < word.length(); i++)
	{
		if (current->children[word[i] - 'a'] == nullptr)
		{
			return vector<string>();	//returns empty vector
		}//end if
		current = current->children[word[i] - 'a'];
	}//end for
	vector<string> words = vector<string>();
	for (int i = 0; i<word.size(); i++) {
		if (find(word) != string::npos) {
			words.push_back(word);
		}
	}
	words.push_back(word);
	return words;
}//end function
