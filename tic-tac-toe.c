#include<stdio.h> 
#include<stdlib.h>

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int movesLeft = 9;

void displayBoard() { 
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf(" ---------- \n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf(" ---------- \n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkWin(char c) { 
    int i;
    for(i = 0; i < 3; i++) {
        if(board[i][0] == c && board[i][1] == c && board[i][2] == c) 
            return 1;
    }
    for(i = 0; i < 3; i++) {
        if(board[0][i] == c && board[1][i] == c && board[2][i] == c) 
            return 1;
    }
    if(board[0][0] == c && board[1][1] == c && board[2][2] == c) 
        return 1;
    if(board[0][2] == c && board[1][1] == c && board[2][0] == c) 
        return 1;
    return 0;
}

int makeMove(char c, int position) { 
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if(board[row][col] != 'X' && board[row][col] != 'O') { 
        board[row][col] = c;
        movesLeft--; 
        return 1;
    } else {
        printf("Invalid move. Please try again.\n"); 
        return 0;
    }
}

int computerMove() { 
    int i;
    for(i = 1; i <= 9; i++) { 
        int row = (i - 1) / 3; 
        int col = (i - 1) % 3;
        if(board[row][col] != 'X' && board[row][col] != 'O') { 
            board[row][col] = 'O';
            if(checkWin('O')) { 
                movesLeft--; 
                return 1;
            }
            board[row][col] = i + '0';
        }
    }
    for(i = 1; i <= 9; i++) { 
        int row = (i - 1) / 3; 
        int col = (i - 1) % 3;
        if(board[row][col] != 'X' && board[row][col] != 'O') { 
            board[row][col] = 'X';
            if(checkWin('X')) {
                board[row][col] = 'O'; 
                movesLeft--;
                return 1;
            }
            board[row][col] = i + '0';
        }
    }
    int position; 
    do {
        position = rand() % 9 + 1; 
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        if(board[row][col] != 'X' && board[row][col] != 'O') { 
            board[row][col] = 'O';
            movesLeft--; 
            return 1;
        }
    } while(1);
}

int main() {
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("You will be playing against the computer.\n"); 
    printf("You are X, and the computer is O.\n"); 
    printf("Here is the board. Each cell is numbered 1-9.\n"); 
    displayBoard();

    while(movesLeft > 0) {
        int playerPosition; 
        do {
            printf("Enter the number of the cell where you want to place your X: ");
            scanf("%d", &playerPosition);
        } while(!makeMove('X', playerPosition)); 
        
        displayBoard();

        if(checkWin('X')) { 
            printf("Congratulations, you won!\n"); 
            return 0;
        }

        if(movesLeft == 0) { 
            printf("It's a draw.\n"); 
            return 0;
        }

        printf("The computer is making its move...\n"); 
        if(computerMove()) {
            displayBoard(); 
            if(checkWin('O')) { 
                printf("Sorry, you lost.\n"); 
                return 0;
            }
        }

        if(movesLeft == 0) {
            printf("It's a draw.\n"); 
            return 0;
        }
    }
    
    return 0;
}
