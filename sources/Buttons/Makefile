all: init.o Buttons.o main.o
	arm-none-eabi-ld -o Buttons.axf Buttons.o init.o main.o -T ldscript_ram -l LPC2106 -l Utils -L ../../libs

lib: Buttons.o
	arm-none-eabi-ar rcs ../../libs/libLPC2106.a Buttons.o

%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

clean: 
	rm -f *.o *.axf
