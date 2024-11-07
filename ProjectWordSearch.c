#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

int directions[8][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0},
    {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
};

// Function to wrap around index
int wrap(int index, int max) {
    if (index < 0) return max + index;
    if (index >= max) return index - max;
    return index;
}

// Function to check if a word exists starting from position (row, col) in a specific direction
bool checkWord(char grid[MAX_SIZE][MAX_SIZE], int n, char *word, int row, int col, int dirX, int dirY) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int newRow = wrap(row + i * dirX, n);
        int newCol = wrap(col + i * dirY, n);
        if (grid[newRow][newCol] != word[i]) return false;
    }
    return true;
}
// Function to find all instances of a word in the grid
void findWord(char grid[MAX_SIZE][MAX_SIZE], int n, char *word) {
    bool found = false;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            for (int dir = 0; dir < 8; dir++) {
                if (checkWord(grid, n, word, row, col, directions[dir][0], directions[dir][1])) {
                    printf("Found word \"%s\" starting at (%d, %d) in direction (%d, %d)\n", word, row, col, directions[dir][0], directions[dir][1]);
                    found = true;
                }
            }
        }
    }
    if (!found) {
        printf("Word \"%s\" not found in the grid.\n", word);
    }
}

// Main function
int main() {
    int n;
    char grid[MAX_SIZE][MAX_SIZE];
    char word[MAX_SIZE];
    
    printf("Enter the size of the grid (n x n): ");
    scanf("%d", &n);
    
    printf("Enter the grid:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    
    printf("Enter the word to search for: ");
    scanf("%s", word);
    
    findWord(grid, n, word);
    
    return 0;
}
