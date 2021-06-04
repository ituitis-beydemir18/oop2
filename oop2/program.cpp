/*
* Student Name: Mertcan YASAKÇI
* Student ID: 150140051
* Date: 22/04/2016
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "classes.h"

using namespace std;

///////////////////////////////////////////////////////////
//	MAIN PROGRAM
//
//	placeCards		->	opens the file	"deck.txt"
//						takes first line
//						reads the input one by one
//						creates a corresponding card object according to the input
//						inserts card to the player1's deck
//						takes second line
//						reads the input one by one
//						creates a corresponding card object according to the input
//						inserts card to the player2's deck
//
//	compareAll		->	compares the corresponding cards of players using compare method in objects while traversing the HetLists
//
//	displayResults	->	counts scores of each player while traversing the HetLists
//						prints output to the screen in the desired format
///////////////////////////////////////////////////////////
//
//	In the previous version of my program, I was printing the deck in the given input file in reverse order.
//	This was not causing any problem and it was not strictly stated in the homework file but assistant told me to change this situation.
//	In order to change this, I used some local vectors for decks and scores.
//	I left my old codes as comments.
//
///////////////////////////////////////////////////////////
void displayResults(HetList&, HetList&);

void placeCards(HetList&, HetList&);
void compareAll(HetList&, HetList&);

int main(){

	HetList player1, player2;

	placeCards(player1, player2);

	player1.compare(player2);
	//compareAll(player1, player2);

	displayResults(player1, player2);

	return 0;
}

void placeCards(HetList&player1, HetList&player2){
	ifstream readFile("deck.txt");

	HetList *listPtr = &player1;

	Base *tmpCard;
	string deck, card;
	while (getline(readFile, deck)){
		istringstream deckInput(deck);
		while (deckInput >> card){
			if (card == "R"){
				tmpCard = new Red;
				listPtr->insert(tmpCard);
			}
			else if (card == "D"){
				tmpCard = new DarkRed;
				listPtr->insert(tmpCard);
			}
			else if (card == "B"){
				tmpCard = new Blue;
				listPtr->insert(tmpCard);
			}
			else if (card == "G"){
				tmpCard = new Green;
				listPtr->insert(tmpCard);
			}
		}
		listPtr = &player2;
	}
}

/*void compareAll(HetList&player1, HetList&player2){
	Base *i, *j;
	for (i = player1.getHead(), j = player2.getHead(); i != NULL, j != NULL; i = i->getNext(), j = j->getNext()){
		i->compare(j);
	}
}*/

void displayResults(HetList& player1, HetList& player2){
	int total1 = 0, total2 = 0;
	vector<char> types1, types2;
	vector<int> scores1, scores2;
	int cardNum1 = 0, cardNum2 = 0;
	
	for (Base* i = player1.getHead(); i != NULL; i = i->getNext()){
		types1.push_back(i->getType());
		scores1.push_back(i->getResult());
		cardNum1++;
	}

	for (Base* i = player2.getHead(); i != NULL; i = i->getNext()){
		types2.push_back(i->getType());
		scores2.push_back(i->getResult());
		cardNum2++;
	}

	cout << "Player1: ";
//	for (Base* i = player1.getHead(); i != NULL; i = i->getNext()){
//		cout << i->getType() << " ";
//	}
	for (int i = cardNum1-1; i >= 0; i--){
		cout << types1[i] << " ";
	}
	cout << endl;

	cout << "Player2: ";
//	for (Base* i = player2.getHead(); i != NULL; i = i->getNext()){
//		cout << i->getType() << " ";
//	}
	for (int i = cardNum2 - 1; i >= 0; i--){
		cout << types2[i] << " ";
	}
	cout << endl;

	cout << "Score1: ";
//	for (Base* i = player1.getHead(); i != NULL; i = i->getNext()){
//		cout << i->getResult() << " ";
//	}
	for (int i = cardNum1 - 1; i >= 0; i--){
		cout << scores1[i] << " ";
	}
	cout << endl;

	cout << "Score2: ";
//	for (Base* i = player2.getHead(); i != NULL; i = i->getNext()){
//		cout << i->getResult() << " ";
//	}
	for (int i = cardNum1 - 1; i >= 0; i--){
		cout << scores2[i] << " ";
	}
	cout << endl;

	cout << "Total Score1: ";
	{
		int lose = 0, tie = 0, win = 0;

		for (Base* i = player1.getHead(); i != NULL; i = i->getNext()){
			if (i->getResult() == 0){
				lose++;
				total1 += 0;
			}
			else if (i->getResult() == 1){
				tie++;
				total1 += 1;
			}
			else if (i->getResult() == 2){
				win++;
				total1 += 2;
			}
		}

		cout << "Lose: " << lose << " " << "Tie: " << tie << " " << "Win: " << win;
	}
	cout << endl;

	cout << "Total Score2: ";
	{
		int lose = 0, tie = 0, win = 0;

		for (Base* i = player2.getHead(); i != NULL; i = i->getNext()){
			if (i->getResult() == 0){
				lose++;
				total2 += 0;
			}
			else if (i->getResult() == 1){
				tie++;
				total2 += 1;
			}
			else if (i->getResult() == 2){
				win++;
				total2 += 2;
			}
		}

		cout << "Lose: " << lose << " " << "Tie: " << tie << " " << "Win: " << win;
	}
	cout << endl;

	cout << "Winner: ";
	if (total1 > total2){
		cout << "Player1";
	}
	else if (total1 < total2){
		cout << "Player2";
	}
	else{
		cout << "Tie!";
	}
	cout << endl;
}