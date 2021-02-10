CXX=clang++
CXXFLAGS=-std=c++2a -Wall -Wextra -Wpedantic
CXXLIBS=

all: lib

clean:
	rm -rf obj lib bin

# Build library
lib: | lib_dirs lib/libSMILESpp.so

lib_dirs:
	mkdir -p obj lib

lib/libSMILESpp.so: obj/SMILESpp.o
	${CXX} -shared ${CXXFLAGS} ${CXXLIBS} -Lobj -o $@ $<

obj/SMILESpp.o: src/SMILESpp.cpp
	${CXX} -c ${CXXFLAGS} ${CXXLIBS} -Iinc -o $@ $<

# Build tests
test: | lib test_dirs bin/test

test_dirs:
	mkdir -p bin

bin/test: test/main.cpp
	${CXX} ${CXXFLAGS} -Iinc -Llib -lSMILESpp -o $@ $<

# Run tests
run_test: test
	LD_LIBRARY_PATH=lib/:${LD_LIBRARY_PATH} bin/test
