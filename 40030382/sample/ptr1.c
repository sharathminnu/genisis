#include<stdio.h>
int main(){
 int i, j;
 char sudoku[9][9];
    char filename[100];

        printf("Please enter file name (W/O .txt): ");
        scanf("%s", filename);

        FILE *file1 = fopen(filename, "r");

        for(i=0;i<5;i++){
            for(j=0;j<3;j++){
         {
                fscanf(file1,"%c\t", &sudoku[i][j]);
            }
            }
        }

        for(i=0;i<5;i++){
            for(j=0;j<3;j++){
                printf("%2c", sudoku[i][j]);
                }
            printf("\n");
        }

fclose(file1);
}