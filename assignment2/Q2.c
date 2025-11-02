#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 4
#define MAX_CART 10

int codes[MAX_ITEMS] = {1, 2, 3, 4};
int stock[MAX_ITEMS] = {50, 10, 20, 8};
float price[MAX_ITEMS] = {100, 200, 300, 150};

int cartItems[MAX_CART];
int cartQty[MAX_CART];
int cartSize = 0;

char name[50];
char cnic[20];

void enterCustomer();
void showProducts();
void addProduct();
void showTotal();
void printInvoice();
int findItem(int code);
float getTotal(int discount);

int main() {
    int choice;

    printf("\n=== SUPERMARKET BILLING SYSTEM ===\n");

    do {
        printf("\n1. Enter Customer Info\n");
        printf("2. Show Product List\n");
        printf("3. Add to Cart\n");
        printf("4. Show Total Bill\n");
        printf("5. Print Invoice\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: enterCustomer(); break;
            case 2: showProducts(); break;
            case 3: addProduct(); break;
            case 4: showTotal(); break;
            case 5: printInvoice(); break;
            case 6: printf("\nThank you! Goodbye!\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void enterCustomer() {
    printf("\nEnter Customer Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter CNIC: ");
    fgets(cnic, sizeof(cnic), stdin);
    cnic[strcspn(cnic, "\n")] = '\0';

    printf("Customer info saved.\n");
}

void showProducts() {
    printf("\n--- PRODUCT LIST ---\n");
    printf("Code\tStock\tPrice\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d\t%d\t%.2f\n", codes[i], stock[i], price[i]);
    }
}

int findItem(int code) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (codes[i] == code)
            return i;
    }
    return -1;
}

void addProduct() {
    int code, qty;
    showProducts();

    printf("\nEnter Product Code: ");
    scanf("%d", &code);
    int index = findItem(code);

    if (index == -1) {
        printf("Invalid product code.\n");
        return;
    }

    printf("Enter Quantity: ");
    scanf("%d", &qty);

    if (qty <= 0) {
        printf("Invalid quantity.\n");
        return;
    }

    if (qty > stock[index]) {
        printf("Only %d available.\n", stock[index]);
        return;
    }

    stock[index] -= qty;
    cartItems[cartSize] = code;
    cartQty[cartSize] = qty;
    cartSize++;

    printf("Item added to cart.\n");
}

float getTotal(int discount) {
    float total = 0;
    for (int i = 0; i < cartSize; i++) {
        int index = findItem(cartItems[i]);
        total += price[index] * cartQty[i];
    }
    if (discount)
        total *= 0.75;
    return total;
}

void showTotal() {
    if (cartSize == 0) {
        printf("\nCart is empty.\n");
        return;
    }

    float total = getTotal(0);
    printf("\nTotal (No Discount): Rs. %.2f\n", total);

    char code[20];
    printf("Enter promo code (Eid2025 / no): ");
    scanf("%s", code);

    if (strcmp(code, "Eid2025") == 0)
        printf("Discounted Total: Rs. %.2f\n", getTotal(1));
    else
        printf("No discount applied.\n");
}

void printInvoice() {
    if (cartSize == 0) {
        printf("\nCart is empty.\n");
        return;
    }

    printf("\n========== INVOICE ==========\n");
    printf("Customer: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("\nCode\tQty\tPrice\tTotal\n");

    float total = 0;
    for (int i = 0; i < cartSize; i++) {
        int index = findItem(cartItems[i]);
        float sub = price[index] * cartQty[i];
        printf("%d\t%d\t%.2f\t%.2f\n", cartItems[i], cartQty[i], price[index], sub);
        total += sub;
    }

    printf("\nTotal: Rs. %.2f\n", total);

    char promo[20];
    printf("Promo code (Eid2025 / no): ");
    scanf("%s", promo);

    if (strcmp(promo, "Eid2025") == 0)
        printf("After Discount: Rs. %.2f\n", total * 0.75);
    else
        printf("Final Total: Rs. %.2f\n", total);

    printf("=============================\n");
}

