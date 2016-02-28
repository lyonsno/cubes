CFLAGS=$(shell pkg-config --cflags glfw3)
LIBS=$(shell pkg-config --static --libs glfw3)

main: main.o camera.o shaderCreator.o cube.o light.o cubestacular.o object.o geometry.o
	g++ $(CFLAGS) -o main main.o camera.o shaderCreator.o cube.o light.o cubestacular.o geometry.o object.o $(LIBS)

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp $(LIBS)

cubestacular.o: cubestacular.cpp
	g++ $(CFLAGS) -c cubestacular.cpp $(LIBS)

camera.o: camera.cpp camera.h
	g++ $(CFLAGS) -c camera.cpp $(LIBS)

shaderCreator.o: shaderCreator.cpp shaderCreator.h
	g++ $(CFLAGS) -c shaderCreator.cpp $(LIBS)

cube.o: cube.cpp cube.h
	g++ $(CFLAGS) -c cube.cpp $(LIBS)

light.o: light.cpp light.h
	g++ $(CFLAGS) -c light.cpp $(LIBS)

object.o: object.cpp object.h
	g++ $(CFLAGS) -c object.cpp $(LIBS)

geometry.o: geometry.cpp geometry.h
	g++ $(CFLAGS) -c geometry.cpp $(LIBS)

clean:
	rm -rf main main.o cubestacular.o camera.o shaderCreator.o cube.o light.o geometry.o object.o

