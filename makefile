#Kompiliatoriaus nustatymai
CXX = g++
CXXFLAGS = -std=c++23 -Wall -Iheaders

SRC = $(wildcard source/*.cpp)

TARGET = run

all: $(TARGET)

# Compile all source files into the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f run

