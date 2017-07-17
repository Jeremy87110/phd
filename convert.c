#include <stdio.h>
#include <stdint.h>

uint64_t binstrToInt(const char* binstr)
{
    uint64_t result = 0;
    int bit = 0;
    while(binstr[bit] != '\0')
    {

    binstr[bit] == '1' ? sum |= 1 : sum;
    bit++;
    binstr[bit] != '\0' ? sum <<= 1 : sum;
   }

   unsigned int hex_ip_addr = (sum & 0xff000000) + (sum & 0x00ff0000) + (sum & 0x0000ff00) + (sum & 0x000000ff);
   printf("IP adresa iz tabele pretvorena u heksadecimalan format: %x\n", hex_ip_addr);

   return sum;
}

int main()
{
    char SAp[33];
    printf("Unesite binarni broj koji je potrebno konvertovati: \n");
    fgets(SAp, sizeof(SAp), stdin);
    printf("Konvertovana vrednost je: %llu\n", binstrToInt(SAp));
    return 0;
}
