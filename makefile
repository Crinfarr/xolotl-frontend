CXXFLAGS = $(shell wx-config --cxxflags)
CFLAGS = $(shell wx-config --cflags)
LIBS = $(shell wx-config --libs)

.PHONY: _DEFAULT reinit
_DEFAULT: full-build

init:
	mkdir -p bin/obj
clean:
	rm -rf bin

reinit: clean init

full-build: src/App.cpp
	g++ src/App.cpp $(LIBS) $(CFLAGS) -o bin/App.out