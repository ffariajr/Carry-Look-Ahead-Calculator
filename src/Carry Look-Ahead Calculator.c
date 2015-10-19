/*
 ============================================================================
 Name        : Carry.c
 Author      : Fernando Faria
 Version     :
 Copyright   : GNU Public License
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lookahead(int);


int main(int argc, char **argv) {

	if(argc == 1 || (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')) {
		printf("$ clac <bit_length_of_number>\n");
		return 0;
	}
	else if(argc != 2) {
		printf("\"clac -h\" for info on using this command.\n");
		return -1;
	}

	int bits = atoi(argv[1]);
	bits--;
	if(bits > 7) {
		printf("Number too big, ripple the carry look ahead.\n");
		return -1;
	}

	char *look = NULL;
	look = lookahead(bits);
	//printf("look-: %p\tbit:%i\n", look, bits);

	printf("The formula for the carry out of the %ith bit is: \n%s\n", bits, look);

	//if(look != NULL) {
	//	free(look);
	//}
	look = NULL;

	return 0;
}

char* lookahead(int bit) {

	char *result = NULL;
	result = (char *) malloc(24*(bit+1)*3);
	//printf("resul: %p\tbit:%i\n", result, bit);

	if(bit < 1) {
		strcpy(result, "Cin*A0 + Cin*B0 + A0*B0");
		return result;
	}

	char *propagate = NULL;
	propagate = lookahead(bit-1);
	//printf("Propa: %p\tbit:%i\n", propagate, bit);


	sprintf(result, "A%i*B%i + A%i*(%s) + B%i*(%s)%c", bit, bit, bit, propagate, bit, propagate, '\0');

	//if(propagate != NULL) {
	//	free(propagate);
	//}
	propagate = NULL;

	return result;
}


