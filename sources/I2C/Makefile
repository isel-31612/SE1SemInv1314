GCC_LIB = /usr/local/arm-tools/arm-2009q1/lib/gcc/arm-none-eabi/4.3.3/
C_LIB = /usr/local/arm-tools/arm-2009q1/arm-none-eabi/lib/
MY_LIBS = ../../libs/

I2C.axf: init.o $(MY_LIBS)libUtils.a I2C.o
	arm-none-eabi-ld -o I2C.axf init.o I2C.o -T ldscript_ram -l LPC2106 -l Utils -L $(MY_LIBS)

%.o: %.c
	arm-none-eabi-gcc -g -c ${<} -o ${@}

%.o: %.S
	arm-none-eabi-as -g ${<} -o ${@}

lib: I2C.o
	arm-none-eabi-ar rcs ../../libs/libLPC2106.a I2C.o

test: init.o main.o I2C.o
	arm-none-eabi-ld -o Test.axf init.o I2C.o main.o -T ldscript_ram -l LPC2106 -l Utils -L $(MY_LIBS) -l c -L $(C_LIB) -l gcc -L $(GCC_LIB)

clean: 
	rm -f *.o *.axf
