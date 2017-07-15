/*
 * test.c
 *
 *  Created on: Apr 17, 2017
 *      Author: Marko
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "flow_table.h"

/*
 * Protocol numbers - always the same and constant
 * represented by an array of 256 values.
 */

int proto_nums[256];

int main(void){
/*
 * All of the VARs with lowercase 'p' are considered
 * as a part of the incoming IP packet. On the other hand
 * the VARs with no lowercase notation are considered as
 * a part of rules from the rule table stored in memory.
 * Rules can be segmented in such a way that one can
 * look at them as five completely separate rules:
 *
 * === SA === DA === SP === DP === PROTO === Flag ===
 *
 */

	int SA = 0x82013771; /* SA address is read from the rule table */
	unsigned int SAp = 0x82013771; /* SA address field from incoming packet (SAp) */
//	int i = 0; /* counter for populating ip_bytes array */
//	int match, SPp, SP_low, SP_high;
	unsigned int DAp = 0x8201376a;
	int count = 0;
	int j = 0;
	int	test_counter = 0;
	int match;
	int SPp, SP_high, SP_low, DPp, DP_high, DP_low;
	int Protocol_p;
	int c;
//	int dec_subnet_mask; /* subnet mask is read from the rule table */
	int hex_subnet_mask = 0xffffffff; /* max length of subnet mask in hexadecimal */
//	unsigned int ip_addr; /* unsigned int ip_addr; */
//	int ip_bytes[5]; /* integer array for all the parts of an IP address */
	flow_table flow[8003]; /* array of data of type flow_table defined in flow_table.h */
	flow_table *flow_p; /* flow table pointer to get values from an array */
	FILE *f = fopen("C:\\Users\\Jeremy\\Cworkspace\\Test\\src\\firewall_10k","r");
	FILE *fp = fopen("C:\\Users\\Jeremy\\Cworkspace\\Test\\src\\firewall_10k","r");
	flow_p = flow;




	 if(fp == NULL) {
	   printf("Error in file opening\n");
	 }

	 while (c != EOF)
	 {
	     c = fgetc(fp);
	     test_counter = (c == '\n') ? test_counter + 1 : test_counter;
	 }

    fclose(fp);

//	flow_table flow2[test_counter];

	if(f == NULL) {
	   printf("Error in file opening\n");
	}

	while (fscanf(f,"%s %d %s %d %d %d %d %d %d",
			flow[count].SA, &flow[count].SA_mask, flow[count].DA, &flow[count].DA_mask,
			&flow[count].SP_low, &flow[count].SP_high, &flow[count].DP_low, &flow[count].DP_high,
			&flow[count].Protocol) != EOF)
		{
			count++;
		}


    for (j = 0; j < count; j++) {
    printf("%s %d %s %d %d %d %d %d %d\n",\
    flow[j].SA, flow[j].SA_mask, flow[j].DA, flow[j].DA_mask, \
    flow[j].SP_low, flow[j].SP_high, flow[j].DP_low, flow[j].DP_high, \
    flow[j].Protocol);
    }

    fclose(f);


	printf("Vrednost test_counter promenljive je: %d\n", test_counter);
    printf("Vrednost promenljive SA iz fajla je: %s\n", flow_p->SA);

	printf("Vrednost promenljive SA je: %x\n", SA);

	/* Change the IP address format from string to integer
	 * by using the strtok() and atoi() predefined functions.
	 * strtok() splits the input string into array elements by using
	 * the delimiter fields ("." and "/" in this case). First four
	 * elements of the resulting array are the four bytes of an IP
	 * address, while the last integer value is the subnet mask.
	 */

	int dec_to_hex_ip_conversion(char *ip_dec) {

		int i = 0;
		int ip_bytes[4];
		char *pch;
		unsigned long ip_addr;

		// String to decimal conversion

		pch = strtok(ip_dec, ".");
		while (pch != NULL && i < 4)
		{
			ip_bytes[i] = atoi(pch);
			pch = strtok(NULL, ".");
			i++;
		  }

		printf("IP adresa je %d.%d.%d.%d\n", ip_bytes[0], ip_bytes[1], ip_bytes[2], ip_bytes[3]);

		// Decimal to hex conversion
		ip_addr = ip_bytes[0] * (256 * 256 * 256) + ip_bytes[1] * (256 * 256) + ip_bytes[2] * 256 + ip_bytes[3];
		printf("IP adresa iz tabele u unsigned long formatu: %lu\n", ip_addr);

		unsigned int hex_ip_addr = (ip_addr & 0xff000000) + (ip_addr & 0x00ff0000) + (ip_addr & 0x0000ff00) + (ip_addr & 0x000000ff);
		printf("IP adresa iz tabele pretvorena u heksadecimalan format: %x\n", hex_ip_addr);

		return hex_ip_addr;
	}

/*	char *pch;
	pch = strtok(flow[0].SA, ".");
	while (pch != NULL && i < 4)
	{
		ip_bytes[i] = atoi(pch);
		pch = strtok(NULL, ".");
		i++;
	  }

	printf("IP adresa sa subnet maskom je %d.%d.%d.%d/%d\n", ip_bytes[0], ip_bytes[1], ip_bytes[2], ip_bytes[3], flow[0].SA_mask);

	ip_addr = ip_bytes[0] * (256 * 256 * 256) + ip_bytes[1] * (256 * 256) + ip_bytes[2] * 256 + ip_bytes[3];
	printf("IP adresa iz tabele u unsigned long formatu: %u\n", ip_addr);

	unsigned int hex_ip_addr = (ip_addr & 0xff000000) + (ip_addr & 0x00ff0000) + (ip_addr & 0x0000ff00) + (ip_addr & 0x000000ff);
	printf("IP adresa iz tabele pretvorena u heksadecimalan format: %x\n", hex_ip_addr);
	*/

	/* Create a new subnet mask in hexadecimal form.
	 * This subnet mask is then used to find the host part
	 * of the IP address and for comparing two IP addresses.
	 */

/*	dec_subnet_mask = flow_p->SA_mask;
	hex_subnet_mask = dec_subnet_mask > 0 ? hex_subnet_mask << (32 - dec_subnet_mask) : 0;
	printf("Subnet maska u heksadecimalnom formatu je: %x\n", hex_subnet_mask);
*/
	int dec_to_hex_mask_conversion(int dec_subnet_mask) {

		//int dec_subnet_mask = sub_dec;
		int hex_subnet_mask = 0xffffffff;
		hex_subnet_mask = dec_subnet_mask > 0 ? hex_subnet_mask << (32 - dec_subnet_mask) : 0;
		printf("Subnet maska u heksadecimalnom formatu je: %x\n", hex_subnet_mask);
		return hex_subnet_mask;
	}

	/* Uncoment the section below to use for testing purposes only:
	 * ip_addr = SA & hex_subnet_mask;
	 * printf("IP adresa u heksadecimalnoj predstavi je %x\n", ip_addr);
	 * printf("IP adresa je: %u\n", ip_addr);
	 */

	/* Find the host part of the IP address for both
	 * SA and SAp (refer to convention from the start of the program).
	 * Use XOR to determine if both IP addresses are the same.
	 * If that is the case, print that. If they are not equal,
	 * print that out, too.
	 */


/* Matching the SA and SAp field. If they match, continue to matching DA and DAp.
 * If they do not match, break the matching process for the rest of the fields,
 * and increment the id from the for loop.
 */
	//SA = SA & hex_subnet_mask;
	hex_subnet_mask = dec_to_hex_mask_conversion(flow_p->SA_mask);
	SAp = SAp & hex_subnet_mask;
	unsigned int SAx = dec_to_hex_ip_conversion(flow_p->SA);
//	int SAx = hex_ip_addr & hex_subnet_mask;
//	printf("Vrednost promenljive SAx je: %x\n", SAx);
	printf("Vrednost promenljive SAx je: %x\n", SAx);
	printf("Vrednost promenljive SAp je: %x\n", SAp);
	int Compare_SA = !(SAx ^ SAp);
	printf("Vrednost promenljive Compare_SA je: %x\n", Compare_SA);
	match = Compare_SA ? 1 : 0;

	if (Compare_SA){
		printf("Promenljive SA i SAp JESU jednake\n");

	}
	else {
		printf("Promenljive SA i SAp NISU jednake\n");
	}

	unsigned int DAx = dec_to_hex_ip_conversion(flow_p->DA);
	hex_subnet_mask = dec_to_hex_mask_conversion(flow_p->DA_mask);
	DAp = DAp & hex_subnet_mask;
	printf("Vrednost promenljive DAx je: %x\n", DAx);
	printf("Vrednost promenljive DAp je: %x\n", DAp);
	int Compare_DA = !(DAx ^ DAp);
	printf("Vrednost promenljive Compare_DA je: %x\n", Compare_DA);
	match = (match & Compare_DA) ? 1 : 0;


/* Testing the matching of SP field from the IP packet and based on values from the flow table.
 * Variable match is equal to 1 if one of the following occurs:
 * 1) SP from the flow table is equal to MIN or MAX port value -> each incoming port is a match;
 * 2) SP_low is equal to SP_high -> port from the IP packet must match exactly;
 * 3) Port from the IP packet is inbetween SP_low and SP_high -> it must be greater than or equal to SP_low
 *    and less than or equal to SP_high.
 *
 * The same logic can be applied when trying to determine whether or not the DP from IP packet matches.
 */

	SP_low = flow_p->SP_low;
	SP_high = flow_p->SP_high;
	SPp = 161; // this value should be read from the network interface

	match = ((SP_low == MIN_PORT) & (SP_high == MAX_PORT)) | ((SPp >= SP_low) & (SPp <= SP_high)) | ((SP_low == SP_high) & (SPp == SP_low)) ? 1 : 0;


	DP_low = flow_p->DP_low;
	DP_high = flow_p->DP_high;
	DPp = 2055; // this value should be read from the network interface

	match = ((DP_low == MIN_PORT) & (DP_high == MAX_PORT)) | ((DPp >= DP_low) & (DPp <= DP_high)) | ((DP_low == DP_high) & (DPp == DP_low)) ? 1 : 0;

/* Testing whether or not the Protocol field corresponds to the Protocol field from the flow table.
 * If there is a match, the value of the variable is 1, which means that all of the fields have the same value.
 * If the last field does not match, the search continues and the next row is searched.
 */

	Protocol_p = 0x11;
	match = Protocol_p == flow_p->Protocol ? 1 : 0;
	printf("Polje protokol iz paketa i iz tabele su: %d %d \n", Protocol_p, flow_p->Protocol);

	printf("Vrednost poklapanja je: %d\n", match);

	return EXIT_SUCCESS;
}
