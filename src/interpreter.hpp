#pragma once

#include <array>
#include <cstdint>
#include "tokenizer.hpp"

typedef struct _Interpreter {
	std::array<uint8_t, 30000> tape;
	size_t instruction_ptr;
} Interpreter;

void interpret(std::vector<Token>);
Interpreter init_interpreter(void);
