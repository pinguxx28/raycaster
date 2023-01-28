#include "keys.h"

uc keys[UCHAR_MAX];

void init_keys()
{
	for (int i = 0; i < UCHAR_MAX; ++i)
	{
		keys[i] = 0;
	}
}
void key_down	(uc key, int x, int y)
{
	if (key == EXIT_KEY)
	{
		exit(0);
	}

	keys[key] = 1;
}

void key_up		(uc key, int x, int y)
{
	keys[key] = 0;
}
