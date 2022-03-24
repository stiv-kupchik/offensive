#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "words.h"


#define INSULT_TIMES 1

void message_random_insult()
{
	char msg[200];
	sprintf(msg, "cmd /c \"%%SystemRoot%%\\Sysnative\\msg.exe * Thou %s %s %s!\"", w1[rand() % W1_LEN], w2[rand() % W2_LEN], w3[rand() % W3_LEN]);
	system(msg);
}


void main()
{
	srand(time(NULL));
	for (int i = 0; i < INSULT_TIMES; i++)
	{
		message_random_insult();
	}
}