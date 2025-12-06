#include"board.h"

void displayboard(){
    int c = 8 ; 
    int j = 7;
    int num= 1;
    printf("   ");
    for (int i = 0 ; i < 8 ; ++i){
        printf("  %c ",'A'+i);
    } printf("\n");
    while(c>0){
        printf("   ");
    for (int i = 0 ; i < 8 ; ++i){
        printf("+---");
    }
    printf("+\n %d ",num);
    for (int i = 0 ; i < 8 ;++i){
        printf("| %c ",init_pos[j][i]);
    }
    printf("|\n");
    c--;
    j--;
    num++;
}
    printf("   ");

for (int i = 0 ; i < 8 ; ++i){
    printf("+---");
}
printf("+\n");
}