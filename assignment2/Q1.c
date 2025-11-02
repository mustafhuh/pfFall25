#include <stdio.h>
#include <string.h>

#define MAX 100

void addBook(int ids[], char names[][50], float costs[], int stock[], int *count);
void sellBook(int ids[], int stock[], int count);
void lowStockReport(int ids[], char names[][50], float costs[], int stock[], int count);
int findBook(int ids[], int count, int id);

int main() {
    int ids[MAX];
    char names[MAX][50];
    float costs[MAX];
    int stock[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n--- LIBERTY BOOKS MENU ---\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook(ids, names, costs, stock, &count);
                break;
            case 2:
                sellBook(ids, stock, count);
                break;
            case 3:
                lowStockReport(ids, names, costs, stock, count);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

int findBook(int ids[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (ids[i] == id)
            return i;
    }
    return -1;
}

void addBook(int ids[], char names[][50], float costs[], int stock[], int *count) {
    if (*count >= MAX) {
        printf("Inventory full.\n");
        return;
    }

    int id;
    printf("Enter ISBN: ");
    scanf("%d", &id);

    if (findBook(ids, *count, id) != -1) {
        printf("Book with this ISBN already exists.\n");
        return;
    }

    getchar();
    ids[*count] = id;

    printf("Enter Title: ");
    fgets(names[*count], 50, stdin);
    names[*count][strcspn(names[*count], "\n")] = '\0';

    printf("Enter Price: ");
    scanf("%f", &costs[*count]);
    printf("Enter Quantity: ");
    scanf("%d", &stock[*count]);

    (*count)++;
    printf("Book added.\n");
}

void sellBook(int ids[], int stock[], int count) {
    int id, sold;
    printf("Enter ISBN: ");
    scanf("%d", &id);

    int index = findBook(ids, count, id);
    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    printf("Enter copies sold: ");
    scanf("%d", &sold);

    if (sold > stock[index]) {
        printf("Not enough stock. Available: %d\n", stock[index]);
    } else {
        stock[index] -= sold;
        printf("Sale complete. Remaining: %d\n", stock[index]);
    }
}

void lowStockReport(int ids[], char names[][50], float costs[], int stock[], int count) {
    int found = 0;
    printf("\n--- LOW STOCK (Below 5) ---\n");
    for (int i = 0; i < count; i++) {
        if (stock[i] < 5) {
            printf("ISBN: %d\n", ids[i]);
            printf("Title: %s\n", names[i]);
            printf("Price: %.2f\n", costs[i]);
            printf("Quantity: %d\n\n", stock[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No books are low on stock.\n");
}

