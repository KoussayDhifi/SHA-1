
FILES = main readingInput encode decode padding calcPaddedSize functions logicalOperators hashComputation

FLAG = -lm

OBJ = $(FILES:%=build/%.o)

all:final

final: ${OBJ} 
	@echo "Creating executable..."
	@gcc -fno-stack-protector  ${OBJ} -o final ${FLAG}

build/%.o : src/%.c
	@echo "Compiling $< into $@ ..."
	@gcc -fno-stack-protector -c  $< -o $@ ${FLAG}


clean:
	@echo "Cleaning workflow ... "
	@rm build/*.o
	@rm *.o 
	@rm final
