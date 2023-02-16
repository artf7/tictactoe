#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

char grid_rep[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char player1_name[3];
char player2_name[3];
bool is_playing = true; 
bool primary = true; 
int move_row,move_col, inv_move_row,inv_move_col;
bool move_validation = true;
int what_player = 1;

void get_grid(){
    printf("    1     2     3   \n");
    printf("  -----+-----+-----\n");
    printf("1   %c  |  %c  |  %c   \n", grid_rep[0][0],grid_rep[0][1],grid_rep[0][2]);
    printf("  -----+-----+-----\n");
    printf("2   %c  |  %c  |  %c  \n", grid_rep[1][0],grid_rep[1][1],grid_rep[1][2]);
    printf("  -----+-----+-----\n");
    printf("3   %c  |  %c  |  %c  \n", grid_rep[2][0],grid_rep[2][1],grid_rep[2][2]);
    printf("  -----+-----+-----\n");
}
void check_for_win(){
     //vertical checking for 'x'
    if (((grid_rep[0][0] == grid_rep[1][0] && grid_rep[2][0] == grid_rep[0][0]) && grid_rep[0][0] == 'x') || ((grid_rep[0][1] == grid_rep[1][1] && grid_rep[2][1] == grid_rep[0][1]) && grid_rep[0][1] == 'x') ||
    ((grid_rep[0][2] == grid_rep[1][2] && grid_rep[2][2] == grid_rep[0][2]) && grid_rep[0][2] == 'x')){ 
        system("clear");
        get_grid();
        printf("%s won", player1_name);
        is_playing = false;
    }// vertical checking for 'o'
    else if (((grid_rep[0][0] == grid_rep[1][0] && grid_rep[2][0] == grid_rep[0][0]) && grid_rep[0][0] == 'o') || ((grid_rep[0][1] == grid_rep[1][1] && grid_rep[2][1] == grid_rep[0][1]) && grid_rep[0][1] == 'o') || ((grid_rep[0][2] == grid_rep[1][2] && grid_rep[2][2] == grid_rep[0][2]) && grid_rep[0][2] == 'o')){
        system("clear");
        get_grid();
        printf("%s won", player2_name);
        is_playing = false;
    }//horizontal checking for 'x'
    else if (((grid_rep[0][0] == grid_rep[0][1] && grid_rep[0][2] == grid_rep[0][0]) && grid_rep[0][0] == 'x') || ((grid_rep[1][0] == grid_rep[1][1] && grid_rep[1][2] == grid_rep[1][0]) && grid_rep[1][0] == 'x') ||
    ((grid_rep[2][0] == grid_rep[2][1] && grid_rep[2][2] == grid_rep[2][0]) && grid_rep[2][0] == 'x')){ 
        system("clear");
        get_grid();
        printf("%s won", player1_name);
        is_playing = false;
    }// horizontal checking for 'o'
    else if (((grid_rep[0][0] == grid_rep[0][1] && grid_rep[0][2] == grid_rep[0][0]) && grid_rep[0][0] == 'o') || ((grid_rep[1][0] == grid_rep[1][1] && grid_rep[1][2] == grid_rep[1][0]) && grid_rep[1][0] == 'o') ||
    ((grid_rep[2][0] == grid_rep[2][1] && grid_rep[2][2] == grid_rep[2][0]) && grid_rep[2][0] == 'o')){
        system("clear");
        get_grid();
        printf("%s won", player2_name);
        is_playing = false;
        
    //diagonal checking for 'x'
    }else if(((grid_rep[0][0] == grid_rep[1][1] && grid_rep[2][2] == grid_rep[0][0]) && grid_rep[0][0] == 'x')){
        system("clear");
        get_grid();
        printf("%s won", player1_name);
        is_playing = false;
    }else if(((grid_rep[0][2] == grid_rep[1][1] && grid_rep[2][0] == grid_rep[0][2]) && grid_rep[0][2] == 'y')){
        system("clear");
        get_grid();
        printf("%s won", player2_name);  
        is_playing = false;
    }
}

void play(player1_name, player2_name){
    get_grid();
    if(what_player%2 == 1){
        printf("%s ", player1_name);
    }else{
        printf("%s ", player2_name);
    }
    printf("make move");
    while (move_validation)
    {
    printf("\nEnter row: ");
    scanf("%d",&inv_move_row);
    printf("Enter column: ");
    scanf("%d", &inv_move_col);
    if (grid_rep[inv_move_row-1][inv_move_col-1] == 'o' || grid_rep[inv_move_row-1][inv_move_col-1] == 'x'){
        system("clear");
        get_grid();
        printf("This cell is aleady used\n");
        printf("Enter another cell\n");
    }else if(inv_move_col > 3 || inv_move_row  > 3){
        system("clear");
        get_grid();
        printf("This cell does not exist\n");
        printf("Enter another cell\n");
        system("clear");
    }else{
        move_row = inv_move_row;
        move_col = inv_move_col;
        break;
    }
    
    }
    printf("\n");
    // chosing what move will it be 'x' or 'o' 
    if (move_row == 1 && move_col == 1){
        if (what_player%2 == 1){
            grid_rep[0][0] = 'x';
        }else{
            grid_rep[0][0]='o';
        }

    }else if (move_row == 1 && move_col == 2){
        if (what_player%2 == 1){
            grid_rep[0][1] = 'x';
        }else{
            grid_rep[0][1] = 'o';
        }

    }else if (move_row == 1 && move_col == 3){
        if (what_player%2 == 1){
            grid_rep[0][2] = 'x';
        }else{
            grid_rep[0][2] = 'o';
        }

    }else if (move_row == 2 && move_col == 1){
        if (what_player%2 == 1){
            grid_rep[1][0] = 'x';
        }else{
            grid_rep[1][0] = 'o';
        }
        
    }else if (move_row == 2 && move_col == 2){
        if (what_player%2 == 1){
            grid_rep[1][1] = 'x';
        }else{
            grid_rep[1][1] = 'o';
        }
        
    }else if (move_row == 2 && move_col == 3){
        if (what_player%2 == 1){
            grid_rep[1][2] = 'x';
        }else{
            grid_rep[1][2] = 'o';
        }

    }else if (move_row == 3 && move_col == 1){
        if (what_player%2 == 1){
            grid_rep[2][0] = 'x';
        }else{
            grid_rep[2][0] = 'o';
        }
        
    }else if (move_row == 3 && move_col == 2){
        if (what_player%2 == 1){
            grid_rep[2][1] = 'x';
        }else{
            grid_rep[2][1] = 'o';
        }
        
    }else if (move_row == 3 && move_col == 3){
        if (what_player%2 == 1){
            grid_rep[2][2] = 'x';
        }
        else{
            grid_rep[2][2] = 'o';
    }
    }
    check_for_win();
    what_player += 1;
    system("clear");
}
int main(){
    printf("Welcome to TicTacToe game\n");
    printf("Player 1 enter your initials: ");
    scanf("%s",player1_name);
    printf("Player 2 enter your initials: ");
    scanf("%s", player2_name);
    while (is_playing){
        play(player1_name, player2_name);
    }
    return 0;
}
