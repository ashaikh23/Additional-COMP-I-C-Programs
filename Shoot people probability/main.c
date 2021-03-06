#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;
enum duelist { AARON, BOB, CHARLIE };
typedef enum duelist Duelist;

void generate_report(Boolean aaron_intentionally_misses, int number_of_duels);

Duelist run_duel(Boolean aaron_intentionally_misses);
void shoot(Boolean* pIs_alive, double accuracy);
const double AARON_ACCURACY = 1 / 3.0;
const double BOB_ACCURACY = 1 / 2.0;
const double CHARLIE_ACCURACY = 1;



int main(int argc, char* argv[])
{
	srand(time(0));
	const Boolean AARON_INTENTIONALLY_MISSES = TRUE;
	const int NUMBER_OF_DUELS = 1000000;

	generate_report(!AARON_INTENTIONALLY_MISSES, NUMBER_OF_DUELS);
	generate_report(AARON_INTENTIONALLY_MISSES, NUMBER_OF_DUELS);
	return 0;
}

void generate_report(Boolean aaron_intentionally_misses, int number_of_duels)
{
	int aaron_wins = 0;
	int bob_wins = 0;
	int charlie_wins = 0;
	int i;

	if (aaron_intentionally_misses)
	{
		printf("Generating report for when Aaron intentionally misses his first shot.\n");
	}
	else
	{
		printf("Generating report for when Aaron does NOT intentionally miss his first shot.\n");
	}
	for (i = 0; i < number_of_duels; i++)
	{
		switch (run_duel(aaron_intentionally_misses))
		{
		case AARON:
			aaron_wins++;
			break;
		case BOB:
			bob_wins++;
			break;
		case CHARLIE:
			charlie_wins++;
			break;
		}
	}
	printf("The probability that Aaron wins is %f\n", aaron_wins / (double) number_of_duels);
	printf("The probability that Bob wins is %f\n", bob_wins / (double)number_of_duels);
	printf("The probability that Charlie wins is %f\n\n", charlie_wins / (double)number_of_duels);
}

Duelist run_duel(Boolean aaron_intentionally_misses)
{
	Boolean aaron_is_alive = TRUE;
	Boolean bob_is_alive = TRUE;
	Boolean charlie_is_alive = TRUE;
	while (aaron_is_alive && bob_is_alive || aaron_is_alive && charlie_is_alive ||
		bob_is_alive && charlie_is_alive)
	{
		if (aaron_is_alive && !aaron_intentionally_misses)
		{
			if (charlie_is_alive)
			{
				shoot(&charlie_is_alive, AARON_ACCURACY);
			}
			else
			{
				shoot(&bob_is_alive, AARON_ACCURACY);
			}
		}
		if (bob_is_alive)
		{
			if (charlie_is_alive)
			{
				shoot(&charlie_is_alive, BOB_ACCURACY);
			}
			else
			{
				shoot(&aaron_is_alive, BOB_ACCURACY);
			}
		}
		if (charlie_is_alive)
		{
			if (bob_is_alive)
			{
				shoot(&bob_is_alive, CHARLIE_ACCURACY);
			}
			else
			{
				shoot(&aaron_is_alive, CHARLIE_ACCURACY);
			}
		}
		aaron_intentionally_misses = FALSE;
	}

	if (aaron_is_alive)
	{
		return AARON;
	}
	if (bob_is_alive)
	{
		return BOB;
	}
	return CHARLIE;
}

void shoot(Boolean* pIs_alive, double accuracy)
{
	double roll;
	roll = rand() / (double) RAND_MAX;

	if (roll <= accuracy)
	{
		*pIs_alive = FALSE;
	}
}

