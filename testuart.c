#include <sys/ioctl.h>
#include <string.h>
#include "uart.h"

enum{
	U_MODE_FULL_422 = 0,
	U_MODE_HALF_485 = 1,
	U_MODE_FULL_232 = 2,
};
#define TIOCSERMODE	0x5460

int main(int argc, char **argv)
{
	int fd = -1;
	char *file = "/dev/ttyS0";
	struct termios old;
	struct termios new;

	if( argc > 1 )
	{
		file = argv[1];
	}

	fd = uart_open(file);
	ioctl(fd, TIOCSERMODE, U_MODE_HALF_485);

	get_termios(fd, &old);
	show_termios(&old);

	uart_config(fd, 115200, 'n', 8, 1);

	get_termios(fd, &new);
	show_termios(&new);

	while(1)
	{
		char buf[100] = {0};
		if( uart_read(fd, buf, sizeof(buf)) > 0 )
		{
			printf("buf:%s\n", buf);
			usleep(100000);
			//uart_write(fd, file, strlen(file));
		}
		usleep(1000);
		//uart_write(fd, file, strlen(file));
	}

	return 0;
}
