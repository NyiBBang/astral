.PHONY: all clean

CXXFLAGS = -Wall -Wextra -Werror -O2 -std=c++0x
TARGET = liblogic.a
SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=.obj/%.o)
HEADERS = $(wildcard *.h)

all: $(TARGET)

$(TARGET): out $(OBJ)
	ar rcs out/$@ $(OBJ)

$(OBJ): .obj $(SRC) $(HEADERS)
	g++ -c $(filter $(@:.obj/%.o=%.cpp), $(SRC)) -o $@ $(CXXFLAGS)

.obj out:
	mkdir $@

clean:
	rm -f $(OBJ)
	rm -f $(TARGET)

