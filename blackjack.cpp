// BlackJack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <ctime>

//               A  2  3  4  5  6  7  8  9  10   J   K  Q
int Cards[] = { 20, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 40, 40 };

int rand_int_between(int min, int max){
	srand(time(0));
	return rand() % max + min;
}
int next_draw()
{
	int card = Cards[rand_int_between(0, 12)];
	if (card == 30 || card == 40 || card == 50) 
	{ 
		card = 10;
	}
	else if (card == 20) 
	{
		printf("=> You drew an ace! Would you like to use it as a 1 or 11? : ");
		std::cin >> card;
		if (card != 1 || card != 11){
			card = next_draw();
			printf("> You tried to falsify a card and cheat? How dare you! \n> Now you get a random card (%i) :)\n", card);
		}
	}
	return card;
}
bool busted = false;
const char *menu = "S\t-\tStay\nH\t-\tHit me";

int main()
{
	int current_hand_total = 0;
	int last_draw = 0;
	std::cout << "Welcome to Black Jack!\n";
	std::cout << menu << std::endl;
	
	while (busted==false){

		if (current_hand_total <= 21){
			char op = 0;
			std::cout << "Action: ";
			std::cin >> op;
			if (op == 'S'){
				break;
			}
			else {
				last_draw = next_draw();
				current_hand_total = current_hand_total + last_draw;

				if (current_hand_total > 21)
				{
			busted = true; 
				printf("! Ooo! Sorry man, your last card (%i) caused you to bust with %i\n", last_draw, current_hand_total);
				break;
				}
				else if (current_hand_total == 21)
				{ 
					printf("You won the game with 21!\n"); 
					break; 
				}
				printf("=> You drew a %i, your current card total is %i\n", last_draw, current_hand_total);

			}

		}
		else{
			busted = true;
			printf("! Ooo! Sorry man, your last card (%i) caused you to bust with %i\n", last_draw,current_hand_total);
		}
	}
	std::cout << "=> Ended game with a total of: " << current_hand_total << std::endl;

	getchar();
	getchar();
	return 0;
}

