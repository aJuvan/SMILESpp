CXX=clang++
CXXFLAGS=-std=c++2a -Wall -Wextra -Wpedantic
CXXLIBS=

sources := $(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp))


all: lib

clean:
	rm -rf obj lib bin

# Build library
lib: lib_dirs $(sources)
	${CXX} -shared ${CXXFLAGS} ${CXXLIBS} -Lobj -o lib/libSMILESpp.so obj/*.o

obj/%.o: src/%.cpp
	${CXX} -c -fPIC ${CXXFLAGS} ${CXXLIBS} -Iinc -o $@ $<

lib_dirs:
	mkdir -p obj lib

# Build tests
test: lib test_dirs
	${CXX} ${CXXFLAGS} -Iinc -Llib -lSMILESpp -o bin/test test/main.cpp

test_dirs:
	mkdir -p bin

# Run tests
run_test: test
	LD_LIBRARY_PATH=lib/:${LD_LIBRARY_PATH} bin/test
