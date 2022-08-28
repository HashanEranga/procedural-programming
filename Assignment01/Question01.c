#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// generating computer choice (random)
// computer will generate either 0, 1, 2 then return that number after add 1
int genCompChoice();

/*
    identify and convert the player's selection
    if input is R or r for rock the assigned integer was 1
    if input is P or p for paper the assigned integer was 2
    if input is S or s for scissor the assigned integer was 3
    for any other invalid input the assigned integer was 0
*/
int sortInput(char input);
/*
    show the selected choice in plain text
    if input is 1 then rock 
    if input is 2 then paper
    if input is 3 then scissor
    for any other invalid input the assigned value is Invalid Selection
*/
void showChoice(int input);

/*
    determine the winner
    player's and computer's choices will be compared and determine win lose or draw
    if the difference is 1 the one who have the higher integer value is the winner 
    otherwise the one who have the less number wins
*/
void detWinner(char input, int compChoice);

int main(int argc, char const *argv[])
{
    // introduce the game rules 
    printf("=================================================================\n");
    printf("█▀█ █▀█ █▀▀ █▄▀   █▀█ ▄▀█ █▀█ █▀▀ █▀█   █▀ █▀▀ █ █▀ █▀ █▀█ █▀█ █▀\n");    
    printf("█▀▄ █▄█ █▄▄ █░█   █▀▀ █▀█ █▀▀ ██▄ █▀▄   ▄█ █▄▄ █ ▄█ ▄█ █▄█ █▀▄ ▄█\n");
    printf("=================================================================\n");
    printf("\t \t \t Game Rules\n");
    printf("-----------------------------------------------------------------\n");
    printf("Player should input one of the following : \n");
    printf("\t R/r - For Rock\n");
    printf("\t P/p - For Paper\n");
    printf("\t S/s - For Scissors\n");
    printf("After player input either of the input computer will randomly generate a choice\n");
    printf("Both players have the same the game will be a draw\n");
    printf("If rock and paper the paper wins\n");
    printf("If paper and scissors the scissors wins\n");
    printf("If scissors and rock the rock wins\n");
    printf("\n");
    printf("-----------------------------------------------------------------\n");
    printf("\t \t \t Game begins\n");
    printf("-----------------------------------------------------------------\n");

    // get user inputs 
    char input;

    // initiate an infinite loop for getting user inputs
    while(1){
        printf("Enter your choice : ");
        scanf(" %c", &input);
        printf("Choice was %c \n", input);
        int compChoice = genCompChoice();
        detWinner(input, compChoice);
    }

    return 0;
}

int genCompChoice(){
    int choice = rand()%3;
    return ++choice;
}

int sortInput(char input){
    if (input == 'R' || input == 'r')
        return 1;
    if (input == 'P' || input == 'p')
        return 2;
    if (input == 'S' || input == 's')
        return 3;
    return 0;
}

void showChoice(int input){
    if (input == 1) printf("Rock\n");
    else if (input == 2) printf("Paper\n");
    else if (input == 3) printf("Scissors\n");
    else {
        printf("Invalid Selection\n");
        exit(-1);
    }
}

void detWinner(char input, int compChoice){
    int playerChoice = sortInput(input);
    printf("Player's Choice : "); 
    showChoice(playerChoice);
    printf("Computer's Choice : "); 
    showChoice(compChoice);

    if(((playerChoice-compChoice) == 1) || ((compChoice-playerChoice) == 2))  printf("Player Wins\n");
    else if(((compChoice-playerChoice) == 1) || (playerChoice-compChoice) == 2) printf("Computer Wins\n");
    else if (compChoice == playerChoice) printf("Draw!\n");
}
