CXXFLAGS = $(shell wx-config --cxxflags)
CFLAGS = $(shell wx-config --cflags)
LIBS = $(shell wx-config --libs)

.PHONY: _DEFAULT reinit test
_DEFAULT: full-build

init:
	mkdir -p bin/obj
clean:
	rm -rf bin

reinit: clean init

full-build: src/App.cpp
	g++ src/App.cpp $(LIBS) $(CFLAGS) -o bin/App.out

test: full-build
	./bin/App.out