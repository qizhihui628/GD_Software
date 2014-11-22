/*
 * main.c
 *
 *  Created on: Nov 22, 2014
 *      Author: jeqi
 */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>


int COM2_fd; 		/* input sources 1 and 2 */

int Cooling_Module_Polling(int Cooling_Addr)
{
	int i;
	unsigned char buf_rx[128];
	int buf_counter;
	char buf_ptr[] = {0x01,0x0f,0x00,0x00,0x00,0x04,0x01,0x00,0x3e,0x96};
	serial_write(COM2_fd,buf_ptr,(sizeof(buf_ptr)/sizeof(buf_ptr[0])));
	if(serial_read(COM2_fd,128,buf_rx,&buf_counter) == RE_SUCCESS)
	{
		for(i=0;i<buf_counter;i++)
		{
			printf("%x\r\n",buf_rx[i]);
		}
	}
	return EXIT_SUCCESS;
}

int main(void)
{


	re_error_enum re_val = RE_SUCCESS;
	int loop = 1; 	/* loop while TRUE */
	serial_init();	/* open_input_source opens a device, sets the port correctly, and returns a file descriptor */
					/*open_input_source*/

	if (serial_creat("/dev/ttyS1", 9600,&COM2_fd) != RE_SUCCESS)	/*Init ttyS2 , 9600 */
	{
		printf("error: ttyS2 init failed\n");
		return EXIT_FAILURE;
	}

	while(loop)
	{
		Cooling_Module_Polling(1);/* Cooling Dvice ,Address 0x01*/
		sleep(1);
	}

	return EXIT_SUCCESS;
}


