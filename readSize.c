#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {

unsigned long x = 0xabababab;

uint32_t y;
uint64_t z;

printf("Char size is %zd bytes.\n", sizeof(char));
printf("Variable x size is %zd bytes.\n", sizeof(x));
printf("Size of unsigned long long is %zd bytes.\n", sizeof(unsigned long long));
printf("Size of unsigned int is %zd bytes.\n", sizeof(y));
printf("Size of short int is %zd bytes.\n", sizeof(short int));
printf("Size of unsigned long long is %zd bytes.\n", sizeof(z));

return EXIT_SUCCESS;

}
