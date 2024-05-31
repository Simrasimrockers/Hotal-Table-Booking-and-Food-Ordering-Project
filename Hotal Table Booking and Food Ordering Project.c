//Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure
typedef struct
{
    int id;
    char name[50];
    float price;
    char category[20];
} MenuItem;

// Functions
void signup();
void login();
void menu();
void takeOrder(MenuItem menu[], int size, const char *category);
void displayMenu(MenuItem menu[], int size, const char *category);
void selectCategoryAndOrder(MenuItem menu[], int size);
void reserveTable();
void collectReview();
void get_Feedback();
void contact_details();
void takepassword(char password[20]);

//Global Variables
int found1;
char username[100];
char name[20];
int tab_no;
int day;
char month[10];
int time;
char am_pm[20];
char opt;

//Main Functions
int main()
{
    system("color 06");
    int choice1,choice2;
    system("cls");
    printf("\t\t_______________\n");
    printf("\t\t|             |\n");
    printf("\t\t|_S_R_K_Grand_|\n");
    printf("\t\t|-------------|\n");
    printf("\t\t|*************|\n");
    printf("\t\t|/////////////|\n");
    printf("\t\t|    _____    |\n");
    printf("\t\t|    |   |    |\n");
    printf("\t\t|    |   |    |\n");
    printf("\t\t|-------------|\n");

    printf("\n\n\t****** WELCOME TO SRK Grand ******\n\n");
    rtn:
    printf("\n\n\t\t+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+--\n");
        printf("\t\t+ \t\t         \t\t\t+\n\t\t+\t\t    MENU\t\t\t");
        printf("+\n\t\t+\t\t\t\t\t\t+\n\t\t+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
        printf("\t\t+\t\t\t\t\t\t+\n\t\t+ \t 1.SIGNUP\t\t\t\t+\n\t\t+\t\t\t\t\t\t+\n");
        printf("\t\t+\t 2.LOGIN\t\t\t\t+\n\t\t+\t\t\t\t\t\t+\n\t\t");
        printf("+\t 3.LOGOUT\t\t\t\t+\n\t\t+\t\t\t\t\t\t+\n\t\t");
        printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-\n\n");
        printf("\n\n\n\t\tEnter your choice:");
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
            printf("\n\t\t\t\tHello %s...Welcome to SRK Grand.\n\n",username);
            printf("\t\t\tSteps to reserve table and Ordering Foods........\n\n");
            printf("\t\tStep 1 : Reserve Your Table (Check the Vacancies of Tables and \n\t\t  Reserve the Free Table By Filling some Basic Details)\n");
            printf("\t\tStep 2 : Next Enter Y/y to order the Food\n");
            printf("\t\tStep 3 : Wait for Few seconds for order Conformation \n");
            printf("\t\tStep 4 : Process complete\n");
            printf("\n\t\t\t\t\"It's Time to Eat\" ");
            printf("\n\n\n\tPress Y/y to Start : ");
            char opt;
            fflush(stdin);
            opt=getch();
            if(opt=='y'||opt=='Y')
            {
                reserveTable();
            }
            else{
                 get_Feedback();
            }
        }
    else
        {
             printf("Invalid username or password / if you sign up now means Press 2 to login\n");
            goto rtn;

        }
}

//Sign up Functions
void signup()
{
    char password[100];
    up:
    printf("\n\n\t\tEnter user name:");
    scanf("%s", username);
    FILE *file = fopen("users.csv", "a+");
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
            printf("\n\n\t\tUsername already exists. Please choose a different one.\n");
            printf("\n\n\t\t\tPress Enter to Continue ..... ");
            getch();
            goto up;
        }
    }
    fclose(file);
    printf("\n\t\tEnter password: ");
    takepassword(password);
    file = fopen("users.csv", "a");
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", "users.csv");
        exit(1);
    }
    fprintf(file, "%s,%s\n", username, password);
    fclose(file);
    printf("Signup successful\n");
}

