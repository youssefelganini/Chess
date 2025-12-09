#include "move.h"
#include<math.h>
#define bsize 8
int flag=0;
int counter=0;

bool rook(char *x){ /*input=[a,3,a,4]*/
    if(x[0]==x[2]&&x[1]!=x[3]) return true;
    if(x[0]!=x[2]&&x[1]==x[3]) return true;
    return false;
}
bool king(char *x){
    int dx[]={1,1,1,0,0,-1,-1,-1};
    int dy[]={1,0,-1,-1,-1,0,1,1};
    for (int i=0;i<8;i++){
        if((x[0]+dx[i]==x[2])&&(x[1]+dy[i]==x[3])) return true;
    }
    return false;
}
bool bishob(char *x){
    if((x[0]-x[2]==x[1]-x[3])||(x[2]-x[0]==x[1]-x[3])||
        (x[0]-x[2]==x[3]-x[1])||(x[2]-x[0]==x[3]-x[1])) return true;
    return false;
}
bool knight(char *x){
    int a[4];
    a[0]=(int)x[0];
    a[1]=(int)x[1];
    a[2]=(int)x[2];
    a[3]=(int)x[3];
    if(((abs(a[0]-a[2])==2) && (abs(a[1]-a[3])==1)) || 
    ((abs(a[0]-a[2])==1) && (abs(a[1]-a[3])==2))) return true;
    return false;
}
bool queen(char *x){
    if(rook(x/*input*/)||bishob(x)) return true;
    return false;
}
bool validation(char *x,char board[8][8]){
    int a[4];
    a[0]=(int)(x[0]-'a');
    a[1]=(int)(x[1]-'1');
    a[2]=(int)(x[2]-'a');
    a[3]=(int)(x[3]-'1');

    char piece=board[a[0]][a[1]];
    if(x[0]==x[2]&&x[1]==x[3]) {
        printf("Invlaid input ,you didnot move the piece\n");
        return false;}
    if(x[0]<'a' || x[0]>'h' || x[2]<'a' || x[2]>'h' || 
            x[1]<'1' || x[1]>'8' || x[3]<'1' || x[3]>'8') {
        printf("Invalid input, must be (a-h) and (1-8)\n");
        return false;
    }
    switch (piece)
    {
    case constant expression:
        /* code */
        break;
    
    default:
        break;
    }

}