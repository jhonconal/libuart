# libuart

简单封装了Linux下操作串口的操作业务，可以简单通过三两个函数接口完成串口的打开、设置、发送、接收、关闭这几个功能。简单实用！
```c
//打开串口
int uart_open(const char *path);

//设置串口参数
int uart_config(int fd, int baud, char parity, int bsize, int stop);

//从串口读取数据
int uart_read(int fd, char *buf, int len);

//通过串口发送数据
int uart_write(int fd, const char *data, int len);

//关闭串口
int uart_close(int fd);
```
##应用例子
```c
#include <stdio.h>
#include "uart.h"

int main(void)
{
  int fd = -1;

  fd = uart_open("/dev/ttyUSB0");
  if( -1 == fd )
  {
      printf("串口打开失败！\n");
  }
  uart_config(fd, 115200, 'N', 8, 1);
  uart_write(fd, "data to send", 12);
  uart_close(fd);
  
  return 0;
}
```
