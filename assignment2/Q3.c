#include <stdio.h>

#define ROWS 3
#define COLS 3

#define POWER 1
#define OVERLOAD 2
#define MAINT 4

void updateStatus(int grid[ROWS][COLS]);
void checkStatus(int grid[ROWS][COLS]);
void systemReport(int grid[ROWS][COLS]);

int main() {
    int grid[ROWS][COLS] = {0};
    int choice;

    do {
        printf("\n--- IESCO GRID SYSTEM ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Check Sector Status\n");
        printf("3. Run System Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: updateStatus(grid); break;
            case 2: checkStatus(grid); break;
            case 3: systemReport(grid); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}

void updateStatus(int grid[ROWS][COLS]) {
    int row, col, type, action;

    printf("Enter row (0-%d): ", ROWS - 1);
    scanf("%d", &row);
    printf("Enter column (0-%d): ", COLS - 1);
    scanf("%d", &col);

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid sector.\n");
        return;
    }

    printf("1. Power\n2. Overload\n3. Maintenance\nEnter type: ");
    scanf("%d", &type);
    printf("1. Set\n0. Clear\nEnter action: ");
    scanf("%d", &action);

    int bit = 0;
    if (type == 1) bit = POWER;
    else if (type == 2) bit = OVERLOAD;
    else if (type == 3) bit = MAINT;
    else {
        printf("Invalid type.\n");
        return;
    }

    if (action == 1)
        grid[row][col] |= bit;
    else
        grid[row][col] &= ~bit;

    printf("Sector updated.\n");
}

void checkStatus(int grid[ROWS][COLS]) {
    int row, col;
    printf("Enter row (0-%d): ", ROWS - 1);
    scanf("%d", &row);
    printf("Enter column (0-%d): ", COLS - 1);
    scanf("%d", &col);

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid sector.\n");
        return;
    }

    int val = grid[row][col];
    printf("\nSector [%d][%d] Status:\n", row, col);
    printf("Power: %s\n", (val & POWER) ? "ON" : "OFF");
    printf("Overload: %s\n", (val & OVERLOAD) ? "YES" : "NO");
    printf("Maintenance: %s\n", (val & MAINT) ? "YES" : "NO");
}

void systemReport(int grid[ROWS][COLS]) {
    int over = 0, maint = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] & OVERLOAD) over++;
            if (grid[i][j] & MAINT) maint++;
        }
    }

    printf("\n--- SYSTEM REPORT ---\n");
    printf("Overloaded Sectors: %d\n", over);
    printf("Maintenance Needed: %d\n", maint);
}

