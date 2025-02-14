//spandy bhai
#include <stdio.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';  // Player X starts
int gameStatus = 0;  // 0 for ongoing, 1 for X wins, 2 for O wins, 3 for draw

// Function to print the board
void printBoard() {
    printf("\nTic-Tac-Toe Game\n");
    printf("\nPlayer 1 (X)  -  Player 2 (O)\n\n");
    
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if a player has won
int checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;  // No winner yet
}

// Function to check for a draw
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;  // There's still an empty space
            }
        }
    }
    return 1;  // It's a draw
}

// Function to change the player
void changePlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to play the game
void playGame() {
    int move;
    int validMove;
    while (gameStatus == 0) {
        printBoard();
        printf("Player %c, enter the number (1-9) where you want to place your mark: ", currentPlayer);
        scanf("%d", &move);

        validMove = 0;
        if (move >= 1 && move <= 9) {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = currentPlayer;
                validMove = 1;
            } else {
                printf("Invalid move. The cell is already taken. Try again.\n");
            }
        } else {
            printf("Invalid input. Please enter a number between 1 and 9.\n");
        }

        if (validMove) {
            if (checkWin()) {
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
                gameStatus = (currentPlayer == 'X') ? 1 : 2;
            } else if (checkDraw()) {
                printBoard();
                printf("It's a draw!\n");
                gameStatus = 3;
            } else {
                changePlayer();
            }
        }
    }
}

int main() {
    playGame();
    return 0;
}

