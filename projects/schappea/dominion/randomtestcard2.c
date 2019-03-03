#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include<time.h>

void main() 
{
	srand(time(NULL));
	
    int i, j, m, a;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    //int seed = 1000;
    //int numPlayers = 2;
    int player=0;
	struct gameState state, test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	for(a = 0; a < 50; a++)
	{
		int numPlayers = (rand() % 50);
		int seed = (rand() % 5000);
		
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &state);


		printf("\n----------Village Card Test %d/50----------\n", a+1);

		// copy the game state to a test case
		memcpy(&test, &state, sizeof(struct gameState));
		cardEffect(village, choice1, choice2, choice3, &state, handpos, &bonus);

		player = whoseTurn(&test);
		
		//this is to check the players hand
		if(state.hand[player][test.handCount[player]-1] != -1)
			printf("Test Passed: Village card was added to the players hand\n");
		else
			printf("Test Failed: Village card was not added to the players hand\n");

		//this is to check if player played the Great Hall card
		if(test.playedCardCount+1 == state.playedCardCount)
			printf("Test Passed: player played Village card\n");
		else
			printf("Test Failed: player did not play Village card\n");
			
		//This is the to see if the car was actually discarded
		if(test.discardCount[player] == state.discardCount[player])
			printf("Test Passed: Village was discarded\n");	
		else	
		{
			printf("Test Failed: Village was not discarded.\n");
		}
		
		//this is to see if the action was added by +2
		if(test.numActions+2 == state.numActions)
			printf("Test Passed: two extra action was added\n");
		else
			printf("Test Failed: where two extra action was not added\n");
	}
	printf("----------Test concluded for Village Card----------\n");
}
