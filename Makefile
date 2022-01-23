
output: glad.o shaderClass.o VBO.o VAO.o EBO.o Textures.o Camera.o main.o
	g++ build/glad.o build/shaderClass.o build/VBO.o build/VAO.o build/EBO.o build/Textures.o build/Camera.o build/main.o -o a.out -ldl -lglfw

glad.o: glad.c
	gcc -c glad.c -ldl -lglfw -o build/glad.o

shaderClass.o: shaderClass.cpp libs/shaderClass.h
	g++ -c shaderClass.cpp -ldl -lglfw -o build/shaderClass.o

VBO.o: VBO.cpp libs/VBO.h
	g++ -c VBO.cpp -ldl -lglfw -o build/VBO.o

VAO.o: VAO.cpp libs/VAO.h
	g++ -c VAO.cpp -ldl -lglfw -o build/VAO.o

EBO.o: EBO.cpp libs/EBO.h
	g++ -c EBO.cpp -ldl -lglfw -o build/EBO.o

Textures.o: Textures.cpp libs/Textures.h
	g++ -c Textures.cpp -ldl -lglfw -o build/Textures.o

Camera.o: Camera.cpp
	g++ -c Camera.cpp -ldl -lglfw -o build/Camera.o

main.o: main.cpp
	g++ -c main.cpp -ldl -lglfw -o build/main.o

clean:
	rm a.out build/*.o

run:
	make
	./a.out

compile: glad.o shaderClass.o VBO.o VAO.o EBO.o main.o
	g++ build/glad.o build/shaderClass.o build/VBO.o build/VAO.o build/EBO.o build/Textures.o build/main.o -o a.out -ldl -lglfw
