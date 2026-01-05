# The makefile exists just because it's easier for me to type "make"
# instead of use the CMake commands. Cope.

compile:
	cd build && make

run:
	cd build && ./jackboxmodtoolpack

rebuild: setup compile

setup: clean
	mkdir build
	cd build && cmake ..

clean:
	rm -rf build
