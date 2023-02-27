#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char grid_rep[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int round = 0;
int move_row,move_col, inv_move_row,inv_move_col;
int for_tie;
int player2_score = 0;
int player1_score = 0;
int player_choice = 1;
char player1_initials[3];
char player2_initials[3];
bool in_game = true;
bool main_game = true;

void clear(){
   system("cls");
}

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
void show_instructions(){
    get_grid();
    printf("Welcome to TicTacToe game\n");
    printf("Instructions:\nTo start play,  first player and second need to enter his initials\n");
    printf("\nAfter that you will see game board that has 9 cells\nYour goal to fill it to get combination of 3 'x' or 'o'\n");
    printf("For doing it, you need to enter the row  number (in horizontal way) from 1 to 3 and after, enter column number (in vertical way) from 1 to 3.");

}
void show_menu(){
    printf("\nMenu\n\nPlay [1]\n\nScore History[2]\n\nShow instructions[3]\n\nExit [4]\n\n");
}
void determ_x_or_o(){
    if (move_row == 1 && move_col == 1){
        if (player_choice%2 == 1){
            grid_rep[0][0] = 'x';
        }else{
            grid_rep[0][0]='o';
        }
    }else if (move_row == 1 && move_col == 2){
        if (player_choice%2 == 1){
            grid_rep[0][1] = 'x';
        }else{
            grid_rep[0][1] = 'o';
    }

    }else if (move_row == 1 && move_col == 3){
        if (player_choice%2 == 1){
            grid_rep[0][2] = 'x';
        }else{
            grid_rep[0][2] = 'o';
        }

    }else if (move_row == 2 && move_col == 1){
        if (player_choice%2 == 1){
            grid_rep[1][0] = 'x';
        }else{
            grid_rep[1][0] = 'o';
        }

    }else if (move_row == 2 && move_col == 2){
        if (player_choice%2 == 1){
            grid_rep[1][1] = 'x';
        }else{
            grid_rep[1][1] = 'o';
        }

    }else if (move_row == 2 && move_col == 3){
        if (player_choice%2 == 1){
            grid_rep[1][2] = 'x';
        }else{
            grid_rep[1][2] = 'o';
        }

    }else if (move_row == 3 && move_col == 1){
        if (player_choice%2 == 1){
            grid_rep[2][0] = 'x';
        }else{
            grid_rep[2][0] = 'o';
        }

    }else if (move_row == 3 && move_col == 2){
        if (player_choice%2 == 1){
            grid_rep[2][1] = 'x';
        }else{
            grid_rep[2][1] = 'o';
        }

    }else if (move_row == 3 && move_col == 3){
        if (player_choice%2 == 1){
            grid_rep[2][2] = 'x';
        }
        else{
            grid_rep[2][2] = 'o';
    }
    }
}

int move_validation(){
    bool check = true;
    while(check){
    printf("\nEnter row: ");
    scanf("%d",&inv_move_row);
    printf("Enter column: ");
    scanf("%d", &inv_move_col);
    if (grid_rep[inv_move_row-1][inv_move_col-1] == 'o' || grid_rep[inv_move_row-1][inv_move_col-1] == 'x'){
        clear();
        get_grid();
        printf("This cell is already used\n");
        printf("Enter another cell\n");
    }else if(inv_move_col > 3 || inv_move_row  > 3){
        clear();
        get_grid();
        printf("This cell does not exist\n");
        printf("Enter another cell\n");

    }else{
        move_row = inv_move_row;
        move_col = inv_move_col;
        printf("\n");
        break;
        }

    }
}
void check_win(){
     //vertical checking for 'x'
    if (((grid_rep[0][0] == grid_rep[1][0] && grid_rep[2][0] == grid_rep[0][0]) && grid_rep[0][0] == 'x') || ((grid_rep[0][1] == grid_rep[1][1] && grid_rep[2][1] == grid_rep[0][1]) && grid_rep[0][1] == 'x') ||
    ((grid_rep[0][2] == grid_rep[1][2] && grid_rep[2][2] == grid_rep[0][2]) && grid_rep[0][2] == 'x')){
        clear();
        get_grid();
        printf("%s won", player1_initials);
        player1_score = player1_score + 1;
        main_game = false;
    }// vertical checking for 'o'
    else if (((grid_rep[0][0] == grid_rep[1][0] && grid_rep[2][0] == grid_rep[0][0]) && grid_rep[0][0] == 'o') || ((grid_rep[0][1] == grid_rep[1][1] && grid_rep[2][1] == grid_rep[0][1]) && grid_rep[0][1] == 'o') || ((grid_rep[0][2] == grid_rep[1][2] && grid_rep[2][2] == grid_rep[0][2]) && grid_rep[0][2] == 'o')){
        clear();
        get_grid();
        player2_score += 1;
        printf("%s won", player2_initials);
        main_game = false;
    }//horizontal checking for 'x'
    else if (((grid_rep[0][0] == grid_rep[0][1] && grid_rep[0][2] == grid_rep[0][0]) && grid_rep[0][0] == 'x') || ((grid_rep[1][0] == grid_rep[1][1] && grid_rep[1][2] == grid_rep[1][0]) && grid_rep[1][0] == 'x') ||
    ((grid_rep[2][0] == grid_rep[2][1] && grid_rep[2][2] == grid_rep[2][0]) && grid_rep[2][0] == 'x')){
        clear();
        get_grid();
        player1_score = player1_score + 1;
        printf("%s won", player1_initials);
        main_game = false;
    }// horizontal checking for 'o'
    else if (((grid_rep[0][0] == grid_rep[0][1] && grid_rep[0][2] == grid_rep[0][0]) && grid_rep[0][0] == 'o') || ((grid_rep[1][0] == grid_rep[1][1] && grid_rep[1][2] == grid_rep[1][0]) && grid_rep[1][0] == 'o') ||
    ((grid_rep[2][0] == grid_rep[2][1] && grid_rep[2][2] == grid_rep[2][0]) && grid_rep[2][0] == 'o')){
        clear();
        get_grid();
        player1_score = player2_score + 1;
        printf("%s won", player2_initials);
        main_game = false;
    //diagonal checking for 'x'
    }else if(((grid_rep[0][0] == grid_rep[1][1] && grid_rep[2][2] == grid_rep[0][0]) && grid_rep[0][0] == 'x') || (grid_rep[0][2] == grid_rep[1][1] && grid_rep[2][0] == grid_rep[0][2] && grid_rep[0][2] == 'x')){
        clear();
        get_grid();
        player1_score = player1_score + 1;
        printf("%s won", player1_initials);
        main_game = false;
    //diagonal checking for 'o'
    }else if(((grid_rep[0][0] == grid_rep[1][1] && grid_rep[2][2] == grid_rep[0][0]) && grid_rep[0][0] == 'o')|| (grid_rep[0][2] == grid_rep[1][1] && grid_rep[2][0] == grid_rep[0][2] && grid_rep[0][2] == 'o')){
        clear();
        get_grid();
        player2_score = player2_score + 1;
        printf("%s won", player2_initials);
        main_game = false;
    }else{
        if(for_tie == 9){
            clear();
            get_grid();
            printf("Tie");
            main_game = false;
        }
    }
}

