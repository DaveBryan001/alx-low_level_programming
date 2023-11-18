#include "lists.h"

/**
 * pre_main_msg - Prints a message before the main function is executed.
 */

void __attribute__ ((constructor)) pre_main_msg()
{
	printf("You're beat! and yet, you must allow");
	printf(",\nI bore my house upon my back!\n");
}
