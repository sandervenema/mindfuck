#include <iostream>
#include <algorithm>

#include "interpreter.hpp"
#include "tokenizer.hpp"

void interpret(std::vector<Token> tokens)
{
	Interpreter i = init_interpreter();

	for (size_t j = 0; j < tokens.size(); j++) {
		auto& token = tokens[j];

		if (token == Token::INCR_PTR) {
			i.instruction_ptr++;
		} else if (token == Token::DECR_PTR) {
			i.instruction_ptr--;
		} else if (token == Token::INCR) {
			i.tape.at(i.instruction_ptr) += 1;
		} else if (token == Token::DECR) {
			i.tape.at(i.instruction_ptr) -= 1;
		} else if (token == Token::OUTPUT) {
			std::cout << i.tape[i.instruction_ptr];
		} else if (token == Token::INPUT) {
			uint8_t input_byte;
			std::cin.clear();
			std::cin >> input_byte;
			i.tape[i.instruction_ptr] = input_byte;
		} else if (token == Token::JEZ) {
			if (i.tape.at(i.instruction_ptr) == 0) {
				// jump to after matching ]. This will be the FIRST ] we
				// find in the token input stream starting here.
				auto current = tokens.begin() + j;
				auto it = std::find(current, tokens.end(), Token::JNZ);
				j = it - tokens.begin();
			}
		} else if (token == Token::JNZ) {
			if (i.tape.at(i.instruction_ptr) != 0) {
				// jump to after matching [. This will be the FIRST [ we
				// find in the input token stream before this index.
				auto current = tokens.begin() + j;
				auto it = std::find(tokens.begin(), current, Token::JEZ);
				j = it - tokens.begin();
			}
		}
	}
}

Interpreter init_interpreter(void)
{
	Interpreter i = {{{}}, 0};
	return i;
}
