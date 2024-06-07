# ID: 208018028, Mail: ronimordechai70@gmail.com
# Note: When I run 'make tidy', I get strange warnings. Attempting to fix them causes a mess in the code, so I decided to leave it that way.
# Another important thing is that Valgrind is not installed correctly on my computer, so 'make valgrind' does not work. However, in this task, there should be no memory leaks because there is no dynamic allocation.

# Compiler and flags for C++
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -Wsign-conversion

# Valgrind settings for memory leak checks
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# Clang-tidy flags for code analysis
CLANG_TIDY_FLAGS = -checks='*,-fuchsia-overloaded-operator,-modernize-use-trailing-return-type,-readability-magic-numbers' -warnings-as-errors='-modernize-use-trailing-return-type,-readability-magic-numbers'

# Source files
DEMO_SOURCES = Demo.cpp catan.cpp board.cpp player.cpp development_card.cpp city.cpp settlement.cpp tile.cpp road.cpp
TEST_SOURCES = Test.cpp catan.cpp board.cpp player.cpp development_card.cpp city.cpp settlement.cpp tile.cpp road.cpp
MAIN_SOURCES = Main.cpp catan.cpp board.cpp player.cpp development_card.cpp city.cpp settlement.cpp tile.cpp road.cpp

# Object files derived from source files
DEMO_OBJECTS = $(DEMO_SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)

# Build rules
.PHONY: all clean tidy valgrind catan # Targets that don't create files

# Default target builds demo, test, and main
all: demo test main

# Build the catan target which depends on demo, main, and test
catan: demo main test

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
