#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define INSULT_COUNT 4
#define MSG_TITLE L"Ook Ook"

typedef enum offensive_level
{
	PWNS = 1,
	TAUNTS,
	INSULTS,
	RUSSIAN
} offensive_level;

int get_min_value(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

void shuffle(int* array, size_t n)
{
	if (n > 1)
	{
		size_t i;
		for (i = 0; i < n - 1; i++)
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}

void message_random_insult(const WCHAR** insult_array)
{
	static int chosen_indices[INSULT_COUNT] = { 0, 1, 2, 3 };
	static int order_index = 0;
	WCHAR msg[200];
	if (order_index == 0)
	{
		shuffle(chosen_indices, INSULT_COUNT);
	}
	//MessageBoxW(NULL, insult_array[chosen_indices[order_index]], MSG_TITLE, 0);
	swprintf(msg, 200, L"cmd /c \"%%SystemRoot%%\\Sysnative\\msg.exe * %s\"", insult_array[chosen_indices[order_index]]);
	//wprintf(msg);
	_wsystem(msg);
	order_index++;
}

int pick_insult_level(int insult_level)
{
	int weight = rand() % 100;
	if (weight < 10 || insult_level == PWNS)
	{
		return PWNS;
	}
	if (weight < 30)
	{
		return get_min_value(TAUNTS, insult_level);
	}
	if (weight < 60)
	{
		return get_min_value(INSULTS, insult_level);
	}
	return get_min_value(RUSSIAN, insult_level);
}