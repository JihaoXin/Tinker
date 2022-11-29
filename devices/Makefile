CXX = g++
CFLAGS = -o
CPP_FILES = $(wildcard *.cpp)
DEVICE_CPP_FILE = $(filter-out tinker_assembler.cpp device_test.cpp main.cpp , $(CPP_FILES))

all:$(DEVICE_CPP_FILE)
	$(CXX) $(CFLAGS) main main.cpp ${DEVICE_CPP_FILE}

device_test:$(DEVICE_CPP_FILE)
	rm device_test
	$(CXX) $(CFLAGS) device_test device_test.cpp ${DEVICE_CPP_FILE}

tinker_assembler:tinker_assembler.cpp
	$(CXX) $(CFLAGS) tinker_assembler tinker_assembler.cpp

clean:
	rm main
	rm device_test
	rm tinker_assembler