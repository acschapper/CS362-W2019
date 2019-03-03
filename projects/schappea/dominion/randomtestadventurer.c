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
	int count1 = 0;
	int count2 = 0;
	
	for(a = 0; a < 50; a++)
	{
		int numPlayers = (rand() % 50);
		int seed = (rand() % 5000);

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &state);

		printf("\n----------Adventurer Card Test %d/50----------\n", a+1);

		// copy the game state to a test case
		memcpy(&test, &state, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &state, handpos, &bonus);

		player = whoseTurn(&test);
		
		
		//this is to count the deck and see if it is accurate
		if(test.deckCount[player]-1 == state.deckCount[player])
			printf("Test Passed: deck count is correct\n");
		else
			printf("Test Failed: deck count is not correct\n");
		
		
		//this is to check to see if the player hand count are correct
		if(test.handCount[player]-1 == state.handCount[player])
			printf("Test Passed: deck hand is correct\n");
		else
			printf("Test Failed: deck hand is not correct\n");
		
		
		//this is to check to see if the players hand is correct
		if(state.hand[player][test.handCount[player]] != -1)
			printf("Test Passed: Adventurer card was added to the players hand\n");
		else
			printf("Test Failed: Adventurer card was not added to the players hand\n");

		
		//this is to check if player played a card
		if(test.playedCardCount+2 == state.playedCardCount)
			printf("Test Passed: player played Adventurer card\n");
		else
			printf("Test Failed: player did not play Adventurer card\n");
		
		
		//this is to count Adventurer cards in the hand
		for (i = 0; i < state.handCount[0]; i++)
			if(state.hand[0][i] = adventurer);
				count1++;
			
		for (i = 0; i < test.handCount[0]; i++)
			if(test.hand[0][i] = adventurer);
				count2++;
		
		if(count1 == count2-1)
			printf("Test Passed: no variance in Adventurer cards\n");
		else
			printf("Test Failed: variance in Adventurer cards\n");
		
		
		//This is the to see if the car was actually discarded
		if(test.discardCount[player] == state.discardCount[player])
			printf("Test Passed: Adventurer was discarded\n");	
		else
			printf("Test Failed: Adventurer was not discarded.\n");
		
		
		//this is to see if the action was added by +1
		if(test.numActions+2 == state.numActions)
			printf("Test Passed: two extra action was added\n");
		else
			printf("Test Failed: two extra action was not added\n");
	
	}
	printf("----------Test concluded for Adventurer Card----------\n");
}

