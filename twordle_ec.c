//Author: Ayush Bhakta
//Date: 4/21/2026
//Purpose: Project 10

#include<stdio.h>

#define ROW 7
#define COL 6
#define WORDLENGTH 5
#define INPUTFILE "mystery.txt"

void mysteryWord(char word[]);
void userGuess(char array[][COL], int row, int col);
void wordLength(char array[][COL], int row, int* count, int* count2);
int validGuess(char array [][COL], int row);
void lowercase(char array[][COL], int row);
void correctLetter(char array[][COL], int row);
void misplacedLetter(char array[][COL], int row);
void divider();
void space(int val);
void winCondition(char array[][COL], int row, int* win);


int main(){

char game[ROW][COL];
int win = 0;
int gameI;

	mysteryWord(game[0]);
	
	for(gameI = 1; gameI < ROW && win == 0; gameI++){	
		printf("Guess %d! Enter your guess: ", gameI);
			
		while(validGuess(game, gameI) == 0){
			printf("\nPlease try again: ");
		}
		
		lowercase(game, gameI);
		divider();
		
		for(int history = 1; history <= gameI; history++){
			correctLetter(game, history);
			printf("\n");
			misplacedLetter(game, history);
			printf("\n");
		}
		
		winCondition(game, gameI, &win);
	}
	
	if(win == 1){
		for(int colI = 0; colI < WORDLENGTH; colI++){
			if(game[0][colI] >= 'a' && game[0][colI] <= 'z'){
			printf("%c", game[0][colI] - ('a' - 'A'));
			}
			else{
			printf("%c", game[0][colI]);
			}
		}
		printf("\nYou won in %d guesses!\n", gameI - 1);		
	}
	else{
		printf("You lost, better luck next time!\n");
	}	
		
	return 0;
}

void mysteryWord(char word[]){
	
	FILE *inputfile;
	
	inputfile = fopen(INPUTFILE, "r");
	if(inputfile == NULL){
		printf("Cant open file :(\n");
		return;
	}
	
	fscanf(inputfile, "%s", word);
	fclose(inputfile);
}

void userGuess(char array[][COL], int row, int col){
	scanf("%5s", array[row]);
}

void wordLength(char array[][COL], int row, int* count, int* count2){

int colI;

	for(colI = 0; array[0][colI] != '\0'; colI++){
	}
	*count = colI;
	
	for(colI = 0; array[row][colI] != '\0'; colI++){
	}
	*count2 = colI;
}

int validGuess(char array [][COL], int row){

int mysteryLen, guessLen;
int nonletter = 0;

	userGuess(array, row, COL);
	wordLength(array, row, &mysteryLen, &guessLen);	
	
	for(int colI = 0; colI < guessLen; colI++){
		char c = array[row][colI];
		if(c >= 'a' && c <= 'z'){
		}
		else if(c >= 'A' && c <= 'Z'){
		}
		else{
		nonletter = 1;
		}
	}
	
	if(guessLen == WORDLENGTH && nonletter == 0){
		return 1;
	}
	else{
		if(guessLen != WORDLENGTH){
			printf("Your guess must be 5 letters long. ");
		}
		else if(nonletter == 1){
			printf("Your guess must contain only letters. ");
		}
		return 0;
	}
}	

void lowercase(char array[][COL], int row){

	for(int colI =0; array[row][colI] != '\0'; colI++){
		if(array[row][colI] >= 'A' && array[row][colI] <= 'Z'){
		array[row][colI] = array[row][colI] + ('a' - 'A');
		}
	}
}

void correctLetter(char array[][COL], int row){
		
	for(int colI = 0; colI < WORDLENGTH; colI++){
		if(array[row][colI] == array[0][colI]){
		printf("%c", array[row][colI]-('a'- 'A'));
		}
		else{
		printf("%c", array[row][colI]);
		}
	}
}

void misplacedLetter(char array[][COL], int row){

int foundIn;
	
	for(int colI = 0; colI < WORDLENGTH; colI++){
	foundIn = 0;
	if(array[row][colI] != array[0][colI]){
		for(int colI2 = 0; colI2 < WORDLENGTH; colI2++){
			if(array[row][colI] == array[0][colI2]){
			foundIn = 1;
			}
		}
	}
	if(foundIn == 1){
	printf("^");
	}
	else{
	printf(" ");
	}
	}
}

void divider(){
	printf("================================\n");
}

void space(int val){
	
	for(int spaceI = 0; spaceI < val; spaceI++){
		printf(" ");
	}
}

void winCondition(char array[][COL], int row, int* win){

int match = 1;

	for(int colI = 0; colI < WORDLENGTH; colI++){
		if(array[row][colI] != array[0][colI]){
		match = 0;
		}
	}
	*win = match;
}
