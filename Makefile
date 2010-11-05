#Top level makefile 
#The secondary makefile has to be present in the src/ folder.

MAKEFILE = Makefile
DEBUG = 0

all:	build

build:
	@echo "Build started"
	cd src; make
	cd src/bin; cp pbrt exrtopng ../../scenes
	@echo "Done"

clean:
	@echo "Cleaning"
	cd src; make clean
	cd src/bin; rm pbrt

	
