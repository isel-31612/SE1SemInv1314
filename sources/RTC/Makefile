RTC.axf: init.o main.o ../../libs/libUtils.a RTC.o
	arm-none-eabi-ld -o RTC.axf RTC.o init.o main.o -T ldscript_ram -l Utils -l PLL -L ../../libs/

%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

test: init.o main.o RTC.o
	arm-none-eabi-ld -o Test.axf main.o RTC.o init.o -T ldscript_ram -l led -l LPC2106 -l Utils -L ../../libs

lib: RTC.o
	arm-none-eabi-ar rcs ../../libs/libLPC2106.a RTC.o

clean: 
	rm -f *.o *.axf

all: clean RTC.axf
