# libuart

简单封装了Linux下操作串口的操作业务，可以简单通过三两个函数接口完成串口的打开、设置、发送、接收、关闭这几个功能。简单实用！
```
int uart_open(const char *path);
int uart_config(int fd, int baud, char parity, int bsize, int stop);
int uart_read(int fd, char *buf, int len);
int uart_write(int fd, const char *data, int len);
int uart_close(int fd);
```
