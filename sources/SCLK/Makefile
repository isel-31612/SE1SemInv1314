SClk.axf: init.o SClk.o
	arm-none-eabi-ld -o SClk.axf SClk.o init.o -T ldscript_ram -l LPC2106 -l Utils -L ../../libs/

%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

lib: SClk.o
	arm-none-eabi-ar rcs ../../libs/libLPC2106.a SClk.o
	
test: init.o SClk.o main.o
	arm-none-eabi-ld -o Test.axf main.o SClk.o init.o -T ldscript_ram -l led -l LPC2106 -l Utils -L ../../libs/

clean: 
	rm -f *.o *.axf

all: clean matrix.axf
