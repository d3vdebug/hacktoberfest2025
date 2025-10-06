#include <stdio.h>

#define N 4

int maze[N][N] = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}
};

int sol[N][N];

int isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

int solveMazeUtil(int x, int y) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return 1;
    }

    if (isSafe(x, y)) {
        sol[x][y] = 1;

        if (solveMazeUtil(x + 1, y)) return 1; // move down
        if (solveMazeUtil(x, y + 1)) return 1; // move right

        sol[x][y] = 0; // backtrack
        return 0;
    }
    return 0;
}

void solveMaze() {
    if (solveMazeUtil(0, 0) == 0) {
        printf("No solution found\n");
        return;
    }

    printf("Path (1 = part of solution):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
}

int main() {
    solveMaze();
    return 0;
}
