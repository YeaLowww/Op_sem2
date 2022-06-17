#include<iostream>
#include<string>
#include<stdio.h>
#include"levell.h"
#include"MyTree.h"
using namespace std;
string printText();
int split_text(string, string*);
int count_words(string*, string*, int);
void sort_arr(string*, int);
int make_arr(string*, string*, int);



string printText() {
	string line = " ", text="";
	cout << "Enter ur text: ";
	while (!empty(line)) {
		getline(cin, line);
		text = text + line + " ";
	}
	return text;
}
int split_text(string text, string* word_arr) {
	int pos ;
	string word;
	int c = 0;
	while ((pos = text.find(" ")) != string::npos){
		word = text.substr(0, pos);
		if (!empty(word)) {
			word_arr[c] = word;
			c++;
		}
		text.erase(0, pos + 1);
	}
	return c;

}
int count_words(string* word_arr, string* word_arr2, int c) {
	int counter = 0;
	for (int i = 0; i < c; i++){
		if (word_arr[i] != "") {
			int number = 1;
			for (int j = i+1; j < c; j++){
				if (word_arr[i] == word_arr[j]) {
					number++;
					word_arr[j] = "";
				}
			}
			word_arr2[counter] = word_arr[i] +" / " + to_string(number) + " times";
			counter++;
		}
	}
	return counter;
}
void sort_arr(string* word_arr2, int size) {
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size-1; j++){
			int num1 = stoi(word_arr2[j].substr(word_arr2[j].length()-7, word_arr2[j].length()));
			int num2 = stoi(word_arr2[j+1].substr(word_arr2[j+1].length()-7, word_arr2[j+1].length()));
			if (num2 > num1) {
				string tmp = word_arr2[j];
				word_arr2[j] = word_arr2[j + 1];
				word_arr2[j + 1] = tmp;
			}
		}
	}
}
int make_arr(string* sorted_arr, string* res_arr, int size) {
	int count = 0;
	for (int i = 0; i < size; i++){
		int num1 = stoi(sorted_arr[i].substr(sorted_arr[i].length() - 7, sorted_arr[i].length()));
		string line = sorted_arr[i].substr(0, sorted_arr[i].length() - 10);
		for (int j = 0; j < num1; j++){
			res_arr[count] = line;
			count++;
		}
	}
	return count;
}

int main() {
	string text = printText();
	string* word_arr = new string[(int)text.length()/2];
	int c = split_text(text, word_arr);
	string* word_arr2 = new string[c];
	int counter = count_words(word_arr, word_arr2, c);
	sort_arr(word_arr2, counter);
	for (int i = 0; i < counter; i++){
		cout << word_arr2[i] << endl;
	}
	string* res_arr = new string[(int)text.length() / 2];
	int n = make_arr(word_arr2, res_arr, counter);


	Tree MyBinaryTree;
	Node* root = MyBinaryTree.makeTree(res_arr, 0, n);
	cout << endl;
	MyBinaryTree.printTree("",root,false);
	cout << endl;
	MyBinaryTree.level(root, res_arr, 0);
	cout <<"resss"<< endl;
	MyBinaryTree.printTree("", root, false);
}