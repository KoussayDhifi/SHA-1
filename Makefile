
all:final

final: build/main.o build/readingInput.o 
	@echo "Creating executable..."
	@gcc build/readingInput.o build/main.o -o final

build/main.o: src/main.c
	@echo "Creating main.o"
	@gcc -c src/main.c -o build/main.o

build/readingInput.o: src/readingInput.c
	@echo "Creating readingInput.o";
	@gcc -c src/readingInput.c -o build/readingInput.o



clean:
	@echo "Cleaning workflow ... "
	@rm build/*.o
	@rm final
