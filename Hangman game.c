//Hangman Game
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void man(int wrong){
    switch (wrong)
    {
    case 1:
        printf("\n__________\n|\t\t |\n|\n|\n|\n|\n|\n|\n|\n|\n|\n__________");
        break;
    case 2:
        printf("\n__________\n|\t\t |\n|\t\t O\n|\n|\n|\n|\n|\n|\n|\n|\n__________");
        break;
    case 3:
        printf("\n__________\n|\t\t |\n|\t\t O\n|\t\t/|\\ \n|\n|\n|\n|\n|\n|\n|\n__________");
        break;
    case 4:
        printf("\n__________\n|\t\t |\n|\t\t O\n|\t\t/|\\ \n|\t\t |\n|\n|\n|\n|\n|\n|\n__________");
        break;
    case 5:
        printf("\n__________\n|\t\t |\n|\t\t O\n|\t\t/|\\ \n|\t\t |\n|\t\t/\n|\n|\n|\n|\n|\n__________");
        break;
    case 6:
        printf("\n__________\n|\t\t |\n|\t\t O\n|\t\t/|\\ \n|\t\t |\n|\t\t/ \\ \n|\n|\n|\n|\n|\n__________");
        break;
        }
    
    
    
}
int check(char *word, char letter){
    for (int j = 0; word[j]!=NULL; j++)
        {
            if (letter==word[j])
            {
                printf("Yeah! That was right!");
                return 1;
            }
            
        }
        return 0;
}
int main(){
    char *words[] = {
    "apple",
    "bread",
    "cloud",
    "dance",
    "eagle",
    "flame",
    "globe",
    "house",
    "jungle",
    "kiwi"}, letter, guessword[20];
    int wrong=0,correct=0;
    srand(time(NULL));
    int index=rand()%10,gw=0;
    char *word=words[index];
    while (wrong<6 || correct!=strlen(word))
    {
        printf("Guess the letter");
        fflush(stdout);
        scanf(" %c",&letter);
        fflush(stdout);
        fflush(stdin);
        if(check(word,letter)==0){
            wrong++;
            printf("That was a wrong guess.");
            man(wrong);
        }
        else
        {
            correct++;
            guessword[gw]=letter;
            gw++;
        }
        if (wrong==6)
        {   
            printf("\n Bro You lost 💀");
            printf("\n That's enough number of guesses");
            break;
        }
        else if(strlen(guessword)==strlen(word)){
            printf("You win!!!!!");
            break;
        }
        
        
    }
    return 0;
    
    
}