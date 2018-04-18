#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int r, c;


int** generate_board(int *x)
{
    int  i, j;
    
    r = (*x)*2 + 1;
    c = (*x)*2 + 1;
    
    int **arr = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));
    
    for (i = 0; i <  r; i++)
        for (j = 0; j < c; j++)
            arr[i][j] = 0;
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

void print_board (int **arr, int r, int c)
{
    int i,j;
    for (i = 0; i <  r; i++)
    {
        if (i%2!=0)     printf("%*s", 5, "");
        for (j = 0; j < c; j++)
        {
            if (arr[i][j] > 3)
                printf("P%d(%d,%d)%*s", arr[i][j]/10, i, j, 10-intlen(i)-intlen(j)-intlen(arr[i][j]/10)-4, "");
            else
                printf("%d(%d,%d)%*s", arr[i][j], i, j, 10-intlen(i)-intlen(j)-intlen(arr[i][j])-3, "");
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
    printf("Enter the number of players:");
    scanf("%d",&number_of_players);
//    printf("Size of the board:");
//    scanf("%d %d", &r, &c);
    int **arr;
//    int **arr2;
    arr = generate_board(&number_of_tiles);
    
    for(z=1 ; z < number_of_tiles ; number_of_tiles--)
    {
        print_board( arr, r, c );
        print_tiles();
        int print_tiles_interaction;
    }
    
    return 0;
}

