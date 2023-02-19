# Makefile for C++ program 

# Compiler and flags 

CXX = g++
CXXFLAGS = 
# Target and dependencies 
TARGET = main 
OBJS = main.o atm.o depot/csvDepot.o depot/jsonDepot.o

# Build and run 
all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

# Cleanup 
clean:
	rm -f $(TARGET) $(OBJS)