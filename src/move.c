#include "move.h"
#define bsize 8
int flag=0;
int counter=0;

bool rook(char *x){ /*input=[a,3,a,4]*/
    if(x[0]==x[2] && x[1]==x[3]) return false;
    if(x[0]!=x[2] && x[1]!=x[3]) return false;
    return true;
}
bool king(char *x){
    if(x[0]==x[2] && x[1]==x[3]) return false;
    int dx[]={1,1,1,0,0,-1,-1,-1};
    int dy[]={1,0,-1,-1,-1,0,1,1};
    for (int i=0;i<8;i++){
        if((x[0]+dx[i]==x[2])&&(x[1]+dy[i]==x[3])) return true;
    }
    return false;
}
bool bishob(char *x){
    if(x[0]==x[2] && x[1]==x[3]) return false;
    if((x[0]-x[2]==x[1]-x[3])||(x[2]-x[0]==x[1]-x[3])||(x[0]-x[2]==x[3]-x[1])||(x[2]-x[0]==x[3]-x[1])) return true;
    return false;
}