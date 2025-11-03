#include <stdio.h>
#include <string.h>

// Struct to represent a user
typedef struct {
    char username[20];
    char password[20];
    char role[10]; // "doctor" or "patient"
} User;

// Array of users: 2 doctors + 5 patients
User users[7] = {
    {"doctor1", "docpass1", "doctor"},
    {"doctor2", "docpass2", "doctor"},
    {"patient1", "pass1", "patient"},
    {"patient2", "pass2", "patient"},
    {"patient3", "pass3", "patient"},
    {"patient4", "pass4", "patient"},
    {"patient5", "pass5", "patient"}
};

// Function to authenticate user
int authenticate(char* username, char* password, char* role) {
    for (int i = 0; i < 7; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0 &&
            strcmp(users[i].role, role) == 0) {
            return 1; // Success
        }
    }
    return 0; // Failure
}

int main() {
    char username[20];
    char password[20];
    char role[10];

    printf("Enter role (doctor/patient): ");
    scanf("%s", role);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (authenticate(username, password, role)) {
        printf("Login successful! Welcome, %s.\n", username);
    } else {
        printf("Login failed. Invalid credentials.\n");
    }

    return 0;
}