//Login Function
void login()
{
    char password[100], file_username[100], file_password[100];
    printf("\n\n\t\tEnter username: ");
    scanf("%s", username);
    printf("\n\t\tEnter password: ");
    takepassword(password);

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

//Take Password
void takepassword(char password[20])
{
    int i=0;
    char ch;
    while(1)
    {
        ch = getch();
        if(ch==13){
            password[i]='\0';
            break;
        }
        else if(ch==8)   //backspace
        {
            if(i>0)
            {
                i--;
                printf("\b\b");
            }
        }
        else if(ch==9||ch==32){  //Space || Tab
            continue;
        }
        else{
            password[i++]=ch;
            printf("*");
        }
    }
    printf("\n");
}

// Reserve Table Function
void reserveTable() {

    FILE *file = fopen("reserved.csv", "r");
    if (file != NULL) {
        printf("\n\n\tCurrently booked tables:\n\n");
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("\t\t%s", line);
        }
        fclose(file);
    }

    while (1) {
        printf("\n\n\t\tEnter Your Name: ");
        scanf("%s", name);
        printf("\t\tEnter Table number (1 to 10): ");
        scanf("%d", &tab_no);
        printf("\t\tEnter Date and month (e.g., 20 May): ");
        scanf("%d %s", &day, month);
        printf("\t\tEnter Time (e.g., 4 PM): ");
        scanf("%d %s", &time, am_pm);

        // Validate time
        if (time < 1 || time > 12 || (strcmp(am_pm, "AM") != 0 && strcmp(am_pm, "PM") != 0)) {
            printf("\t\tInvalid time format. Please try again.\n");
            continue;
        }

        // Check for duplicate reservations
        int duplicate = 0;
        file = fopen("reserved.csv", "r");
        if (file != NULL) {
            char file_line[256];
            while (fgets(file_line, sizeof(file_line), file)) {
                int file_tab_no, file_day, file_time;
                char file_month[10], file_am_pm[10], file_name[20];
                sscanf(file_line, "Table %d was successfully reserved for %d %s on %s %d by %s.\n",
                       &file_tab_no, &file_time, file_am_pm, file_month, &file_day, file_name);
                if (file_tab_no == tab_no && file_day == day && strcmp(strupr(file_month), strupr(month)) == 0 &&
                    file_time == time && strcmp(strupr(file_am_pm), strupr(am_pm)) == 0) {
                    duplicate = 1;
                    break;
                }
            }
            fclose(file);
        }

        if (duplicate) {
            printf("\t\tThe table %d is already reserved for %d %s on %s %d. Please choose a different table or time.\n",
                   tab_no, time, am_pm, month, day);
        } else {
            break;
        }
    }

    file = fopen("reserved.csv", "a");
    if (file != NULL) {
        fprintf(file, "Table %d was successfully reserved for %d %s on %s %d by %s.\n", tab_no, time, am_pm, strupr(month), day, name);
        fclose(file);
        printf("\tTable %d was successfully reserved for %d %s on %s %d by %s.\n", tab_no, time, am_pm,strupr(month), day, name);
    }

    printf("\n\tPress Y/y to Order Food: ");
    char opt;
    fflush(stdin);
    opt = getch();
    if (opt == 'y' || opt == 'Y') {
        menuf();
    } else {
        get_Feedback();
    }
}

//Menu Function
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
        {12,"S.R.K special starters platter",865.00,"Starters"},

        {13, "Paneer Butter Masala", 200.00, "Main Course"},
        {14, "Kaju Butter Masala", 220.00, "Main Course"},
        {15, "Mushroom Masala", 260.00, "Main Course"},
        {16, "Dal makhani ", 200.00, "Main Course"},
        {17, "Butter Chicken", 200.00, "Main Course"},
        {18, "Biryani(veg)", 180.00, "Main Course"},
        {19, " Hyderbad dum Biryani ", 200.00, "Main course"},
        {20, "S.R.K special Biryani", 400.00, "Main course"},
        {21, "Nalli ka Gosh Biryani ", 500.00, "Main course"},
        {22, "Mutton Briyani ", 300.00, "Main course"},

        {23, "Gulab Jamun", 30.00, "Desserts"},
        {24, "Rasgulla", 25.50, "Desserts"},
        {25, "Ras Malai", 35.50, "Desserts"},
        {26, "Double ka Meeta", 65.50, "Desserts"},
        {27, "Matka Kulfi ", 45.50, "Desserts"},
        {28, "S.R.K SP Kheer", 75.50, "Desserts"},

        {29, "Badam Kheer", 75.50, "Drinks"},
        {30, "Rose milk", 65.50, "Drinks"},
        {31, "Sweet lassi", 55.50, "Drinks"},
        {32, "Lemonade", 45.50, "Drinks"},
        {33, "Body cooler", 55.50, "Drinks"},
        {34, "Tender coconut water ", 55.50, "Drinks"},
        {35, "Fresh Sugarcane Juice", 55.50, "Drinks"},
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    selectCategoryAndOrder(menu, menuSize);
}

//Select Category And Order Function
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

//Display Menu Function
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

