/*
The following macro definitions convert to and from the network standard byte
order. The macros with their name in lower case guarantee to evaluate their
argument exectly once. The function of the macros is encoded in their names;
htons means convert a (unsigned) short in host byte order to network byte order.
*/

#ifndef _NET__HTON_H
#define _NET__HTON_H

#include <minix/config.h>

extern u16_t _tmp;
extern u32_t _tmp_l;

/* Find out about the byte order. */

/* assume <minix/config.h> is included, let's check */
#if (CHIP == 0)
#include "CHIP macro not set, include <minix/config.h>"
#endif

#if (CHIP == INTEL)
#define LITTLE_ENDIAN	1
#endif

#if (CHIP == M68000 || CHIP == SPARC)
#define BIG_ENDIAN	1
#endif


#if (LITTLE_ENDIAN) && (BIG_ENDIAN)
#include "both LITTLE_ENDIAN and BIG_ENDIAN are defined"
			/* LITTLE_ENDIAN and BIG_ENDIAN are both defined */
#endif

#if !(LITTLE_ENDIAN) && !(BIG_ENDIAN)
#include "neither LITTLE_ENDIAN nor BIG_ENDIAN is defined"
			/* LITTLE_ENDIAN and BIG_ENDIAN are both NOT defined */
#endif

#if LITTLE_ENDIAN
#define htons(x) (_tmp=(x), ((_tmp>>8) & 0xff) | ((_tmp<<8) & 0xff00))
#define HTONS(x) ( ( (((unsigned short)(x)) >>8) & 0xff) | \
		((((unsigned short)(x)) & 0xff)<<8) )

#define ntohs(x) (_tmp=(x), ((_tmp>>8) & 0xff) | ((_tmp<<8) & 0xff00))
#define NTOHS(x) ( ( (((unsigned short)(x)) >>8) & 0xff) | \
		((((unsigned short)(x)) & 0xff)<<8) )

#define htonl(x) (_tmp_l=(x), ((_tmp_l>>24) & 0xffL) | \
	((_tmp_l>>8) & 0xff00L) | \
	((_tmp_l<<8) & 0xff0000L) | ((_tmp_l<<24) & 0xff000000L))
#define HTONL(x) ((((x)>>24) & 0xffL) | (((x)>>8) & 0xff00L) | \
	(((x)<<8) & 0xff0000L) | (((x)<<24) & 0xff000000L))
#define ntohl(x) (_tmp_l=(x), ((_tmp_l>>24) & 0xffL) \
	| ((_tmp_l>>8) & 0xff00L) | \
	((_tmp_l<<8) & 0xff0000L) | ((_tmp_l<<24) & 0xff000000L))
#define NTOHL(x) ((((x)>>24) & 0xffL) | (((x)>>8) & 0xff00L) | \
	(((x)<<8) & 0xff0000L) | (((x)<<24) & 0xff000000L))

#endif /* LITTLE_ENDING */

#if BIG_ENDIAN
#define htons(x) (x)
#define HTONS(x) (x)
#define ntohs(x) (x)
#define NTOHS(x) (x)
#define htonl(x) (x)
#define HTONL(x) (x)
#define ntohl(x) (x)
#define NTOHL(x) (x)
#endif /* BIG_ENDIAN */

#endif /* _NET__HTON_H */
