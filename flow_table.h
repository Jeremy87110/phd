/*
 * flow_table.h
 *
 *  Created on: May 29, 2017
 *      Author: Jeremy
 */

#ifndef FLOW_TABLE_H_
#define FLOW_TABLE_H_

#define MIN_PORT 0
#define MAX_PORT 65535

/* Definise se novi tip promenljive koja se koristi za unosenje podataka iz flow tabele.
 * Na ovaj nacin ce biti moguce da se kreira struktura podataka koja ce imati raznolike tipove podataka,
 * sto nije moguce kod definisanja nizova gde svi podaci moraju biti istog tipa.
 *
 * Za razliku od prvobitne ideje da se podatak o subnet maski lepi uz adresu, ovde su odvojena polja,
 * tj. SA i SA_mask. Na taj nacin je potrebno izvrsiti konverziju atoi() samo za IP adresu. Isto vazi
 * i za DA i DA_mask.
 *
 * Problem sa portovima je resen tako sto su definisana donja i gornja granica, low i high.
 * Ako su low i high port jednaki, smatra se da se port iz paketa mora jednozacno poklopiti.
 * Ako su low i high neki opseg, onda svaki port koji pripada izmedju low i high odgovara.
 * Ako su low i high na krajevima opsega (0 i 65535), ovaj opseg se posmatra kao wildcard opseg
 * i svi portovi se poklapaju.
 *
 * Za polje protokol (Protocol) je ostavljeno da bude tipa int, sto moze da se promeni ako bude potrebno,
 * jer su u paketu svakako sva polja u heksadecimalnoj formi.
 */


typedef struct flow_table{
   char SA[15];
   int SA_mask;
   char DA[15];
   int DA_mask;
   int SP_low;
   int SP_high;
   int DP_low;
   int DP_high;
   int Protocol;
} flow_table;

#endif /* FLOW_TABLE_H_ */
