utils.axf: utils.o
	arm-none-eabi-ld -o utils.axf utils.o
	
lib: utils.o
	arm-none-eabi-ar rcs ../../libs/libUtils.a utils.o

%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

clean: 
	rm -f *.o *.axf

all: clean utils.axf
