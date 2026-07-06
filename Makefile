# menu Makefile
# Variable declarations
CXX = g++
CXXFLAGS = -std=c++11 -Wall
LIBS = -lncurses
CPP = main.cpp menu.cpp

# Version
VERSION := 1.2.1

# Define compiler flag with the version
CPPFLAGS := -DVERSION=\"$(VERSION)\"

# Rule to build the executable
EXECUTABLE = main_$(VERSION)
main: $(CPP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $(EXECUTABLE) $^ $(LIBS)
	@echo "Сборка завершена! Исполняемый файл: $(EXECUTABLE)"

# Clean rule
clean:
	rm -f $(EXECUTABLE)
