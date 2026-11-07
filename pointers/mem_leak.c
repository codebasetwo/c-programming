#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
"Simple betting game"
"Jack Queen King" - computer shuffles these cards
Player has to gues the position of Queen
if he wins he takes 3*bet
if he losses he losses the bet amount
player has $100 intially
*/
int cash = 100;

void play(int bet)
{
    // char C[3] = {'J', 'Q', 'K'}; // on stack
    // memory consumption when you dont free 
    // call to play keep crating memoey on heap without freeing 
    // thereby using up memory
    char * C = (char*)malloc(sizeof(char) * 3); // on heap becomes garbage if not deallocated
    C[0] = 'J'; C[1] = 'K'; C[2] = 'Q';
    printf("Shuffling...");
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int tmp = C[x];
        C[x] = C[y];
        C[y] = tmp;
    }

    int player_guess;
    printf("What's the position of Queen 1, 2, or 3? ");
    scanf("%d", &player_guess);
    if(C[player_guess - 1] == 'Q') {
        cash += 3*bet;
        printf(" You win! result = \"%c %c %c\" Total cash = %d\n", C[0], C[1], C[2], cash);
    }else {
        cash -= bet;
        printf(" You lose! result = \"%c %c %c\" Total cash = %d\n", C[0], C[1], C[2], cash);
    }
    free(C); // calling free here does not use up memory it deallocates it for next call
}
int main(){
    int bet;
    printf("**Welcome to virtual casino**\n");
    printf("Total cash = $%d\n", cash);
    while (cash > 0) {
        printf("What's your bet $:");
        scanf("%d", &bet);
        if (bet == 0 || bet > cash) break;
        play(bet); 
        printf("\n*******************\n")  ;
    }

}
