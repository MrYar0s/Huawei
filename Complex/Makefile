CXX = g++
STAND = -std=c++11
OPTS = -O2 -Wall
SOURCE_PATH = source/complex.cpp
TEST_PATH = tests/test.cpp
TARGET = test

.PHONY: all install uninstall clean

all: $(TARGET)
test.o: $(TEST_PATH)
			$(CXX) -c -o test.o $(TEST_PATH)
complex.o: $(SOURCE_PATH)
			$(CXX) -c -o complex.o $(SOURCE_PATH)
$(TARGET): test.o complex.o
			$(CXX) -o $(TARGET) test.o complex.o
install:
			install $(TARGET)
uninstall:
			rm -rf $(TARGET)
clean:
			rm -rf *.o