CXX = g++

%.o : %.c 
	$(CXX) -c $< 

testMaze: testMaze.o mymaze.o 
	$(CXX) -o $@ testMaze.o mymaze.o

main: utils.o mymaze.o main.o
	$(CXX) -o $@ main.o utils.o mymaze.o

clean:
	$(RM) main mymaze testMaze *.o
