#include "move.h"
#include<math.h>
#define bsize 8
int flag=0;
int counter=0;


/*x is the input
a  has the values of the input as int
pawn logic
destantion check
checkoftheking
checkmate
*/



int input_as_int[4];  // global array

void convert_input_to_int(char *x) {
    input_as_int[0]=x[0] - 'a'; // start column
    input_as_int[1]=x[1] - '1'; // start row
    input_as_int[2]=x[2] - 'a'; // end column
    input_as_int[3]=x[3] - '1'; // end row
}

int sign(int x){ /*to know the piece go forward or backward*/
    if(x>0) return 1;
    if(x<0) return -1;
    return 0;
}
bool rook(void){ /*input=[a,3,a,4]*/
    if(input_as_int[0]==input_as_int[2]&&input_as_int[1]!=input_as_int[3]) return true;
    if(input_as_int[0]!=input_as_int[2]&&input_as_int[1]==input_as_int[3]) return true;
    return false;
}
bool king(void){
    if(abs(input_as_int[0]-input_as_int[2])<=1 &&
        abs(input_as_int[1]-input_as_int[3])<=1) return true;

    return false;
}

bool bishop(void){
    if(abs(input_as_int[2]-input_as_int[0])==abs(input_as_int[3]-input_as_int[1])) return true;
    return false;
}


bool knight(void){
if(((abs(input_as_int[0]-input_as_int[2])==2) && (abs(input_as_int[1]-input_as_int[3])==1)) || 
   ((abs(input_as_int[0]-input_as_int[2])==1) && (abs(input_as_int[1]-input_as_int[3])==2))) return true;
   return false;
}
bool queen(void){
    if(rook()||bishob()) return true;
    return false;
}
bool path_check(char board[8][8]){
    int dx=sign(input_as_int[2]-input_as_int[0]);
    int dy=sign(input_as_int[3]-input_as_int[1]);
    int x=dx+input_as_int[0];
    int y=dy+input_as_int[1];
    while (x!=input_as_int[2]||y!=input_as_int[3])
    {
        if(board[y][x]!='.' && board[y][x]!='-') return false;
        x+=dx;
        y+=dy;
    }
    return true;
}
bool is_king_checked(){

}
bool validation(char *x,char board[8][8]){
    char piece=board[input_as_int[1]][input_as_int[0]];
    if(x[0]==x[2]&&x[1]==x[3]) {
        printf("Invlaid input ,you didnot move the piece\n");
        return false;}
    if(x[0]<'a' || x[0]>'h' || x[2]<'a' || x[2]>'h' || 
            x[1]<'1' || x[1]>'8' || x[3]<'1' || x[3]>'8') {
        printf("Invalid input, must be in the range of (a-h) and (1-8)\n");
        return false;
    }
    switch (piece)
    {
    case 'r':
    case 'R':
        if(path_check(/*last board*/)==false){
           printf("Path is blocked\n");
            return false;
        }
        return rook();
    case 'b':
    case 'B':
        if(path_check(/*last board*/)==false){
            printf("Path is blocked\n");
            return false;
        }
        return bishop();
    case 'Q':
    case 'q':
        if(path_check(/*last board*/)==false){
            printf("Path is blocked\n");
            return false;
        }
        return queen();
    case 'K':
    case 'k':
        return king();
    case 'N':
    case 'n':
        return knight();
    case 'P':
        if(x[1]=='2'){
            if(x[3]=='4'){
                if(path_check(/*last board*/)==false){
                    printf("Path is blocked\n");
                    return false;
        }
            return true;                
            }
            
        }
        if(x[3]==x[1]+'1') return true;
        
    case 'p':
        if(x[1]=='7'){
        if(x[3]=='5'){
                if(path_check(/*last board*/)==false){
                    printf("Path is blocked\n");
                    return false;
        }
            return true;                
            }
        }
        if(x[3]==x[1]-'1') return true;
    
    default:
        pritf("Invalid input,This square has no pieces\n");
        return false;
    }

}