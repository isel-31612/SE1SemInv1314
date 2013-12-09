LCD.axf: init.o LCD.o main.o
	arm-none-eabi-ld -o LCD.axf LCD.o init.o main.o -T ldscript_ram -l LPC2106 -L ../../libs/ -l Utils -L ../../libs

lib: LCD.o
	arm-none-eabi-ar rcs ../../libs/libLPC2106.a LCD.o

%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

clean: 
	rm -f *.o *.axf

all: clean LCD.axf
