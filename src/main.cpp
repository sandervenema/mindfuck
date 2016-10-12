#include <string>
#include <iostream>

#include "tokenizer.hpp"
#include "interpreter.hpp"

int main()
{
	std::string source;

	// TODO add command-line handling and opening files

	// Get the source from stdin
	for (std::string line; std::getline(std::cin, line);) {
		source += line;
	}

	// Tokenize and interpret
	interpret(tokenize(source));
}
