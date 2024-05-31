#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char name[50];
    float price;
    char category[20];
} MenuItem;

void signup();
void login();
void menu();
void takeOrder(MenuItem menu[], int size, const char *category);
void displayMenu(MenuItem menu[], int size, const char *category);
void selectCategoryAndOrder(MenuItem menu[], int size);
void reserveTable();
void collectFeedback();

int found1;
char username[100];
char name[20];
int tab_no;
int day;
char month[10];
int time;
char am_pm[20];
int main()
{
    system("color f1");
    int choice1,choice2;
    system("cls");
    printf("\t\t_______________\n");
    printf("\t\t|             |\n");
    printf("\t\t|_A_S_K_Grand_|\n");
    printf("\t\t|-------------|\n");
    printf("\t\t|*************|\n");
    printf("\t\t|/////////////|\n");
    printf("\t\t|    _____    |\n");
    printf("\t\t|    |   |    |\n");
    printf("\t\t|    |   |    |\n");
    printf("\t\t|-------------|\n");

    printf("\n\n\t****** WELCOME TO ASK Grand ******\n\n");
    rtn:
    printf("1. Signup\n2. Login\n3. Exit\nEnter your choice: ");
    scanf("%d",&choice1);

    switch (choice1)
    {
        case 1:
            signup();
            break;
        case 2:
            login();
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
    }
        if (found1)
        {
            printf("\n\t\t\t\tHello %s...Welcome to ASK Grand.\n\n",username);
            printf("\t\t\tSteps to reserve table and Ordering Foods........\n\n");
            printf("\t\tStep 1 : Reserve Your Table (Check the Vacancies of Tables and \n\t\t  Reserve the Free Table By Filling some Basic Details)\n");
            printf("\t\tStep 2 : Next Enter Y/y to order the Food\n");
            printf("\t\tStep 3 : Wait for Few seconds for order Conformation \n");
            printf("\t\tStep 4 : Process complete\n");
            printf("\n\t\t\t\t\"It's Time to Eat\" ");
            printf("\n\n\n\tPress Y/y to Start : ");
            char opt;
            fflush(stdin);
            scanf("%c",&opt);
            if(opt=='y'||opt=='Y')
            {
                reserveTable();
            }
        }
    else
        {
             printf("Invalid username or password / if you sign up now means Press 2 to login\n");
            goto rtn;

        }
}

void signup()
{
    char password[100];
    printf("Enter user name:");
    scanf("%s", username);
    FILE *file = fopen("users.csv", "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        exit(1);
    }

    char file_username[100];
    while (fscanf(file, "%[^,],%*[^\n]\n", file_username) != EOF)
    {
        if (strcmp(username, file_username) == 0)
        {
            printf("Username already exists. Please choose a different one.\n");
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("Enter password: ");
    scanf("%s", password);
    file = fopen("users.csv", "a");
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", "users.csv");
        exit(1);
    }
    fprintf(file, "%s,%s\n", username, password);
    fclose(file);
    printf("Signup successful\n");
}

void login()
{
    char password[100], file_username[100], file_password[100];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen("users.csv", "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        exit(1);
    }

     found1 = 0;
    while (fscanf(file, "%[^,],%s\n", file_username, file_password) != EOF)
        {
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0)
            {
            found1 = 1;
            break;
        }
    }
    fclose(file);

}

