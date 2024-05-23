#//ID: 208018028, Mail: ronimordechai70@gmail.com
#**note : when i do the commend 'make tidy' i get strange warnings and when i try to fux them it is just caused a mess in the code, so i decided to leave it that way. 
# Another importent thing is that the valgrind not install correctly to me computer so its not working when i am wirte- 'make valdgind', but in this task there is no need to be a memoery leak becouse there is no dynamic allocation.

# Compiler and flags for C++
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -Wsign-conversion

# Valgrind settings for memory leak checks
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# Clang-tidy flags for code analysis
CLANG_TIDY_FLAGS = -checks='*,-fuchsia-overloaded-operator,-modernize-use-trailing-return-type,-readability-magic-numbers' -warnings-as-errors='-modernize-use-trailing-return-type,-readability-magic-numbers'

# Source files
DEMO_SOURCES = Demo.cpp catan.cpp board.cpp player.cpp development_card.cpp construction.cpp city.cpp settlement.cpp tile.cpp raod.cpp
TEST_SOURCES = Test.cpp catan.cpp board.cpp player.cpp development_card.cpp construction.cpp city.cpp settlement.cpp tile.cpp raod.cpp
MAIN_SOURCES = Main.cpp catan.cpp board.cpp player.cpp development_card.cpp construction.cpp city.cpp settlement.cpp tile.cpp raod.cpp

# Object files derived from source files
DEMO_OBJECTS = $(DEMO_SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)

# Build rules
.PHONY: all clean tidy valgrind  # Targets that don't create files

# Default target builds both demo and test
catan: demo test main

# Build the demo executable
demo: $(DEMO_OBJECTS)
	$(CXX) $(CXXFLAGS) -o demo $(DEMO_OBJECTS)

# Build the main executable
main: $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o main $(MAIN_OBJECTS)

# Build the test executable
test: $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o test $(TEST_OBJECTS)

# Compile individual object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executables
clean:
	rm -f *.o demo test main

# Tidy up the codebase using clang-tidy
tidy:
	@echo "Running clang-tidy..."
	clang-tidy $(DEMO_SOURCES) $(CLANG_TIDY_FLAGS) --fix --quiet
	clang-tidy $(MAIN_SOURCES) $(CLANG_TIDY_FLAGS) --fix --quiet
	clang-tidy $(TEST_SOURCES) $(CLANG_TIDY_FLAGS) --fix --quiet

# Run Valgrind to check for memory leaks
valgrind:
	valgrind $(VALGRIND_FLAGS) ./demo
