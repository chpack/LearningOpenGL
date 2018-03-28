# cc = clang++
cc = clang++
link = -ldl -lglad -lglfw -lstb_image
config = -g -std=c++11

game : build/main.o  build/manager.o build/globj.o
	$(cc) $(config) build/main.o build/manager.o build/globj.o -o game $(link)

build/main.o : src/game.cpp
	$(cc) $(config) -c src/game.cpp -o build/main.o

build/manager.o : src/manager.cpp include/manager.hpp
	$(cc) $(config) -c src/manager.cpp -o build/manager.o

build/globj.o : src/globj.cpp include/globj.hpp
	$(cc) $(config) -c src/globj.cpp -o build/globj.o

.PHONY : clean
clean:
	rm build/* -rf
	rm game

.PHONY : run
run: game
	./game

