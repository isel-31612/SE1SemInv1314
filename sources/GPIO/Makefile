testGpio.axf: main.o init.o
	arm-none-eabi-ld -o tapcs.axf GPIO.o main.o init.o -T ldscript_ram

lib: GPIO.o
	arm-none-eabi-ar rcs ../../libs/libLPC2106.a GPIO.o
	
%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

clean: 
	rm -f *.o *.axf

all: clean testGpio.axf
