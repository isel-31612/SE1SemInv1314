tapcs.axf: blinkLED.o init.o delay.o
	arm-none-eabi-ld -o tapcs.axf blinkLED.o init.o delay.o -Tldscript_ram -lled -L ../../libs

blinkLED.o: blinkLED.c
	arm-none-eabi-gcc -g -c blinkLED.c -o blinkLED.o

delay.o: delay.S
	arm-none-eabi-as -g delay.S -o delay.o

init.o: init.S
	arm-none-eabi-as -g init.S -o init.o

clean: 
	rm -f *.o *.axf

all: clean tapcs.axf

