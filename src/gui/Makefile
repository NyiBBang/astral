TARGET = rts_game
SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=.obj/%.o)
HEADERS = $(wildcard *.h)
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++0x
INCLUDE_PATH = -I..
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lGLEW -llogic
LIB_PATH = -L../logic/out
LD_PATH = -Wl,-rpath /usr/local/lib -Wl,-rpath /usr/lib -Wl,-rpath /usr/lib64

all: $(TARGET)

$(TARGET): out $(OBJ)
	g++ $(OBJ) -o out/$@ $(CXXFLAGS) $(LIB_PATH) $(LIBS) $(LD_PATH)

$(OBJ): .obj $(SRC) $(HEADERS)
	g++ -c $(filter $(@:.obj/%.o=%.cpp), $(SRC)) -o $@ $(CXXFLAGS) $(INCLUDE_PATH)

.obj out:
	mkdir $@

clean:
	rm -f $(OBJ)
	rm -f $(TARGET)

