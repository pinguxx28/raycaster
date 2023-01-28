#ifndef __KEYS_H
#define __KEYS_H
#include "include.h"

/* esc */
#define EXIT_KEY 27

typedef unsigned char uc;
extern uc keys[UCHAR_MAX];

void init_keys	();

/* x and y are trash values required by the glut function */
/* but none of them are used in my implementation */
void key_down	(uc key, int x, int y);
void key_up		(uc key, int x, int y);

#endif
