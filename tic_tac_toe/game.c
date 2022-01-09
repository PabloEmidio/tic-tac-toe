#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

#include "game.h"
#include "utils.h"




void draw_game(int tic_tac_toe[3][3], int player_moves[], int bot_moves[]){
    for (int i = 0; i < 3; i++){
        printf("\t");
        for (int j = 0; j < 3; j++){
            bool last_loop = j != 2;
            if(!played(tic_tac_toe[i][j], player_moves, bot_moves)){
                printf("%s%d%s", last_loop ? "" : "", tic_tac_toe[i][j], last_loop ? "    |    " : "");
            } else{
                char symbol = get_played_symbol(tic_tac_toe[i][j], player_moves, bot_moves);
                printf("%s%c%s", last_loop ? "" : "", symbol, last_loop ? "    |    " : "");
            }
        }
        printf("%s", i != 2 ? "\n  ---------------------------------\n" : "\n");
    }
}

bool is_game_ended(int player_moves[], int bot_moves[]){
    return is_game_drawn(player_moves, bot_moves) || right_combination(player_moves) || right_combination(bot_moves);
}

void player_move(int tic_tac_toe[3][3], int player_moves[], int bot_moves[]){
    system(CLEAR);
    draw_game(tic_tac_toe, player_moves, bot_moves);
    sleep(0.8);

    if (size(player_moves) == MAX_INDIVIDUAL_MOVE) {
        exit(1);
    }

    int move = 0;
    bool already_played = false;

    do {

        already_played = false;

        printf("\n\nMake your move: ");
        scanf("%d", &move);

        if (move > 9 || move < 1){
            printf("The option %d is not allowed\n", move);
            already_played = true;
            continue;
        }

        if(has(player_moves, move) || has(bot_moves, move)){
            already_played = true;
            printf("The option %d was already played\n", move);
            continue;
        }

    } while(already_played);

    register_value(move, player_moves);
}

