CXXFLAGS = -Wall -Wextra -Werror -O2
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lGLEW
LD_PATH = -Wl,-rpath /usr/local/lib -Wl,-rpath /usr/lib

all:
	g++ main.cpp -o gui $(CXXFLAGS) $(LIBS) $(LD_PATH)
