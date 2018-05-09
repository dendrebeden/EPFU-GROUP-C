#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct board_point {
    int id;
    int rotation;
};

int columns;
int rows;
FILE *tile_file, *board_file;
struct board_point **board;



struct board_point** generate_board(FILE *fpin)
{
    char c;
    int end_of_row = 0;
    columns = 1;
    rows = 0;
    while((c=fgetc(fpin))!=EOF) {
        
//        printf("%c", c);
        
        if ((c == ',')&&!end_of_row) columns++;
        else if (c == '\n') {
            rows++;
            end_of_row = 1;
        }
    }
    
    int i,j;
    
    struct board_point **arr = (struct board_point **)malloc(rows * sizeof(struct board_point *));
    for (i=0; i < rows; i++)
        arr[i] = (struct board_point *)malloc(columns * sizeof(struct board_point));
    
    for (i = 0; i <  rows; i++) {
        for (j = 0; j < columns; j++) {
            arr[i][j].id = 0;
        }
    }
    
    return arr;
}

//int** generate_auxiliary_board( int r, int c )
//{
//    int  x, y;
//    int **arr = (int **)malloc(r * sizeof(int *));
//    for (x=0; x<r; x++)
//        arr[x] = (int *)malloc(c * sizeof(int));
//
//    for (x = 0; x <  r; x++)
//        for (y = 0; y < c; y++)
//            arr[x][y] = 0;
//    return arr;
//}

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

int  print_tiles()
{
    int g , h, i, j, l;
    g=h=j=i=3;
    printf("1,0,0,0,0,1,0  x%d \n", g);
    printf("2,0,0,0,0,0,0  x%d \n", h);
    printf("3,0,1,2,2,2,2  x%d \n", i);
    printf("4,0,0,1,2,1,0  x%d \n", j);
    printf("Input index of tile you want to pick: ");
    scanf("%d", &l);
    if(l==1){
        g--;
    }else if(l==2){
        h--;
    }else if(l==3){
        i--;
    }else if(l==4){
        j--;
    }return l;
    
}

void put_tile(int l, int x, int y){
    
    //if (arr[i][j] !=0){
    //  printf("This place is already taken");
    //}else{
    //if(l==1){
    // arr[i][j]=1
    //}else if(l==2){
    //arr[i][j]=2
    //}else if(l==3){
    //arr[i][j]=3
    //}else if(l==4){
    //arr[i][j]=4
    
    //}
    
    //}
    
    
    
    
}

int main()
{
    int  z, number_of_players;
    int number_of_tiles=13;
//    printf("Enter the number of players:");
//    scanf("%d",&number_of_players);
 
    for(z=1 ; z < number_of_tiles ; number_of_tiles--)
    {
        tile_file = fopen("tile.txt", "r");
        board_file = fopen("tmp.txt", "r");
        
        if (board_file == NULL) return 1;
        print_board(board_file);
        print_tiles();
        fclose(tile_file);
        fclose(board_file);
    }
    
    return 0;
}

