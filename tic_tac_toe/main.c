#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game.h"
#include "utils.h"

int main(){
    int tic_tac_toe[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    int player_moves[MAX_INDIVIDUAL_MOVE] = {0, 0, 0, 0, 0};
    int bot_moves[MAX_INDIVIDUAL_MOVE] = {0, 0, 0, 0, 0};
    
    bool ended = false;
    
    do {
        ended = player_move(tic_tac_toe, player_moves, bot_moves);
        if(ended) break;

        ended = bot_move(tic_tac_toe, player_moves, bot_moves);
        if(ended) break;
    } while(!game_ended(player_moves, bot_moves));

    if(right_combination(player_moves)){
        printf("    XXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        printf("  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        printf(" XXXXXXXXXXXXXXXXXX         XXXXXXXX\n");
        printf("XXXXXXXXXXXXXXXX              XXXXXXX\n");
        printf("XXXXXXXXXXXXX                   XXXXX\n");
        printf(" XXX     _________ _________     XXX      You\n");
        printf("  XX    I  _xxxxx I xxxxx_  I    XX        Won\n");
        printf(" ( X----I         I         I----X )         The\n");
        printf("( +I    I      00 I 00      I    I+ )          Game\n");
        printf(" ( I    I    __0  I  0__    I    I )\n");
        printf("  (I    I______ /   \\_______I    I)\n");
        printf("   I           ( ___ )           I\n");
        printf("   I    _  :::::::::::::::  _    i\n");
        printf("    \\    \\___ ::::::::: ___/    /\n");
        printf("     \\_      \\_________/      _/\n");
        printf("       \\        \\___,        /\n");
        printf("         \\                 /\n");
        printf("          |\\             /|\n");
        printf("          |  \\_________/  |\n");
    } 
    else if(right_combination(bot_moves)) {
        printf("   ____          ____\n");
        printf("    |oooo|        |oooo|\n");
        printf("    |oooo| .----. |oooo|\n");
        printf("    |Oooo|/\\_||_/\\|oooO|\n");
        printf("    `----' / __ \\ `----'\n");
        printf("    ,/ |#|/\\/__\\/\\|#| \\,\n");
        printf("   /  \\|#|| |/\\| ||#|/  \\\n");
        printf("  / \\_/|_|| |/\\| ||_|\\_/ \\\n");
        printf(" |_\\/    o\\=----=/o    \\/_|\n");
        printf(" <_>      |=\\__/=|      <_>\n");
        printf(" <_>      |------|      <_>     I\n");
        printf(" | |   ___|======|___   | |      Won\n");
        printf("//\\\\  / |O|======|O| \\  //\\\\      The\n");
        printf("|  |  | |O+------+O| |  |  |       Game\n");
        printf("|\\/|  \\_+/        \\+_/  |\\/|        HAHAHAHA\n");
        printf("\\__/  _|||        |||_  \\__/\n");
        printf("      | ||        || |\n");
        printf("     [==|]        [|==]\n");
        printf("     [===]        [===]\n");
        printf("      >_<          >_<\n");
        printf("     || ||        || ||\n");
        printf("     || ||        || ||\n");
        printf("     || ||        || ||\n");
        printf("   __|\\_/|__    __|\\_/|__\n");
        printf("  /___n_n___\\  /___n_n___\\\n");
    } else {
        printf("                                 ,        ,\n");
        printf("                                /(        )`\n");
        printf("                                \\ \\___   / |\n");
        printf("                                /- _  `-/  '\n");
        printf("                               (/\\/ \\ \\   /\\\n");
        printf("                               / /   | `    \\\n");
        printf("                               O O   ) /    |\n");
        printf("                               `-^--'`<     '\n");
        printf("             We drawn         (_.)  _  )   /\n");
        printf("                               `.___/`    /\n");
        printf("                                 `-----' /\n");
        printf("                    <----.     __ / __   \\\n");
        printf("                    <----|====O)))==) \\) /====\n");
        printf("                    <----'    `--' `.__,' \\\n");
        printf("                                 |        |\n");
        printf("                                  \\       /\n");
        printf("                             ______( (_  / \\______\n");
        printf("                           ,'  ,-----'   |        \\\n");
        printf("                           `--{__________)        \\/\n");

    }

    printf("\n\n");
    draw_game(tic_tac_toe, player_moves, bot_moves);
    printf("\n\n");

    return 0;
}