void bot_move(int tic_tac_toe[3][3], int player_moves[], int bot_moves[]){
    system(CLEAR);
    draw_game(tic_tac_toe, player_moves, bot_moves);
    printf("\n\nBot is playing...\n");
    sleep(2);

    int move = 0;
    if (size(bot_moves) == MAX_INDIVIDUAL_MOVE) {
        exit(1);
    }

    // horizontal moves case
    if           (has(bot_moves, 1) && has(bot_moves, 2) && !(has(bot_moves, 3) || has(player_moves, 3))) move = 3;
    else if      (has(bot_moves, 1) && has(bot_moves, 3) && !(has(bot_moves, 2) || has(player_moves, 2))) move = 2;
    else if      (has(bot_moves, 2) && has(bot_moves, 3) && !(has(bot_moves, 1) || has(player_moves, 1))) move = 1;

    else if      (has(bot_moves, 4) && has(bot_moves, 5) && !(has(bot_moves, 6) || has(player_moves, 6))) move = 6;
    else if      (has(bot_moves, 4) && has(bot_moves, 6) && !(has(bot_moves, 5) || has(player_moves, 5))) move = 5;
    else if      (has(bot_moves, 5) && has(bot_moves, 6) && !(has(bot_moves, 4) || has(player_moves, 4))) move = 4;

    else if      (has(bot_moves, 7) && has(bot_moves, 8) && !(has(bot_moves, 9) || has(player_moves, 9))) move = 9;
    else if      (has(bot_moves, 7) && has(bot_moves, 9) && !(has(bot_moves, 8) || has(player_moves, 8))) move = 8;
    else if      (has(bot_moves, 8) && has(bot_moves, 9) && !(has(bot_moves, 7) || has(player_moves, 7))) move = 7;

    // vertical moves case
    else if      (has(bot_moves, 1) && has(bot_moves, 4) && !(has(bot_moves, 7) || has(player_moves, 7))) move = 7;
    else if      (has(bot_moves, 1) && has(bot_moves, 7) && !(has(bot_moves, 4) || has(player_moves, 4))) move = 4;
    else if      (has(bot_moves, 4) && has(bot_moves, 7) && !(has(bot_moves, 1) || has(player_moves, 1))) move = 1;

    else if      (has(bot_moves, 2) && has(bot_moves, 5) && !(has(bot_moves, 8) || has(player_moves, 8))) move = 8;
    else if      (has(bot_moves, 2) && has(bot_moves, 8) && !(has(bot_moves, 5) || has(player_moves, 5))) move = 5;
    else if      (has(bot_moves, 5) && has(bot_moves, 8) && !(has(bot_moves, 2) || has(player_moves, 2))) move = 2;

    else if      (has(bot_moves, 3) && has(bot_moves, 6) && !(has(bot_moves, 9) || has(player_moves, 9))) move = 9;
    else if      (has(bot_moves, 3) && has(bot_moves, 9) && !(has(bot_moves, 6) || has(player_moves, 6))) move = 6;
    else if      (has(bot_moves, 6) && has(bot_moves, 9) && !(has(bot_moves, 3) || has(player_moves, 3))) move = 3;

    // diagonal moves case
    else if      (has(bot_moves, 1) && has(bot_moves, 5) && !(has(bot_moves, 9) || has(player_moves, 9))) move = 9;
    else if      (has(bot_moves, 1) && has(bot_moves, 9) && !(has(bot_moves, 5) || has(player_moves, 5))) move = 5;
    else if      (has(bot_moves, 5) && has(bot_moves, 9) && !(has(bot_moves, 1) || has(player_moves, 1))) move = 1;

    else if      (has(bot_moves, 1) && has(bot_moves, 5) && !(has(bot_moves, 9) || has(player_moves, 9))) move = 9;
    else if      (has(bot_moves, 1) && has(bot_moves, 9) && !(has(bot_moves, 5) || has(player_moves, 5))) move = 5;
    else if      (has(bot_moves, 5) && has(bot_moves, 9) && !(has(bot_moves, 1) || has(player_moves, 1))) move = 1;

    // moves that stop the player's winning
    else if(has(player_moves, 2) && has(player_moves, 3) && !(has(player_moves, 1) || has(bot_moves, 1))) move = 1;
    else if(has(player_moves, 5) && has(player_moves, 9) && !(has(player_moves, 1) || has(bot_moves, 1))) move = 1;
    else if(has(player_moves, 4) && has(player_moves, 7) && !(has(player_moves, 1) || has(bot_moves, 1))) move = 1;

    else if(has(player_moves, 1) && has(player_moves, 3) && !(has(player_moves, 2) || has(bot_moves, 2))) move = 2;
    else if(has(player_moves, 5) && has(player_moves, 8) && !(has(player_moves, 2) || has(bot_moves, 2))) move = 2;

    else if(has(player_moves, 2) && has(player_moves, 1) && !(has(player_moves, 3) || has(bot_moves, 3))) move = 3;
    else if(has(player_moves, 6) && has(player_moves, 9) && !(has(player_moves, 3) || has(bot_moves, 3))) move = 3;
    else if(has(player_moves, 5) && has(player_moves, 7) && !(has(player_moves, 3) || has(bot_moves, 3))) move = 3;

    else if(has(player_moves, 5) && has(player_moves, 6) && !(has(player_moves, 4) || has(bot_moves, 4))) move = 4;
    else if(has(player_moves, 1) && has(player_moves, 7) && !(has(player_moves, 4) || has(bot_moves, 4))) move = 4;

    else if(has(player_moves, 4) && has(player_moves, 6) && !(has(player_moves, 5) || has(bot_moves, 5))) move = 5;
    else if(has(player_moves, 3) && has(player_moves, 7) && !(has(player_moves, 5) || has(bot_moves, 5))) move = 5;
    else if(has(player_moves, 2) && has(player_moves, 8) && !(has(player_moves, 5) || has(bot_moves, 5))) move = 5;
    else if(has(player_moves, 1) && has(player_moves, 9) && !(has(player_moves, 5) || has(bot_moves, 5))) move = 5;

    else if(has(player_moves, 4) && has(player_moves, 5) && !(has(player_moves, 6) || has(bot_moves, 6))) move = 6;
    else if(has(player_moves, 3) && has(player_moves, 9) && !(has(player_moves, 6) || has(bot_moves, 6))) move = 6;

    else if(has(player_moves, 8) && has(player_moves, 9) && !(has(player_moves, 7) || has(bot_moves, 7))) move = 7;
    else if(has(player_moves, 1) && has(player_moves, 4) && !(has(player_moves, 7) || has(bot_moves, 7))) move = 7;
    else if(has(player_moves, 3) && has(player_moves, 5) && !(has(player_moves, 7) || has(bot_moves, 7))) move = 7;
    
    else if(has(player_moves, 6) && has(player_moves, 7) && !(has(player_moves, 8) || has(bot_moves, 8))) move = 8;
    else if(has(player_moves, 2) && has(player_moves, 5) && !(has(player_moves, 8) || has(bot_moves, 8))) move = 8;

    else if(has(player_moves, 7) && has(player_moves, 8) && !(has(player_moves, 9) || has(bot_moves, 9))) move = 9;
    else if(has(player_moves, 3) && has(player_moves, 6) && !(has(player_moves, 9) || has(bot_moves, 9))) move = 9;
    else if(has(player_moves, 1) && has(player_moves, 5) && !(has(player_moves, 9) || has(bot_moves, 9))) move = 9;

    // else move
    else move = random_move(player_moves, bot_moves);
    register_value(move, bot_moves);
}

bool right_combination(int moves[]){
    bool winning = false; 

    for(int i = 0; i < MAX_INDIVIDUAL_MOVE; i++){

        if(has(moves, 1) && has(moves, 2) && has(moves, 3)){
            winning = true;
            break;
        }
        else if(has(moves, 4) && has(moves, 5) && has(moves, 6)){
            winning = true;
            break;
        }
        else if(has(moves, 7) && has(moves, 8) && has(moves, 9)){
            winning = true;
            break;
        }


        else if(has(moves, 1) && has(moves, 4) && has(moves, 7)){
            winning = true;
            break;
        }
        else if(has(moves, 2) && has(moves, 5) && has(moves, 8)){
            winning = true;
            break;
        }
        else if(has(moves, 3) && has(moves, 6) && has(moves, 9)){
            winning = true;
            break;
        }


        else if(has(moves, 1) && has(moves, 5) && has(moves, 9)){
            winning = true;
            break;
        }
        else if(has(moves, 3) && has(moves, 5) && has(moves, 7)){
            winning = true;
            break;
        }
    }
    return winning;
}

bool played(int position, int player_moves[], int bot_moves[]){
    return has(bot_moves, position) || has(player_moves, position);
}

char get_played_symbol(int position, int player_moves[], int bot_moves[]){
    char symbol;
    if(has(player_moves, position)){
        symbol = 'X';
    } 
    else if(has(bot_moves, position)){
        symbol = 'O';
    }
    else{
        exit(2);
    }
    return symbol;
}

int random_move(int player_moves[], int bot_moves[]){
    int random = 0;

    srand(time(0));

    do{
        random = (rand() % 9) + 1;
    } while(has(player_moves, random) || has(bot_moves, random));
    return random;
}

bool is_game_drawn(int player_moves[], int bot_moves[]){
    return size(player_moves) + size(bot_moves) > MAX_GAME_MOVES;
}