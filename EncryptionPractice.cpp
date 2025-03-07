// EncryptionPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

// this is the encryption key:
std::vector<std::pair<int, int>> key = { {1, 0}, {2, 1}, {3, 2}, {4, 1}, {0, 3} };

std::vector<std::string> splitSentence(std::string);
std::string shiftWord(std::string, std::pair<int, int>);

int main()
{

	// this is the Test text phrase:
	std::string message = "This is a test sentence to show how the algorithm works";

	// split the sentences into words and store them in a vector of strings
	std::vector<std::string> all_words = splitSentence(message);

	// this is the encryption key:
	std::vector<std::pair<int, int>> key_vector = { {1, 0}, {2, 1}, {3, 2}, {4, 1}, {0, 3} };

	// interduce a variable to store the shifted words sentence
	std::vector<std::string> shifted_sentence;

	// actual operation of shifting the letters in the words
	for (const auto& word : all_words)
		shifted_sentence.push_back(shiftWord(word, (word.length() > 4) ? key_vector[4] : key_vector[(word.length() - 1)]));

	// print out the results.
	for (const auto& word : shifted_sentence)
		std::cout << word << " ";
}

std::vector<std::string> splitSentence(std::string message)
{
	// ss_sentence is the string stream object to store the sentence
	std::stringstream ss_sentence(message);

	// a variable to hold each word
	std::string individual_word;

	// this variable holds all words in a splitted sentence
	std::vector<std::string> all_words;

	// take words from the sentence
	while (ss_sentence >> individual_word)
		all_words.push_back(individual_word);

	return all_words;

}

std::string shiftWord(std::string word, std::pair<int, int> key)
{
	// shift the letters in the word accoring to the key
	key.second = key.second % word.length();
	return word.substr(key.second) + word.substr(0, key.second);
}
