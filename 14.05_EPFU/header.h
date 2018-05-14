typedef struct {
    int id;
    int rotation;
} board_point;

struct tiles{
char name[100];
int isTemple;
int crossRoads;
int bonus;
int top;
int right;
int left;
int bottom;
};

void read_tiles();                                  //
void board_writting (board_point **board);          //
board_point** generate_board(FILE *fpin);           //
//int** generate_auxiliary_board( int r, int c );     //
void print_board (FILE *fpin);
void  print_available_tiles_from_file(FILE *fpin,int noft);
//void choose_the_place (int id, int **arr);
//void put_tile(int l, int x, int y);
int intlen(int x);
int number_of_tiles_in_file();
//int r, c;
int columns, rows, i, j;
char c;
FILE *tile_file, *board_file, *ftilesdef;;
board_point **board;

