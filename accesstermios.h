#ifndef __ACCESS_TERMIOS_H__
#define __ACCESS_TERMIOS_H__

#include <termios.h>
#include <unistd.h>

void show_termios(const struct termios *s);

int get_termios(int fd, struct termios *s);
int set_termios(int fd, const struct termios *s);

int baud_to_speed(int baud);
int get_speed(const struct termios *s);
int get_ispeed(const struct termios *s);
int get_ospeed(const struct termios *s);
int get_bsize(const struct termios *s);
char get_parity(const struct termios *s);
int get_stop(const struct termios *s);
int readable(const struct termios *s);

int speed_to_baud(int speed);
int set_speed(struct termios *s, int speed);
int set_ispeed(struct termios *s, int speed);
int set_ospeed(struct termios *s, int speed);
int set_bsize(struct termios *s, int bsize);
int set_parity(struct termios *s, char parity);
int set_stop(struct termios *s, int stop);
int enable_read(struct termios *s);
int disable_read(struct termios *s);
int enable_flow_control(struct termios *s);
int disable_flow_control(struct termios *s);

#endif//__ACCESS_TERMIOS_H__
