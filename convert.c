#include <stdio.h>
#include <stdint.h>

uint64_t binstrToInt(const char* binstr)
{
    uint64_t result = 0;
    int bit = 0;
    while(binstr[bit] != '\0')
    {

    binstr[bit] == '1' ? result |= 1 : result;
    bit++;
    binstr[bit] != '\0' ? result <<= 1 : result;
   }

   unsigned int hex_ip_addr = (result & 0xff000000) + (result & 0x00ff0000) + (result & 0x0000ff00) + (result & 0x000000ff);
   printf("IP adresa iz tabele pretvorena u heksadecimalan format: %x\n", hex_ip_addr);

   return result;
}

int main()
{
    char SAp[33];
    printf("Unesite binarni broj koji je potrebno konvertovati: \n");
    fgets(SAp, sizeof(SAp), stdin);
    printf("Konvertovana vrednost je: %llu\n", binstrToInt(SAp));
    return 0;
}
