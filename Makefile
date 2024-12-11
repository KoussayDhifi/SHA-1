
FILES = main readingInput encode decode padding calcPaddedSize functions logicalOperators

OBJ = $(FILES:%=build/%.o)

all:final

final: ${OBJ} 
	@echo "Creating executable..."
	@gcc ${OBJ} -o final

build/%.o : src/%.c
	@echo "Compiling $< into $@ ..."
	@gcc -c $< -o $@


clean:
	@echo "Cleaning workflow ... "
	@rm build/*.o
	@rm *.o 
	@rm final
