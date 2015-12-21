/*
 * testing_a1.c
 *
 * the testing case, there are 7 case to be tested
 *
 *  Created on: Sep 27, 2015
 * 	Authors: Duc Cuong Dinh (B00516935)
 * 	         Jie Zhang      (B00583787)
 */
#include <stdio.h>
#include <stdlib.h>

#include "generalinfo.h"
#include "memory.h"

//test case 1:
//testing marcos
void test1(void)
{
	unsigned int value;
	value = 0;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 127;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 128;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 129;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 255;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 256;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 257;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 511;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 512;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 513;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 1023;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 1024;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 1025;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 2048;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 2049;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));
	value = 3000;
	printf("<value,address>: <%d, %08x>\n", value, (unsigned int) allocate(value));

}

//test case 2
void test2(void)
{
	unsigned int value;
	unsigned int count;
	// known: section 1KB is 16 blocks,
	// asking: 18 blocks 1Kb
	// supposed: given 16 blocks 1Kb, and 2 Kb

	value = 1024;
	for(count=0; count <18; count++)
		printf("<count, address>: <%d, %08x>\n", count, allocate(value));
}

//test case 3
void test3(void)
{
	unsigned int value;
	unsigned int count;
	// known: 248 blocks memory
	// asking: 249 blocks 60 bytes

	value = 60;
	for(count=0; count <249; count++)
		printf("<count, address>: <%d, %08x>\n", count, allocate(value));
}

//test case 4
void test4(void)
{
	unsigned int value;
	unsigned int count;
	// known: 8 blocks memory of 2Kbytes
	// asking: 9 blocks 2Kbytes

	value = 2000;
	for(count=0; count <9; count++)
		printf("<count, address>: <%d, %08x>\n", count, allocate(value));
}

//test case 5
void test5(void)
{
	unsigned int value;
	unsigned int count;
	// known: 8 blocks memory of 2Kbytes
	// asking: 5 blocks 2Kbytes

	value = 2000;
	for(count=0; count <5; count++)
		printf("<count, address>: <%d, %08x>\n", count, allocate(value));
	//return 2 block 1 and 4
	printf("deallocate\n");
	printf("deallocate 0x20014800: %d\n", deallocate((unsigned int *) 0x20014800));
	printf("deallocate 0x20016000: %d\n", deallocate((unsigned int *) 0x20016000));

}

//test case 6
void test6(void)
{
	unsigned int value;
	unsigned int count;
	// known: 8 blocks memory of 2Kbytes
	// asking: 5 blocks 2Kbytes

	//setup for 5 block in used
	value = 2000;
	for(count=0; count <5; count++)
		printf("address: %08x\n",(unsigned int) allocate(value));

	//return 2 block 1 and 4
	printf("deallocate\n");

	//in used
	printf("deallocate 0x20014000: %d\n", deallocate((unsigned int *) 0x20014000));
	printf("deallocate 0x20014800: %d\n", deallocate((unsigned int *) 0x20014800));

	//invalid
	printf("deallocate 0x20014801: %d\n", deallocate((unsigned int *) 0x20014801));
	printf("deallocate 0x20014FFF: %d\n", deallocate((unsigned int *) 0x20014FFF));

	//free
	printf("deallocate 0x20016800: %d\n", deallocate((unsigned int *) 0x20016800));
	printf("deallocate 0x20017000: %d\n", deallocate((unsigned int *) 0x20017000));
}

void test7(void)
{
	unsigned int value;
	unsigned int *get_address;

	//initializing value
	value = 1500;

	//add_number getting address
	get_address = allocate(value);
	printf("address: %08x\n", (unsigned int) get_address);

	//assigned the value 4 to the address
	(*get_address) = 4;
}

//set up 2Kbyte is all in used
// now deallocate an address out of address at 20018000 which is right after the index 247
void test8(void)
{
	unsigned int count;
	unsigned int value;
	value = 1500;
	printf("allocating 8 times\n");
	for(count=1; count<=8; count++)
		printf("allocate(%d): %08x\n", value, (unsigned int) allocate(value));
	printf("deallocate(0x20018000): %d\n", deallocate((unsigned int *)0x20018000));
}

//complex setup
void test9(void)
{
	unsigned int count;
	unsigned int value;
	value = 1500;
	printf("allocating 5 times\n");
	for(count=1; count<=5; count++)
		printf("allocate(%d): %08x\n", value, (unsigned int) allocate(value));
	printf("having 3 blocks lefts\n");
	printf("deallocate 2 times");
	value = 0x20015000;
	printf("deallocate(%08x): %d\n", value, deallocate((unsigned int *) value));
	value = 0x20015800;
	printf("deallocate(%08x): %d\n", value, deallocate((unsigned int *) value));
	printf("having 5 blocks lefts\n");
	value = 1500;
	for(count=1; count<=5; count++)
		printf("allocate(%d): %08x\n", value, (unsigned int) allocate(value));
	printf("having NONE block left\n");
	value = 0x20016000;
	printf("deallocate(%08x): %d\n", value, deallocate((unsigned int *) value));
	value = 0x20016800;
	printf("deallocate(%08x): %d\n", value, deallocate((unsigned int *) value));
	printf("having two blocks left\n");
	printf("asking three blocks\n");
	value = 1500;
	for(count=1; count<=3; count++)
		printf("allocate(%d): %08x\n", value, (unsigned int) allocate(value));


}