void takeOrder(MenuItem menu[], int size, const char *category) {
    int choice, quantity;
    float total = 0;
    static float overalltotal = 0;
    char more;

    printf("\n\t--- Take Order from %s ---\n", category);

    do {
        displayMenu(menu, size, category);
        printf("\nEnter the item number to order: ");
        scanf("%d", &choice);

        int found = 0;
        FILE *file = fopen("order.csv", "a");
        if (file != NULL) {
            for (int i = 0; i < size; i++) {
                if (menu[i].id == choice && strcmp(menu[i].category, category) == 0) {
                    found = 1;
                    printf("\nEnter the quantity: ");
                    scanf("%d", &quantity);
                    total = menu[i].price * quantity;
                    overalltotal += total;
                    fprintf(file, "%d,%s,%s,%s,%s,%.2f,%d,%.2f\n", tab_no, username, name, menu[i].category, menu[i].name, menu[i].price, quantity, total);
                    break;
                }
            }
            fclose(file);
        }
        if (!found) {
            printf("Invalid item number. Please try again.\n");
            continue;
        }
        printf("\nDo you want to order another item from %s? (y/n): ", category);
        more = getch();
    } while (more == 'y' || more == 'Y');

    printf("\nDo you want to order another Category(y/n): ");
    char opt;
    fflush(stdin);
    opt = getch();
    if (opt == 'y' || opt == 'Y') {
        menuf();
    } else {
        printf("\n\nYour total bill for your Order is: %.2f Rs\n", overalltotal);
        get_Feedback();
    }
}


//Collect Review function
void collectReview()
{
    char feedback[100];
    char star[10];

    rating:
    printf("\n\n\t\tEnter your Rating 1 / 5 ( * / ***** ): ");
    scanf("%s",star);

    int count_star = strlen(star);
    int i;
    for (i = 0; i < count_star; i++) {
        if (star[i] != '*') {
            printf("Invalid Input. Please provide a rating from 1 to 5 using asterisks (*).\n");
            goto rating;
        }
    }

    switch (count_star) {
    case 1:
        printf("Bad\n");
        break;
    case 2:
        printf("Not bad\n");
        break;
    case 3:
        printf("Good\n");
        break;
    case 4:
        printf("Excellent\n");
        break;
    case 5:
        printf("Marvelous\n");
        break;
    default:
        printf("Invalid Rating\n");
        goto rating;
    }

    printf("Enter Your Review: ");
    scanf(" %[^\n]", feedback);

    FILE* file = fopen("feedback.txt", "a");
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", "feedback.txt");
        return 1;
    }
    else {
        fprintf(file, "Rating: %s (%d/5)\n", star,count_star);
        fprintf(file, "Review: %s\n\n", feedback);
        fclose(file);
        printf("Thank you for your feedback!\n");
    }
}

//Get Feedback
void get_Feedback()
{
    printf("\n\tPress Y/y to Feedback about this Services or Press any key to Exit: ");
    fflush(stdin);
    opt=getch();
    if(opt=='y'||opt=='Y')
    {
        collectReview();
        printf("\n\n\t\tPress Y/y to View Contact Details : ");
        fflush(stdin);
        opt=getch();
        if(opt=='y'||opt=='Y')
        {
            contact_details();
        }

    }
    else
    {
        printf("\n\t\t\tPress Y/y to View Contact Details : ");
        fflush(stdin);
        opt=getch();
        if(opt=='y'||opt=='Y')
        {
            contact_details();
        }

    }
    exit(0);
}

//Contact Details Function
void contact_details()
{
    printf("\n\n\n\n\t\t\t\t\t***THANK YOU FOR VISITING OUR RESTAURANT***\n\nFor more information,contact below: \n");
    printf("\n\t\tADDRESS:- \n\n\t\t\tSIMRASIM ROCKERS ");
    printf("\n\t\t\tNo XX, AhXX PiXXXXle, Grdxxx Foxxrx,\n\t\t\tXth Main, Xnd Cross, ");
    printf("Xth Block\n\t\t\tKoraXXXXXXX Inixxxxxxal Area - XXXXXXXre,\n\t\t\tXXXXXXka - XXX095,\n\t\t\tIndia ");
    printf("\n\n\t\t\tPhone +91 98 7654 9876\n\n\t\t\tMobile +91 99 7878 6789\n\n\t\t\tEmail : demo12345.in\n\n\n");
    printf("\n\n\t\t\t\t\t\t*******************\t\t\t\t");
    FILE *file = fopen("feedback.txt", "r");
    if (file == NULL)
    {
        printf("Could not open file %s for reading.\n", "feedback.txt");
    }
    else
    {
        printf("\n\n\tReviews : \n\n");
        char line[256];
        while (fgets(line, sizeof(line), file))
        {
            printf("\t\t%s", line);
        }
        fclose(file);
    }

}
