#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
#define num_of_types_tiles 14  //not to be confused with number_of_tiles

int main()
{




    read_tiles();                                                                //function that reads all available types of tiles from the tiles.txt file and assings them to struct tiles.

    int  z, number_of_players;

	int number_of_tiles=number_of_tiles_in_file();                               //How many tiles there are?(from available_tiles.txt file);

	printf("The number of tiles in available_tiles file is %d\n",number_of_tiles);

	tile_file = fopen("available_tiles.txt", "r");
	print_available_tiles_from_file(tile_file, number_of_tiles);                 //prints how many tiles there are of each ID from available_tiles.txt.
	fclose(tile_file);                                                          //IMPORTANT:for now, it stores it in howmany_of_each_tile[tileid] LOCAL array.
                                                                                //We have to make it either global(doesnt work with automode) or make it function non-void, it has to return the array.
    puts("OK");
    /*printf("Enter the number of players:");
    scanf("%d",&number_of_players);*/
//    printf("Size of the board:");
//    scanf("%d %d", &r, &c);
   // int **arr;
//    int **arr2;
   // arr = generate_board(&number_of_tiles);
   	//system ("CLS");

   //for(z=1 ; z < number_of_tiles ; number_of_tiles--)                          //For interactive mode we dont need boardfile interaction, only once we need
   // {                                                                          //available_tiles.txt and tiles.txt interaction to load the tiles.
        //tile_file = fopen("available_tiles.txt", "r");
        board_file = fopen("board.txt", "r");
        //int x;


        print_board(board_file);
        //scanf("%d",x);
        board_writting(board);

        //fclose(tile_file);
        fclose(board_file);
    //}

    return 0;
}


void board_writting (board_point **board) {
    board_file = fopen("board.txt", "w");

    for (i = 0; i <  rows; i++) {
        for (j = 0; j < columns; j++) {
            if (board[i][j].id != 0) {
                fprintf(board_file, "%d", board[i][j].id);
                putc('_', board_file);
                fprintf(board_file, "%d", board[i][j].rotation);
            }
            if (j != (columns - 1))putc(',', board_file);
        }
        putc('\n', board_file);
    }

    fclose(board_file);
}

board_point** generate_board(FILE *fpin)
{
    int end_of_row = 0;
    columns = 1;
    rows = 0;

///////////////rows and columns counting//////////////////
    while((c=fgetc(fpin))!=EOF) {

        if ((c == ',')&&!end_of_row) columns++;
        else if (c == '\n') {
            rows++;
            end_of_row = 1;
        }
    }

///////////////memory allocation//////////////////
    board_point **arr = (board_point **)malloc(rows * sizeof(board_point *));
    for (i=0; i < rows; i++){
        arr[i] = (board_point *)malloc(columns * sizeof(board_point));
    }

///////////////setting initial values//////////////////
    for (i = 0; i <  rows; i++) {
        for (j = 0; j < columns; j++) {
            arr[i][j].id = 1;
            arr[i][j].rotation = 1;
        }
    }

///////////////reading board from a file (board.txt)//////////////////
    fpin = fopen("board.txt", "r");

    for (i = 0; i < rows; i++) {
        j = 0;
        while((c = fgetc(fpin)) != '\n') {
            if (c != ',') {
                arr[i][j].id = atoi(&c);
                c = fgetc(fpin);
                c = fgetc(fpin);
                arr[i][j].rotation = atoi(&c);
            } else {
                j++;
            }
        }
    }

    fclose(fpin);
    return arr;
}

int number_of_tiles_in_file(){
tile_file = fopen("available_tiles.txt", "r");
int noft=0;
int id;
while(fscanf(tile_file,"%d,",&id)==1){

    ++noft;

}

fclose(tile_file);

return noft;
}

