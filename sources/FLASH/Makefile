GCC_LIB = /usr/local/arm-tools/arm-2009q1/lib/gcc/arm-none-eabi/4.3.3/
C_LIB = /usr/local/arm-tools/arm-2009q1/arm-none-eabi/lib/
MY_LIBS = ../../libs/

FLASH.axf: init.o main.o
	arm-none-eabi-ld -o FLASH.axf main.o init.o -T ldscript_ram -l LPC2106 -l Utils -L $(MY_LIBS) -l c -L $(C_LIB) -l gcc -L $(GCC_LIB)
%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

clean: 
	rm -f *.o *.axf

all: clean FLASH.axf
