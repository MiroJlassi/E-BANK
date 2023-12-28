#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Clients menu options
// diplay all clients
void Clientslist() {
    FILE *f;
    f = fopen("BD.txt", "r");
    if (f == NULL) {
        fprintf(stderr, "EMPTY!!\n");
        return;
    }
    char line[300];
    while (fgets(line, sizeof(line), f) != NULL) {
        printf("%s", line);
    }
    if (fclose(f) != 0) {
        fprintf(stderr, "Error closing file\n");
        return;
    }
    printf("\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
}


// add new client
void NewClient() {
    FILE *f;
    f = fopen("BD.txt", "a");
    char name[100];
    char lastname[100];
    char sal[100];
    printf("Enter client name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter client last name: ");
    fgets(lastname, sizeof(lastname), stdin);
    printf("Enter client salary: ");
    fgets(sal, sizeof(sal), stdin);
    name[strcspn(name, "\n")] = '\0';
    lastname[strcspn(lastname, "\n")] = '\0';
    sal[strcspn(sal, "\n")] = '\0';
    char clientinfo[300];
    sprintf(clientinfo, "%s-%s-%s", name, lastname, sal);
    fprintf(f, "%s\n", clientinfo);
    printf("%s is added to the database\n", name);
    fclose(f);
    printf("\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

// Remove a client by it's name
void removeClient() {
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Clients list: \n");
	Clientslist();
	printf("make sure to type the correct name please\n");
    FILE* f;
    FILE* tempFile;
    f = fopen("BD.txt", "r");
    tempFile = fopen("tempBD.txt", "w");
    if (f == NULL || tempFile == NULL) {
        fprintf(stderr, "Error opening file\n");
        return;
    }
    char name[100];
    printf("Enter client name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    char line[300];
    while (fgets(line, sizeof(line), f) != NULL) {
        char currentName[100], currentLastname[100], currentSal[100];
        if (sscanf(line, "%[^-]-%[^-]-%s", currentName, currentLastname, currentSal) == 3 &&
            strcmp(name, currentName) == 0){
            continue;
        }
        fprintf(tempFile, "%s", line);
    }
    fclose(f);
    fclose(tempFile);
    remove("BD.txt");
    rename("tempBD.txt", "BD.txt");

}


// update client info. this function remove the client then add a new one. 
void updateclient(){
	removeClient();
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Client is selected\n");
	printf("Update Informations\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	NewClient();
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Inofrmations updated successfully\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Transaction menu options

// Display History
void displayTransactions() {
    FILE *f = fopen("TRBD.txt", "r");
    if (f == NULL) {
        fprintf(stderr, "EMPTY!!\n");
        return;
    }
    char line[300];
    while (fgets(line, sizeof(line), f) != NULL) {
        printf("%s", line);
    }
    fclose(f);
}

// Make Transaction
#include <stdbool.h>

void MakeTransactions() {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Clients list: \n");
    Clientslist();

    FILE *f = fopen("TRBD.txt", "a");
    if (f == NULL) {
        fprintf(stderr, "Error opening transactions file\n");
        return;
    }

    char name1[100], lastname1[100], name2[100], lastname2[100], value[100];
    printf("SENDER~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter sender's name: ");
    fgets(name1, sizeof(name1), stdin);
    printf("Enter sender's last name: ");
    fgets(lastname1, sizeof(lastname1), stdin);
    printf("RECIEVER~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter receiver's name: ");
    fgets(name2, sizeof(name2), stdin);
    printf("Enter receiver's last name: ");
    fgets(lastname2, sizeof(lastname2), stdin);
    printf("VALUE~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter transaction value: ");
    fgets(value, sizeof(value), stdin);

    name1[strcspn(name1, "\n\r")] = '\0';
    lastname1[strcspn(lastname1, "\n\r")] = '\0';
    name2[strcspn(name2, "\n\r")] = '\0';
    lastname2[strcspn(lastname2, "\n\r")] = '\0';
    value[strcspn(value, "\n\r")] = '\0';
    int val = atoi(value);
    FILE *BD = fopen("BD.txt", "r");
    if (BD == NULL) {
        fprintf(stderr, "Error opening BD.txt file\n");
        fclose(f);
        return;
    }
    FILE *tempFile = fopen("tempBD.txt", "w");
    if (tempFile == NULL) {
        fprintf(stderr, "Error opening tempBD.txt file\n");
        fclose(BD);
        fclose(f);
        return;
    }
    char line[300];
    int updated = 0;
    while (fgets(line, sizeof(line), BD) != NULL) {
        char currentName[100], currentLastname[100], currentSal[100];
        if (sscanf(line, "%[^-]-%[^-]-%s", currentName, currentLastname, currentSal) == 3) {
            if (strcmp(name1, currentName) == 0 && strcmp(lastname1, currentLastname) == 0) {
                fprintf(tempFile, "%s-%s-%d\n", name1, lastname1, atoi(currentSal) - val);
                updated = 1;
            } else if (strcmp(name2, currentName) == 0 && strcmp(lastname2, currentLastname) == 0) {
                fprintf(tempFile, "%s-%s-%d\n", name2, lastname2, atoi(currentSal) + val);
                updated = 1;
            } else {
                fprintf(tempFile, "%s", line);
            }
        }
    }
    fclose(BD);
    fclose(tempFile);
    if (updated == 0) {
        printf("Sender or receiver not found in the database.\n");
        remove("tempBD.txt");
        fclose(f);
        return;
    }
    remove("BD.txt");
    rename("tempBD.txt", "BD.txt");
    fprintf(f, "{%s %s sent %d to %s %s}\n", name1, lastname1, val, name2, lastname2);
    printf("Transaction recorded successfully!\n");

    fclose(f);
}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main Menu Options
/* - Clients
   - Transaction
   - About
   - Quit          */



// clients Menu
void clients() {
    while (1) {
        FILE *file;
        file = fopen("UI/clientsmenu.txt", "r");
        char buffer[2];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }
        fclose(file);
        int y;
        printf("\nEnter your choice: ");
        scanf("%d", &y);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (y) {
            case 1:
            	system("cls");
                printf("Clients list:\n");
                Clientslist();
                break;
            case 2:
                system("cls");
                printf("ADD NEW CLIENT:\n");
                NewClient();
                break;
            case 3:
                system("cls");
                updateclient();
                break;
            case 4:
                system("cls");
                printf("Remove Client\n");
                removeClient();
                printf("Client removed\n");
                break;
            case 0:
                system("cls");
                menu();
            default:
                printf("UNAVAILABLE COMMAND!! try again\n");
        }
    }	
}

//  transaction Menu
void transactionMenu() {
    while (1) {
        FILE *file;
        file = fopen("UI/TransactionMenu.txt", "r");
        char buffer[2];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }
        fclose(file);

        int x;
        printf("\nEnter your choice: ");
        scanf("%d", &x);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (x) {
            case 1:
                system("cls");
                printf("Transaction History:\n");
                displayTransactions();
                break;
            case 2:
                system("cls");
                printf("Make a Transaction:\n");
                MakeTransactions();
                break;
            case 0:
                system("cls");
                menu();
            default:
                printf("UNAVAILABLE COMMAND!! Try again\n");
        }
    }
}

// About Menu
void about(){
	FILE *file;
    file = fopen("UI/ABOUT.txt", "r");
    char buffer[2];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
    printf("            0. Back to main menu\n");
	printf("----------------------------------------------------------------------------------------\n");
    printf("Enter your choice: ");
    int y;
    scanf("%d", &y);
    if(y == 0){
        system("cls");
    	menu();

    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Main Menu
void menu() {
    FILE *file;
    file = fopen("UI/MENU.txt", "r");
    char buffer[2];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
    while (1) {
        int x;
        printf("\nEnter your choice: ");
        scanf("%d", &x);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (x) {
            case 1:
                system("cls");
                clients();
                break;
            case 2:
                system("cls");
                transactionMenu();
                break;
            case 3:
                system("cls");
                about();
                break;
            case 0:
                exit(0);
            default:
                printf("UNAVAILABLE COMMAND!! try again\n");
        }
    }
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// MAIN CODE
int main() {
    menu();
    return 0;
}
