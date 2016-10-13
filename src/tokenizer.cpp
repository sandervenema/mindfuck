#include <map>

#include "tokenizer.hpp"

std::vector<Token> tokenize(std::string input)
{
	std::map<char, Token> map = {
		{'>', Token::INCR_PTR},
		{'<', Token::DECR_PTR},
		{'+', Token::INCR},
		{'-', Token::DECR},
		{'.', Token::OUTPUT},
		{',', Token::INPUT},
		{'[', Token::JEZ},
		{']', Token::JNZ}
	};

	std::vector<char> chars(input.begin(), input.end());
	std::vector<Token> tokens;

	for (auto &c : chars) {
		if (map.find(c) != map.end()) {
			tokens.push_back(map[c]);
		}
	}

	return tokens;
}
