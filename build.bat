@echo off
cls

del Main.exe

set DRIVE_LETTER=%1:

g++ -c -w main.cpp
g++ -c -w Enemy.cpp
g++ -c -w Encounter.cpp

g++ -o Main.exe main.o Enemy.o Encounter.o
Main Creatures.txt