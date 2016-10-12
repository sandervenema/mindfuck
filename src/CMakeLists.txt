set(CMAKE_BUILD_TYPE Release)
set(COMMON_FLAGS "-Wall -Werror -Wextra -pedantic --std=c++1y")
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3 ${COMMON_FLAGS} ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -s ${COMMON_FLAGS} ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")

add_executable(mindfuck
    tokenizer.cpp
    tokenizer.hpp
    interpreter.hpp
    interpreter.cpp
    main.cpp
)
