.PHONY: all clean

TARGET = logic_test
SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=.obj/%.o)
HEADERS = $(wildcard *.h)
CXXFLAGS = -Wall -Wextra -Werror -O2 -std=c++0x
INCLUDE_PATH = -I..
LIBS = -llogic -lboost_unit_test_framework
LIB_PATH = -L../logic/out

all: $(TARGET)

$(TARGET): out $(OBJ)
	g++ $(OBJ) -o out/$@ $(CXXFLAGS) $(LIB_PATH) $(LIBS)

$(OBJ): .obj $(SRC) $(HEADERS)
	g++ -c $(filter $(@:.obj/%.o=%.cpp), $(SRC)) -o $@ $(CXXFLAGS) $(INCLUDE_PATH)

.obj out:
	mkdir $@

clean:
	rm -f $(OBJ)
	rm -f $(TARGET)

