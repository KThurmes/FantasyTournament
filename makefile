#target: dependencies
#	rule to build
#must use tab for rules

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
OBJS = Die.o getNumberBetween.o Vampire.o main.o Battle.o Barbarian.o BlueMan.o Medusa.o HarryPotter.o Tournament.o Node.o DoubleLinkedList.o Menu.o
SRCS = *.cpp
HEADERS = *.hpp
#LDFLAGS = -lboost_date_time (any libraries you want to link)

proj4: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o proj4

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o proj4

valgrind:
	valgrind -v --leak-check=full proj4
	#--leak-check=full
	#--v --track-origin=yes