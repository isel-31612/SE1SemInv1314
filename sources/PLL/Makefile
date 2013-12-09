PLL.axf: init.o PLL.o main.o
	arm-none-eabi-ld -o PLL.axf PLL.o init.o main.o -T ldscript_ram -l led -L ../../libs/

lib: PLL.o
	arm-none-eabi-ar rcs ../../libs/libLPC2106.a PLL.o

%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

clean: 
	rm -f *.o *.axf

all: clean PLL.axf
