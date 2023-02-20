# Makefile for C++ program 

# Compiler and flags 

CXX = g++
CXXFLAGS = 
# Target and dependencies 
TARGET = main 
OBJS = main.o atm.o depot/csvDepot.o depot/jsonDepot.o depot/sqliteDepot.o

# Build and run 
all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -l sqlite3

%.o: %.cpp	
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
# Cleanup 
clean:
	rm -f $(TARGET) $(OBJS)
