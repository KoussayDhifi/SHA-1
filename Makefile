
all:final

final: build/main.o build/readingInput.o build/encode.o build/decode.o 
	@echo "Creating executable..."
	@gcc build/readingInput.o build/main.o  build/encode.o build/decode.o -o final

build/main.o: src/main.c
	@echo "Creating main.o"
	@gcc -c src/main.c -o build/main.o

build/readingInput.o: src/readingInput.c
	@echo "Creating readingInput.o";
	@gcc -c src/readingInput.c -o build/readingInput.o


build/encode.o : src/encode.c
	@echo "Creating encode.c";
	@gcc -c src/encode.c -o build/encode.o

build/decode.o : src/decode.c
	@echo "Creating decode.c";
	@gcc -c src/decode.c -o build/decode.o


clean:
	@echo "Cleaning workflow ... "
	@rm build/*.o
	@rm final
