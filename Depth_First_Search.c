#include <stdio.h>
#include <stdbool.h>
#define ROWS 5
#define COLS 6
// Maze representation
int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0}
};
// Directions for moving in the maze (right, down, left, up)
int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
// Function to check if a move is valid
bool is_valid_move(int row, int col, bool visited[ROWS][COLS]) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 
    0 && !visited[row][col]);}
// Recursive DFS function
bool dfs(int row, int col, bool visited[ROWS][COLS], int path[ROWS][COLS]) {
    // Base case: If reached the bottom-right corner, mark it and return true
    if (row == ROWS - 1 && col == COLS - 1) {
        path[row][col] = 1;
        return true;
    }
    // Mark the current cell as visited and part of the path
    visited[row][col] = true;
    path[row][col] = 1;
    // Explore the neighboring cells
    for (int i = 0; i < 4; i++) {
        int new_row = row + direction[i][0];
        int new_col = col + direction[i][1];
        if (is_valid_move(new_row, new_col, visited)) {
            if (dfs(new_row, new_col, visited, path)) {
                return true;}}}
    // Backtrack: Unmark the current cell from the path and return false
    path[row][col] = 0;
    return false; }
// Function to solve the maze
bool solve_maze() {
    bool visited[ROWS][COLS] = {false};
    int path[ROWS][COLS] = {0};
    // Start DFS from the top-left corner (0, 0)
    if (dfs(0, 0, visited, path)) {
        printf("Solution path:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", path[i][j]);
            }
            printf("\n");}
                return true;} 
        else {
        printf("No solution path found.\n");
        return false;
    }}
// Main function
int main() {
    solve_maze();
    return 0;
}
