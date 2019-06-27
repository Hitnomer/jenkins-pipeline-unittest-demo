BINARY = testBasicMath
CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= CBasicMath.cpp
OBJM = $(SRCM:.cpp=.o)
LINKFLAGS= -lcppunit

$(BINARY): TestBasicMath.cpp $(OBJM)
	$(CXX) -v $(CXXFLAGS) -o $@ TestBasicMath.cpp $(OBJM) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)

# Default compile

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -fv $(BINARY)
	rm -fv *.o

.PHONY: clean
