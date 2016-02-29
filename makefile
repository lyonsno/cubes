CFLAGS=$(shell pkg-config --cflags glfw3)-stdlib=libc++ -std=c++11
LIBS=$(shell pkg-config --static --libs glfw3)

main: main.o camera.o shaderCreator.o cube.o light.o cubestacular.o object.o geometry.o collisionPlane.o cubeLauncher.o projectile.o
	clang++ $(CFLAGS) -o main main.o camera.o shaderCreator.o cube.o light.o cubestacular.o geometry.o object.o collisionPlane.o cubeLauncher.o projectile.o $(LIBS)

main.o: main.cpp
	clang++ $(CFLAGS) -c main.cpp $(LIBS)

cubestacular.o: cubestacular.cpp cubestacular.h
	clang++ $(CFLAGS) -c cubestacular.cpp $(LIBS)

camera.o: camera.cpp camera.h
	clang++ $(CFLAGS) -c camera.cpp $(LIBS)

shaderCreator.o: shaderCreator.cpp shaderCreator.h
	clang++ $(CFLAGS) -c shaderCreator.cpp $(LIBS)

cube.o: cube.cpp cube.h
	clang++ $(CFLAGS) -c cube.cpp $(LIBS)

light.o: light.cpp light.h
	clang++ $(CFLAGS) -c light.cpp $(LIBS)

object.o: object.cpp object.h
	clang++ $(CFLAGS) -c object.cpp $(LIBS)

geometry.o: geometry.cpp geometry.h
	clang++ $(CFLAGS) -c geometry.cpp $(LIBS)

collisionPlane.o: collisionPlane.cpp collisionPlane.h
	clang++ $(CFLAGS) -c collisionPlane.cpp $(LIBS)

cubeLauncher.o: cubeLauncher.cpp cubeLauncher.h
	clang++ $(CFLAGS) -c cubeLauncher.cpp $(LIBS)

projectile.o: projectile.cpp projectile.h
	clang++ $(CFLAGS) -c projectile.cpp $(LIBS)


clean:
	rm -rf main main.o cubestacular.o camera.o shaderCreator.o cube.o light.o geometry.o object.o collisionPlane.o cubeLauncher.o projectile.o

