#define MAX_GAME_MOVES 9
#define MAX_INDIVIDUAL_MOVE 5

void draw_game(int tic_tac_toe[3][3], int player_moves[], int bot_moves[]);

bool is_game_ended(int player_moves[], int bot_moves[]);

void player_move(int tic_tac_toe[3][3], int player_moves[], int bot_moves[]);

void bot_move(int tic_tac_toe[3][3], int player_moves[], int bot_moves[]);

bool right_combination(int moves[]);

bool played(int position, int player_moves[], int bot_moves[]);

char get_played_symbol(int position, int player_moves[], int bot_moves[]);

int random_move(int player_moves[], int bot_moves[]);

bool is_game_drawn(int player_moves[], int bot_moves[]);

bool available(int player_moves[], int bot_moves[], int position);