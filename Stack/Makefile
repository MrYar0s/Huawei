CXX = g++
STAND = -std=c++11
OPTS = -Wall
TARGET = test
SOURCE_PATH = source/stack.cpp
TEST_PATH = tests/test.cpp
INCLUDE_PATH = include/stack.hpp

.PHONY: all install clean uninstall

all: $(TARGET)
clean:
	rm -rf *.o
stack.o: $(SOURCE_PATH)
	$(CXX) -c -o stack.o $(SOURCE_PATH)
test.o: $(TEST_PATH)
	$(CXX) -c -o test.o $(TEST_PATH)
$(TARGET): stack.o test.o $(INCLUDE_PATH)
	$(CXX) -o test $(STAND) $(OPTS) test.o stack.o
install:
	install $(TARGET)
uninstall:
	rm -rf $(TARGET)