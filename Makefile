main.o: main.cpp table.txt
  g++ -c main.cpp
  
main: main.o
  g++ main.o -o main
