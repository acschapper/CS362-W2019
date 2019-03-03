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
    int seed = 1000;
    //int numPlayers = 2;
    int player=0;
	struct gameState state, test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	for(a = 0; a < 10000; a++)
	{
		int numPlayers = (rand() % 50);
		//int seed = (rand() % 100);
	
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &state);

		printf("\n----------Great Hall Test %d/10000----------\n", a+1);

		// copy the game state to a test case

		memcpy(&test, &state, sizeof(struct gameState));
		cardEffect(great_hall, choice1, choice2, choice3, &state, handpos, &bonus);

		player = whoseTurn(&test);
		
		//this is to check the players hand
		if(state.hand[player][test.handCount[player]-1] != -1)
			printf("Test Passed:Great Hall card was added to the players hand\n");
		else
			printf("Test Failed:Great Hall card was not added to the players hand\n");

		//this is to check if player played the Great Hall card
		if(test.playedCardCount+1 == state.playedCardCount)
			printf("Test Passed: player played Great Hall card\n");
		else
			printf("Test Failed: where player did not play Great Hall card\n");
			
		//This is the to see if the car was actually discarded
		if(test.discardCount[player] == state.discardCount[player])
			printf("Test Passed: Great Hall was discarded\n");	
		else	
		{
			printf("Test Failed: Great Hall was not discarded.\n");
		}
		
		//this is to see if the action was added by +1
		if(test.numActions+1 == state.numActions)
			printf("Test Passed: action was added\n");
		else
			printf("Test Failed: action was not added\n");
	}
	printf("----------Test concluded for Great Hall Card----------\n");
}

