.PHONY: all

CXXFLAGS = -Wall -Wextra -Werror -O2
TARGET = liblogic.a
SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=.obj/%.o)
HEADERS = $(wildcard *.h)

all: .obj $(TARGET)

$(TARGET): out $(OBJ)
	ar rcs out/$(TARGET) $(OBJ)

$(OBJ): $(SRC) $(HEADERS)
	g++ -c $(filter $(@:.obj/%.o=%.cpp), $(SRC)) -o $@ $(CXXFLAGS)

.obj out:
	mkdir $@

clean:
	rm -f $(OBJ)
	rm -f $(TARGET)

