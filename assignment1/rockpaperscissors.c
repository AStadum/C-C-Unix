/* Anders Stadum
** CIS330
** Assignment 1
** 01-13-2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>

char* getUserChoice() {
    /* Prompt the user "Enter rock, paper, or scissors: " and return
       the string they enter */
    char* input = malloc(sizeof(char) * 128); //create unknown string size
    printf("Enter rock, paper, or scissors: "); //enter string
    scanf("%s", input); //take in input 
    return input; //return inputted text
}

char* getComputerChoice() {
    srand (time(NULL));
    /* get a pseudo-random integer between 0 and 2 (inclusive) */
    int randChoice = rand() % 3; //randomize 3 choices
    char* compChoice = malloc(sizeof(char) * 128); //create another string


    /* If randChoice is 0, return "rock", otherwise if randChoice is 1, 
     return "paper", and if randChoice is 2, return "scissors". */
    if(randChoice == 0) 
    { //choice 1 is rock
        strcpy(compChoice, "rock");
    }
    if(randChoice == 1) 
    { //choice 2 is paper
        strcpy(compChoice, "paper");  
    }
    else 
    {                  //choice 3 is scissors
        strcpy(compChoice, "scissors");
    }
    return compChoice; //return computer choice

}

char* compare(char* choice1, char* choice2) 
{
    /* Implement the logic of the game here. If choice1 and choice2
     are equal, the result should be "This game is a tie."

     Make sure to use strcmp for string comparison.
     */
     char* comChoice = malloc(sizeof(char) * 128); //create another string
     int valueCompare = strcmp(choice1,choice2); //compares both choices, used for tie
     
     if(valueCompare == 0) //if the two choices are the same, the game is a tie
     {
        strcpy(comChoice, "This game is a tie");
     }
     else
     {
         if ((strcmp(choice1, "rock") == 0 && strcmp(choice2, "paper") == 0) || 
             (strcmp(choice1,"paper") == 0 && strcmp(choice2, "scissors") == 0) ||
             (strcmp(choice1, "scissors") == 0 && strcmp(choice2, "rock") == 0))
         {
             strcpy(comChoice, choice2); 
             strcat(comChoice, " Wins!");
         }
         else
         {  
             strcpy(comChoice, choice1);       
             strcat(comChoice, " Wins!");
         }
     }
     return comChoice;
}

int main(int argc, char** argv) 
{
    char *userChoice, *computerChoice, *outcome; //pointers to specific functions
    char* r = malloc(sizeof(char) * 128); //create string
    do
    {
        userChoice = getUserChoice();
        printf("You picked %s.\n", userChoice);
        
        computerChoice = getComputerChoice();
        printf("Computer picked %s.\n", computerChoice);
        
        outcome = compare(userChoice, computerChoice);
        printf("%s\n", outcome);
        printf("Play again? ");
        scanf("%s",r);
    }
    while(strcmp(r, "yes") == 0 || strcmp(r, "Y") == 0 || strcmp(r, "YES") == 0 || strcmp(r, "y") == 0); //to repeat press one the of following options
    free(r); //free malloc memory in r
    free(userChoice); //free malloc memory in the userChoice function
    free(computerChoice); //free malloc memory in the computerChoice function
    free(outcome); //free malloc memory in main; outcome.
    return 0;
}

//4685
