CXX = g++
STAND = -std=c++11
OPTS = -Wall
TARGET = test
SOURCE_PATH = include/stack-impl.hpp
TEST_PATH = tests/test.cpp
INCLUDE_PATH = include/stack.hpp

.PHONY: all install clean uninstall

all: $(TARGET)
clean:
	rm -rf *.o
test.o: $(TEST_PATH)
	$(CXX) -c -o test.o $(TEST_PATH)
$(TARGET): test.o $(INCLUDE_PATH)
	$(CXX) -o test $(STAND) $(OPTS) test.o
install:
	install $(TARGET)
uninstall:
	rm -rf $(TARGET)
