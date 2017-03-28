CXX=g++-5
CXXFLAGS=-std=c++14 -Wall -MMD 
OBJECTS=main.o item.o Potion.o Treasure.o cell.o chamber.o character.o display.o door.o enemy.o floor.o normalCell.o passage.o pc.o spawn.o stair.o wall.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGES} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm *.o
.PHONY: clean