void write_to_file(){
    FILE *fptr;
    fptr = fopen("score.txt","a");
    fprintf(fptr,"Number of rounds: %d\n", round);
    fprintf(fptr,"%s : %d\n",player1_initials, player1_score);
    fprintf(fptr,"%s : %d\n",player2_initials, player2_score);
    fprintf(fptr,"\n");
    fclose(fptr);
}

void play(){
    int to_menu;
    clear();
    printf("Welcome to Tic-tac-toe game\n");
    printf("Player 1, please enter your initials: ");
    scanf("%s", player1_initials);
    printf("Player 2, please enter your initials: ");
    scanf("%s", player2_initials);
    printf("\n%s your sign -- 'x'\n",player1_initials);
    printf("\n%s your sign -- 'o'\n\n",player2_initials);
    sleep(5);
    while (in_game){
        round += 1;
        main_game = true;
       while(main_game){
        clear();
        for_tie += 1;
        printf("In game\n");
        printf("Round %d\n", round);
        get_grid();
        if (player_choice%2 == 1){
            printf("%s ", player1_initials);
        }else{
            printf("%s ", player2_initials);
        }
        printf("make a move");
        move_validation();
        determ_x_or_o();
        check_win();
        player_choice +=1;
        if (main_game == false){
            break;
        }
       }
        printf("\n");
        printf("Continue game [1]\n");
        printf("To go to menu [2]\nEnter: ");
        scanf("%d", &to_menu);
            if(to_menu == 1){
                for (int i = 0; i < 3;i++){
                    for(int j = 0;j < 3 ;j++ ){
                        grid_rep[i][j] = ' ';
                    }
                }

            for_tie = 0;
            in_game = true;
            clear();
        }
        else if(to_menu == 2){
            for (int i = 0; i < 3;i++){
                for(int j = 0;j < 3 ;j++ ){
                    grid_rep[i][j] = ' ';
                    }
                }

            write_to_file();
            for_tie = 0;
            player2_score = 0;
            player1_score = 0;
            in_game = false;
            main_game = false;
            round = 0;
        }
    }


clear();
}





int main()
{
    int close_instr;
    int close_history;
    bool in_program = true;
    int menu;
    while (in_program){
        show_menu();
        printf("Enter: ");
        scanf("%d", &menu);
        printf("\n");
        show_menu();
        switch(menu){
            case 1:
                main_game = true;
                in_game = true;
                play();
                break;
            case 2:
                clear();
                FILE *fp;
                char ch;
                fp = fopen("score.txt", "r");
                printf("Score History:\n\n");
                if (fp == NULL) {
                printf("No game history in this file.\n");
                sleep(5);
                break;
                }
                while ((ch = fgetc(fp)) != EOF) {
                    printf("%c", ch);
                }

                while(true){
                    printf("\nClose[1]");
                    printf("\nEnter: ");
                    scanf("%d", &close_history);
                    if (close_history == 1){
                        fclose(fp);
                        clear();
                        break;

                    }else{
                        printf("\nEnter the proper value");
                    }
                }
                break;
            case 3:
                clear();
                show_instructions();
                while(true){
                    printf("\nClose[1]");
                    printf("\nEnter: ");
                    scanf("%d", &close_instr);
                    if (close_instr == 1){
                        clear();
                        break;

                    }else{
                        printf("\nEnter the proper value");
                    }
                }
                break;
            case 4:
                clear();
                exit(0);
                break;
            default:
                printf("Choose the option\n");
                break;
        }
        clear();
    }
    clear();
    return 0;
}
