#include "tokenizer.hpp"

std::vector<Token> tokenize(std::string input)
{
	std::vector<char> chars(input.begin(), input.end());
	std::vector<Token> tokens;

	for (auto &c : chars) {
		switch (c) {
		case '>':
			tokens.push_back(Token::INCR_PTR);
			break;
		case '<':
			tokens.push_back(Token::DECR_PTR);
			break;
		case '+':
			tokens.push_back(Token::INCR);
			break;
		case '-':
			tokens.push_back(Token::DECR);
			break;
		case '.':
			tokens.push_back(Token::OUTPUT);
			break;
		case ',':
			tokens.push_back(Token::INPUT);
			break;
		case '[':
			tokens.push_back(Token::JEZ);
			break;
		case ']':
			tokens.push_back(Token::JNZ);
			break;
		}
	}

	return tokens;
}
