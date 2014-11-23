#ifndef _SERIAL_H
#define _SERIAL_H
#include "type.h"
typedef bool (*serial_parse_func)(void);
void serial_init(void);
re_error_enum serial_creat(char* dev_name_ptr, int baud_rate, int* fd_ptr);
re_error_enum serial_write(int fd, unsigned char *buf_ptr, int buf_size);
re_error_enum serial_read(int fd, int max_size, unsigned char *buf_ptr, int* buf_size_ptr);
#endif
