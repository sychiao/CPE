#include <cstdio>

using namespace std;

int main(){

    int nums = 1;
    int col,row;
    while(1){
        scanf("%d %d",&row,&col);
        if(col == 0 && row == 0){
            break;
        }else{
            if(nums != 1)
                printf("\n");
        }
        char *board = new char[col*row];
        for(int i=0;i<row;i++){
            scanf("%*c");
            for(int j=0;j<col;j++){
                scanf("%c",&board[i*col+j]);
            }
        }

        printf("Field #%d:\n",nums++);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i*col+j] == '*')
                    printf("*");
                else{
                    int count = 0;
                    if(i+1<row){
                        if(j+1<col){
                            if(board[(i+1)*col+(j+1)] == '*') count++;
                        }
                        if(j-1>=0){
                            if(board[(i+1)*col+(j-1)] == '*') count++;
                        }
                        if(board[(i+1)*col+j] == '*') count++;
                    }
                    if(i-1>=0){
                        if(j+1<col){
                            if(board[(i-1)*col+(j+1)] == '*') count++;
                        }
                        if(j-1>=0){
                            if(board[(i-1)*col+(j-1)] == '*') count++;
                        }
                        if(board[(i-1)*col+j] == '*') count++;
                    }
                    if(j+1<col){
                        if(board[(i)*col+(j+1)] == '*') count++;
                    }
                    if(j-1>=0){
                        if(board[(i)*col+(j-1)] == '*') count++;
                    }
                    printf("%d",count);
                }
                //printf("%c",board[i*col+j]);
            }
            printf("\n");
        }
        
        
    }
    return 0;
}