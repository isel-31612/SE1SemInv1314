FLASH.axf: init.o main.o
	arm-none-eabi-ld -o FLASH.axf init.o main.o -T ldscript_ram

%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

clean: 
	rm -f *.o *.axf

all: clean FLASH.axf
