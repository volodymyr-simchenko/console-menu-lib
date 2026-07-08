# menu Makefile
# Variable declarations
CXX = g++
CXXFLAGS = -std=c++11 -Wall
LIBS = -lncurses
CPP = main.cpp menu.cpp

# Rule to build the executable
EXECUTABLE = main
main: $(CPP)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $^ $(LIBS)
	@echo "Built: $(EXECUTABLE)"

# Clean rule
clean:
	rm -f $(EXECUTABLE)
