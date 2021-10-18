#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int string_with_palindromes(const string part_of_StringForTheInput);

void FindRightStrings(const string StringForTheInput, vector<int>& array_for_the_right_strings);

int string_with_one_palindrome(const vector<int> arr3);

void openFiles(ifstream& file1, ofstream& file2, ofstream& file3) {
	if (file1.is_open() && file2.is_open() && file3.is_open())
		cout << "Starting programm..." << endl << endl;
	else
		cout << "some file isn't opened" << endl << "ERROR";
}

void closeFiles(ifstream& file1, ofstream& file2, ofstream& file3) {
	file3.close();
	file2.close();
	file1.close();
	if (file1.is_open() || file2.is_open() || file3.is_open())
		cout << "some file isn't closed" << endl << "ERROR" << endl;
	else
		cout << "Programm finished" << endl;
}

void solution(string& StringForTheInput, ofstream& text_of_the_first_output, ofstream& text_of_the_second_output) {
	StringForTheInput.push_back('.');
	vector<int>array_for_the_right_strings;
	FindRightStrings(StringForTheInput, array_for_the_right_strings);
	if (string_with_one_palindrome(array_for_the_right_strings))
		text_of_the_first_output << StringForTheInput << '\n';
	else
		text_of_the_second_output << StringForTheInput << '\n';
}

int main() {
	ifstream text_for_lab5("for input.txt");
	ofstream text_of_the_first_output("for the first output.txt");
	ofstream text_of_the_second_output("for the second output.txt");
	string StringForTheInput;
	openFiles(text_for_lab5, text_of_the_first_output, text_of_the_second_output);
	while (getline(text_for_lab5, StringForTheInput))
		solution(StringForTheInput, text_of_the_first_output, text_of_the_second_output);
	closeFiles(text_for_lab5, text_of_the_first_output, text_of_the_second_output);
	return 0;
}

int string_with_palindromes(const string part_of_StringForTheInput) {
	int check_word = part_of_StringForTheInput.size();
	bool  ch = 1;
	for (int j = 0; j < (part_of_StringForTheInput.size() / 2) + 1; j++) {
		check_word--;
		if (part_of_StringForTheInput[j] != part_of_StringForTheInput[check_word] || part_of_StringForTheInput[j] == ' ') {
			ch = 0;
			break;
		}
	}
	return ch;
}

void FindRightStrings(const string Input, vector<int>& array_for_the_right_strings) {
	int k = 0;
	for (int i = 0; i < Input.size(); i++) {
		if ((Input[i] == ' ' && Input[i + 1] != ' ') || Input[i] == '.' && Input[i + 1] != '.') {
			string part_of_StringForTheInput;
			part_of_StringForTheInput.append(Input, k, i - k);
			if (string_with_palindromes(part_of_StringForTheInput))
				array_for_the_right_strings.push_back(1);
			else
				array_for_the_right_strings.push_back(2);
			k = i + 1;
		}
	}
}

int string_with_one_palindrome(const vector<int> arr3) {
	int b = 0;
	for (int i = 0; i < arr3.size(); i++) {
		if (arr3[i] == 1)
			b++;
	}
	if (b == 1)
		return 1;
	else
		return 0;
}