void read_tiles()
{

	ftilesdef=fopen("tiles.txt","r");    //FILE
//	char oneline[100];
	puts("Available types of tiles in tiles.txt tiles. Assigning flags from tiles.txt file to array of struct tiles members such as isTemple, Left, etc");
	int tilecount=1;
//	int restline;
	int tileid[num_of_types_tiles];                 //Tile id as in board_point
	struct tiles tile[num_of_types_tiles];
	//fseek(fPointer,0,SEEK_SET);
	//while(!feof(fPointer)){
	for(int i=0;i<num_of_types_tiles;i++){

		//fseek(fPointer,-7,SEEK_END);
		fscanf(ftilesdef,"%d,%[^,],%d,%d,%d,%d,%d,%d,%d;",&tileid[tilecount],
		&tile[tilecount].name, &tile[tilecount].isTemple, &tile[tilecount].crossRoads, &tile[tilecount].bonus,
		&tile[tilecount].top, &tile[tilecount].right, &tile[tilecount].left, &tile[tilecount].bottom );

		printf("%d:,%s,%d,%d,%d,%d,%d,%d,%d\n",tileid[tilecount],
		tile[tilecount].name, tile[tilecount].isTemple, tile[tilecount].crossRoads, tile[tilecount].bonus,
		tile[tilecount].top, tile[tilecount].right, tile[tilecount].left, tile[tilecount].bottom );                     //bugchecking


		//tile[tilecount].isTemple=fgetc(fPointer);
		//int val=fgetc(fPointer);

		tilecount++;
		//TileRead(tilecount,oneline);
//		fgets(oneline,100,fPointer);
//		puts(oneline);
		//fseek(fPointer,1,SEEK_END);

	}
	puts("ok");
	fclose(ftilesdef);
	puts("okOK");



}


int intlen(int x){
    int n = 1;
    while (x /= 10)
        n++;
    return n;
}

void print_board (FILE *fpin)
{
    board = generate_board(fpin);

    int i, j;
    for (i = 0; i <  rows; i++)
    {
        if (i%2!=0)     printf("%*s", 5, "");
        for (j = 0; j < columns; j++)
        {

            if (board[i][j].id > 3)
                printf("P%d(%d,%d)%*s", board[i][j].id/10, i, j, 10-intlen(i)-intlen(j)-intlen(board[i][j].id/10)-4, "");
            else
                printf("%d(%d,%d)%*s", board[i][j].id, i, j, 10-intlen(i)-intlen(j)-intlen(board[i][j].id)-3, "");
        }
        printf("\n\n");
    }
}

void  print_available_tiles_from_file(FILE *fpin,int noft)
{
    int tileid;

    int howmany_of_each_tile[num_of_types_tiles+1];

    for(int i=0;i<=num_of_types_tiles;i++){
            howmany_of_each_tile[i]=0;
    }
 //printf("1there are %d tiles of %d id in the available_tiles file.\n",howmany_of_each_tile[14],14);

    for(int i=0;i<noft;i++){
        fscanf(fpin,"%d,",&tileid);
        howmany_of_each_tile[tileid]++;
        //printf("1b%dth time inloop there are %d tiles of %d id in the available_tiles file.\n",i,howmany_of_each_tile[14],14);

    }
 //printf("2there are %d tiles of %d id in the available_tiles file.\n",howmany_of_each_tile[14],14);
    tileid=1;
    while(tileid<=num_of_types_tiles){
            if (howmany_of_each_tile[tileid]!=0) printf("there are %d tiles of %d id in the available_tiles file.\n",howmany_of_each_tile[tileid],tileid);
            tileid++;
    }


}





/*int** generate_auxiliary_board( int r, int c )
{
    int  x, y;
   int **arr = (int **)malloc(r * sizeof(int *));
   for (x=0; x<r; x++)
        arr[x] = (int *)malloc(c * sizeof(int));

    for (x = 0; x <  r; x++)
        for (y = 0; y < c; y++)
           arr[x][y] = 0;
    return arr;
}

/*void choose_the_place (int id, int **arr){
 int x, y;
 printf("Provide coordinates");
 scanf("%d %d", &x, &y);
}

void put_tile(int l, int x, int y)
{
    int i,j;
    int **arr;
    for(i=0;i<x;i++)
        for(j=0;j<0;j++)
    if (arr[i][j] !=0)
        printf("This place is already taken");
    else if(l==1)
        arr[i][j]=1;
   else if(l==2)
    arr[i][j]=2;
    else if(l==3)
        arr[i][j]=3;
    else if(l==4)
        arr[i][j]=4;

}*/



