#include "uart.h"

int uart_open(const char *path)
{
	if( path )
	{
		return open(path, O_RDWR);
	}
	return -1;
}

int uart_config(int fd, int baud, char parity, int bsize, int stop)
{
	if( fd < 0 )
	{
		return -1;
	}
	else
	{
		struct termios new = {0};

		bzero(&new, sizeof(new));
		if( set_speed(&new, baud) )
		{
			return -2;
		}
		if( set_parity(&new, parity) )
		{
			return -3;
		}
		if( set_bsize(&new, bsize) )
		{
			return -4;
		}
		if( set_stop(&new, stop) )
		{
			return -5;
		}
		enable_read(&new);
		disable_flow_control(&new);
		if( set_termios(fd, &new) )
		{
			return -6;
		}
	}
	return 0;
}

int uart_read(int fd, char *buf, int len)
{
	if( fd < 0 || 0 == buf || len < 1 )
	{
		return -1;
	}
	return read(fd, buf, len);
}

int uart_write(int fd,  const char *data, int len)
{
	if( fd < 0 || 0 == data || len < 1 )
	{
		return -1;
	}
	return write(fd, data, len);
}

int uart_close(int fd)
{
	return close(fd);
}
