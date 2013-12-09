matrix.axf: init.o ../../libs/libGPIO.a matrix.o
	arm-none-eabi-ld -o matrix.axf matrix.o init.o -T ldscript_ram -l GPIO -L ../../libs/

%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

clean: 
	rm -f *.o *.axf

all: clean matrix.axf
