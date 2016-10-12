#pragma once

#include <vector>
#include <string>

enum class Token {
	INCR_PTR,	// >
	DECR_PTR,	// <
	INCR,		// +
	DECR,		// -
	OUTPUT,		// .
	INPUT,		// ,
	JEZ,		// [
	JNZ,		// ]
};

std::vector<Token> tokenize(std::string);