void reserveTable()
{


    FILE *file = fopen("reserved.csv", "r");
    if (file == NULL)
    {
        printf("Could not open file %s for reading.\n", "reserved.csv");
    }
    else
    {
        printf("\n\n\tCurrently booked tables:\n\n");
        char line[256];
        while (fgets(line, sizeof(line), file))
        {
            printf("\t\t%s", line);
        }
        fclose(file);
    }

    printf("\n\n\t\tEnter Your Name: ");
    scanf("%s", name);
    printf("\t\tEnter Table number (1 to 10): ");
    scanf("%d", &tab_no);
    printf("\t\tEnter Date and month (eg 20 may): ");
    scanf("%d %s", &day, month);
    printf("\t\tEnter Time (eg: 4 pm): ");
    scanf("%d %s", &time, am_pm);

    file = fopen("reserved.csv", "a");
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", "reserved.csv");
    }
    else
    {
    fprintf(file, "Table %d was successfully reserved for %d %s on %s %d by %s.\n", tab_no, time, am_pm, month, day, name);
    fclose(file);
    printf("\tTable %d was successfully reserved for %d %s on %s %d by %s.\n", tab_no, time, am_pm, month, day, name);
    }
    printf("\n\tPress Y/y to Order Food : ");
    char opt;
            fflush(stdin);
            scanf("%c",&opt);
            if(opt=='y'||opt=='Y')
            {
                 menuf();
            }

}
void menuf()
{
    printf("\n\t---Menu---\n");
    MenuItem menu[] =
    {
        {1, "Samosa", 11.50, "Starters"},
        {2, "Paneer Tikka", 18.00, "Starters"},
        {3, "Veg Cutlet", 20.00,"Starters"},
        {4, "Pav Bhaji",65.00,"Starters"},
        {5, "Mushroom 65",165.00,"Starters"},
        {6, "Gobi Manchuria",95.00,"Starters"},
        {7, "Egg Manchuria",65.00,"Starters"},
        {8, "Chicken Tandoori",265.00,"Starters"},
        {9, "Sheer Kebab",265.00,"Starters"},
        {10,"VEG starters combo",465.00,"Starters"},
        {11,"Non Veg starters combo",565.00,"Starters"},
        {12,"A.S.K special starters platter",865.00,"Starters"},

        {13, "Paneer Butter Masala", 200.00, "Main Course"},
        {14, "Kaju Butter Masala", 220.00, "Main Course"},
        {15, "Mushroom Masala", 260.00, "Main Course"},
        {16, "Dal makhani ", 200.00, "Main Course"},
        {17, "Butter Chicken", 200.00, "Main Course"},
        {18, "Biryani(veg)", 180.00, "Main Course"},
        {19, " Hyderbad dum Biryani ", 200.00, "Main course"},
        {20, "A.S.K special Biryani", 400.00, "Main course"},
        {21, "Nalli ka Gosh Biryani ", 500.00, "Main course"},
        {22, "Mutton Briyani ", 300.00, "Main course"},

        {23, "Gulab Jamun", 30.00, "Desserts"},
        {24, "Rasgulla", 25.50, "Desserts"},
        {25, "Ras Malai", 35.50, "Desserts"},
        {26, "Double ka Meeta", 65.50, "Desserts"},
        {27, "Matka Kulfi ", 45.50, "Desserts"},
        {28, "A.S.K SP Kheer", 75.50, "Desserts"},

        {29, "Badam Kheer", 75.50, "Drinks"},
        {30, "Rose milk", 65.50, "Drinks"},
        {31, "Sweet lassi", 55.50, "Drinks"},
        {32, "Lemonade", 45.50, "Drinks"},
        {33, "Body cooler", 55.50, "Drinks"},
        {33, "Tender coconut water ", 55.50, "Drinks"},
        {33, "Fresh Sugarcane Juice", 55.50, "Drinks"},
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    selectCategoryAndOrder(menu, menuSize);
}
void selectCategoryAndOrder(MenuItem menu[], int size)
{
    int choice;
    while (1)
    {
        printf("\n--- Select a Category ---\n");
        printf("\t1. Starters\n");
        printf("\t2. Main Course\n");
        printf("\t3. Drinks\n");
        printf("\t4. Desserts\n");
        printf("\t5. Exit\n");
        printf("\n\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                takeOrder(menu, size, "Starters");
                break;
            case 2:
                takeOrder(menu, size, "Main Course");
                break;
            case 3:
                takeOrder(menu, size, "Drinks");
                break;
            case 4:
                takeOrder(menu, size, "Desserts");
                break;
            case 5:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void displayMenu(MenuItem menu[], int size, const char *category)
{
    printf("\n--- %s ---\n", category);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(menu[i].category, category) == 0)
        {
            printf("%d. %s - %.2f Rs\n", menu[i].id, menu[i].name, menu[i].price);
        }
    }
}

void takeOrder(MenuItem menu[], int size, const char *category)
{
    int choice,quantity;
    float total;
    static float overalltotal;
    char more;

    printf("\n\t--- Take Order from %s ---\n", category);

    do {
        displayMenu(menu, size, category);

        printf("\nEnter the item number to order: ");
        scanf("%d", &choice);


        int found = 0;
        FILE *file5 = fopen("order.csv", "a");
    if (file5 != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            if (menu[i].id == choice && strcmp(menu[i].category, category) == 0)
           {
                found = 1;
                printf("\nEnter the quantity: ");
                scanf("%d", &quantity);
                total += menu[i].price * quantity;
                overalltotal+=total;
                fprintf(file5,"%d,%s,%s,%s,%s,%.2f,%d,%.2f\n",tab_no,username,name,menu[i].category,menu[i].name,menu[i].price,
               quantity,total);
                break;
            }
        }
    }fclose(file5);
        if (!found)
        {
            printf("Invalid item number. Please try again.\n");
            continue;
        }


        printf("\nDo you want to order another item from %s? (y/n): ", category);
        scanf(" %c", &more);

    }while (more == 'y' || more == 'Y');
    printf("\nDo you want to order any another Category(y/n): ");
    char opt;
        fflush(stdin);
        scanf("%c",&opt);
        if(opt=='y'||opt=='Y')
            {
                 menuf();
            }
    printf("\n\n");
    char a[15]={'(','L','o','a','d','i','n','g','.','.','.',')'};
    for(int i =0;i<5;i++)
    {
        printf("\r--------------------- )\r");
        for(int j=0;j<=11;j++){
            printf("%c ",a[j]);
            usleep(300000);
        }

    }

    printf("\n\nYour total bill for your Order is: %.2f Rs\n", overalltotal);
    printf("Press Y/y to Feedback about this Services or Press any key to Exit: ");
        fflush(stdin);
        scanf("%c",&opt);
        if(opt=='y'||opt=='Y')
            {
                 collectFeedback();
            }
            else
                printf("\n\n\t\tThank You......");
    exit(0);

}

void collectFeedback()
{
    char feedback[500];
    printf("Enter your feedback: ");
    scanf(" %[^\n]", feedback);
    FILE *file = fopen("feedback.txt", "a");
    if (file == NULL)
    {
        printf("Could not open file %s for writing.\n", "feedback");

    }

    fprintf(file,"%s\n",feedback);
    fclose(file);

    printf("Thank you for your feedback!\n");
}