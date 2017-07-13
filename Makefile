uarttest: *.c
	arm-linux-gcc *.c -o $@

clean:
	@rm -vf uarttest
