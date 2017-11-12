cc = clang++
link = -lGL -ldl -lglfw
config = -g -std=c++11

game : build/main.o build/glch.o build/glad.o build/shader.o build/globject.o
	$(cc) $(config) $(link) build/glad.o build/shader.o build/glch.o build/main.o build/globject.o -o game

build/main.o : src/main.cpp include/glch.h
	$(cc) $(config) -c src/main.cpp -o build/main.o

build/glch.o : src/glch.cpp include/shader.h
	$(cc) $(config) -c src/glch.cpp -o build/glch.o

build/glad.o : src/glad.c include/glch.h
	$(cc) $(config) -c src/glad.c -o build/glad.o

build/shader.o : src/shader.cpp include/shader.h
	$(cc) $(config) -c src/shader.cpp -o build/shader.o

build/globject.o : src/globject.cpp include/globject.h
	$(cc) $(config) -c src/globject.cpp -o build/globject.o 

.PHONY : clean
clean:
	rm build/* -rf
	rm game

.PHONY : run
run: game
	./game
