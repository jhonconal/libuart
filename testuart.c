#include <string.h>
#include "uart.h"

int main(int argc, char **argv)
{
	int fd = -1;
	char *file = "/dev/ttyS0";

	if( argc > 1 )
	{
		file = argv[1];
	}

	fd = uart_open(file);
	uart_config(fd, 115200, 'n', 8, 1);
	while(1)
	{
		uart_write(fd, file, strlen(file));
		usleep(1000);
	}

	return 0;
}
