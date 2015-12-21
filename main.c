/*	FILE: main.c
 * 	This is the main function to run the program
 *
 * 	Date: September 20th, 2015
 * 	Authors: Duc Cuong Dinh (B00516935)
 * 	         Jie Zhang      (B00583787)
 */

#include <stdio.h>
#include <stdlib.h>

#include "generalinfo.h"
#include "memory.h"

#include "testing_a1.h"

void initialize(void)
{
	initial_memory();
}

int main(void)
{
	initialize();
	test9();

	return 0;
}
