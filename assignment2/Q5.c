#include <stdio.h>
#include <string.h>

void encodeMessage(char text[]);
void decodeMessage(char text[]);
void toggleBits(char *character);

int main() {
    char message[200];
    int option;

    do {
        printf("\n=========== TCS MESSAGE ENCODER/DECODER ===========\n");
        printf("1. Encode a Message\n");
        printf("2. Decode a Message\n");
        printf("3. Exit\n");
        printf("===================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        getchar();  

        switch (option) {
            case 1:
                printf("\nEnter message to encode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                encodeMessage(message);
                break;

            case 2:
                printf("\nEnter message to decode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                decodeMessage(message);
                break;

            case 3:
                printf("\nThank you for using the system. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (option != 3);

    return 0;
}

void toggleBits(char *character) {
    *character ^= (1 << 1);  // Toggle 2nd bit
    *character ^= (1 << 4);  // Toggle 5th bit
}

void encodeMessage(char text[]) {
    int length = strlen(text);
    char temp;

    for (int i = 0; i < length / 2; i++) {
        temp = text[i];
        text[i] = text[length - i - 1];
        text[length - i - 1] = temp;
    }

    for (int i = 0; i < length; i++) {
        toggleBits(&text[i]);
    }

    printf("\nEncoded Message:\n%s\n", text);
}

void decodeMessage(char text[]) {
    int length = strlen(text);
    char temp;

    for (int i = 0; i < length; i++) {
        toggleBits(&text[i]);
    }

    for (int i = 0; i < length / 2; i++) {
        temp = text[i];
        text[i] = text[length - i - 1];
        text[length - i - 1] = temp;
    }

    printf("\nDecoded Message:\n%s\n", text);
}

