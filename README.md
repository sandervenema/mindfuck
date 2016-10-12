# Mindfuck

**Mindfuck** is a Brainfuck interpreter written in C++. This is just a toy project
for me to try and get more familiar with C++, so no doubt there's a lot of room
for improvement. Feel free to make suggestions.

[Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) is an esoteric programming
language, noted for its extreme minimalism. It has 8 simple instructions plus
an instruction pointer. Because of its simplicity it's a good target to try and
learn something more about C++ as we go along.

Currently, the programme supports input from stdin and outputs to stdout for
simplicity. File handling will be added later.

## Interpreting process

Interpreting is done using the following phases:

1. First we get the input
2. Tokenise the source code
3. Read all the tokens in order
4. For each token, translate it to the appropriate operation(s)

## Building

This project requires [CMake](https://cmake.org/). Building can be done as follows:

    $ git clone https://github.com/sandervenema/mindfuck.git
    $ cd mindfuck
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

The binary will be put in `build/src/mindfuck`. For instance, to test it, we can run:

    $ cat examples/hello.b | ./build/src/mindfuck
    Hello World!

## Brainfuck instruction set

For reference, here is the instruction set of Brainfuck.

    > 	increment the data pointer (to point to the next cell to the right).
    < 	decrement the data pointer (to point to the next cell to the left).
    +	increment (increase by one) the byte at the data pointer.
    -   decrement (decrease by one) the byte at the data pointer.
    . 	output the byte at the data pointer.
    , 	accept one byte of input, storing its value in the byte at the data
        pointer.
    [ 	if the byte at the data pointer is zero, then instead of moving the
        instruction pointer forward to the next command, jump it forward to the
        command after the matching ] command.
    ] 	if the byte at the data pointer is nonzero, then instead of moving the
        instruction pointer forward to the next command, jump it back to the
        command after the matching [ command.

## License

Mindfuck is MIT licensed. See the LICENSE file for more information.
