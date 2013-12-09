SClk.axf: init.o SClk.o
	arm-none-eabi-ld -o SClk.axf SClk.o init.o -T ldscript_ram -l LPC2106 -L ../../libs/ -l Utils -L ../../libs/

lib: SClk.o
	arm-none-eabi-ar rcs ../../libs/libLPC2106.a SClk.o -l Utils -L ../../libs/

%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

test: init.o SClk.o main.o
	arm-none-eabi-ld -o Test.axf main.o SClk.o init.o -T ldscript_ram -l led -l Utils -l PLL -L ../../libs/

clean: 
	rm -f *.o *.axf

all: clean matrix.axf
