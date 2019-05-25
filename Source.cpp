#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

const string delimiter = "\n";
const string delimiter1 = " ";

class node {
public:
	string word;
	vector<int>line;
	node* left;
	node* right;
};

class BST {
public:
	node* insert(node* root, string word, int lineNumber) {
		if (root == NULL) {
			root = new node;
			root->word = word;
			root->left = NULL;
			root->right = NULL;
			root->line.push_back(lineNumber);
		}
		else if (root->word == word) {
			root->line.push_back(lineNumber);
		}
		else if (root->word > word) {
			root->left = insert(root->left, word, lineNumber);
		}
		else if (root->word < word) {
			root->right = insert(root->right, word, lineNumber);
		}
		return root;
	}

	void inorder(node* root) {
		if (root != NULL) {
			inorder(root->left);
			cout << root->word << "   ";
			for (int i = 0; i < root->line.size(); i++) {
				cout << root->line[i] << " ";
			}
			cout << endl;
			inorder(root->right);
		}
	}
};

int main() {
	node* root = NULL;
	BST obj;
	string phrase = "I am for truth, \nno matter who tells it. \nI am for justice, \nno matter who it is for or against. \nMalcolm X \n";
	
	for (int i = 0; i < phrase.length(); i++) {
		if (phrase[i] == '.' || phrase[i] == ',') {
			phrase.erase(phrase.begin() + i);
		}
	}

	string arr[20];
	int i = 0;
	size_t pos;
	while ((pos = phrase.find(delimiter)) != string::npos) {
		string token = phrase.substr(0, pos);
		arr[i] = token;
		phrase.erase(0, pos + delimiter.length());
		i++;
	}
	
	size_t pos1;
	for (int i = 0; i < arr->size(); i++) {
		string str;
		string arr1[200];
		str = arr[i];
		int j = 0;
		while ((pos1 = str.find(delimiter1)) != string::npos) {
			string token = str.substr(0, pos1);
			arr1[j] = token;
			str.erase(0, pos1 + delimiter1.length());
			j++;
			if (root == NULL) {
				root = obj.insert(root, token, i + 1);
			}
			else
			{
				obj.insert(root, token, i + 1);
			}
		}
	}
	obj.inorder(root);
	system("pause");
	return 0;
}