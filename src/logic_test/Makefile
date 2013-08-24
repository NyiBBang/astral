.PHONY: all

CXXFLAGS = -Wall -Wextra -Werror -O2
LIBS = -llogic -lboost_unit_test_framework
LIB_PATH = -L../logic/out

all: .obj
	g++ config.cpp -o .obj/config.o $(CXXFLAGS) $(LIBS)

.obj:
	mkdir $@
