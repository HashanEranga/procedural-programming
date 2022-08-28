#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int genCompChoice();
int sortInput(char input);
void showChoice(int input);
void detWinner(char input, int compChoice);

int main(int argc, char const *argv[])
{
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
    char input;
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
    else printf("Invalid Selection\n");
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
    else {
        printf("Program End : Player input is invalid");
        exit(-1);
    }
}
