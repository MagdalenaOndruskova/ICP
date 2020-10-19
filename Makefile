# Project: ICP project
# File: Makefile
# Title: Public Transport Map simulator 
# Description: This file uses qmake to generete all files necessaire for project 
# Authors: Magdalena Ondruskova (xondru16@stud.fit.vutbr.cz)

compile: update
	make -f QMAKEFILE 

run: compile
	./mhdsimulator

update: src/icp.pro 
	qmake -o QMAKEFILE src/icp.pro 

doxygen:
	doxygen doc/Doxyfile 

clean:
	rm -f mhdsimulator *.o QMAKEFILE moc_* qrc_myRes.cpp ui_mainwindow.h

pack:
	zip -r xondru16-xhradi16-60-40.zip src examples README.txt README.md Makefile doc/Doxyfile

