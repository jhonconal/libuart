CC := gcc
CC := arm-linux-gcc

uarttest: *.c
	$(CC) *.c -o $@

copy:
	cp uarttest /srv/tftp/

clean:
	@rm -vf uarttest
