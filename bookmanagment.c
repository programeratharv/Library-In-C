// Created By Atharv On 10 Jun 2024
// Book Managment System 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Book
{   
    int id;
    char name[50];
    char author[50];
    char category[50];
    float price;
    float rating;
}Book;
int book_count = 0;//For maintain Count Of Book
void addBook(Book*);
void removeBook(Book*);
void searchBook(Book*);
void showAuthorsBook(Book*);
void showCategoryBook(Book*);
void updateBookData(Book*);
void displayTopBook(Book*);
void sortByPrice(Book*);
void sortByRating(Book*); 
void displayAllBooks(Book*);
int main()
{
    Book library[100];
    int choice;
    // While Loop To Continue Iterate In Choice Menu Until User Request To Exit
    while(1)
    {   
        // Display Menu
        printf("\n********** Book Managment System **********\n");
        printf("1.Add Book\n");
        printf("2.Remove Book\n");
        printf("3.Search Book\n");
        printf("4.Show Author's Book's\n");
        printf("5.Show Category's Book's\n");
        printf("6.Update Book Data\n");
        printf("7.Display Sorted Book's\n");
        printf("8.Display All Book's\n");
        printf("9.Exit\n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);

        // Switch Case To Perform Perticular Task As Per Users Input.
        switch(choice)
        {
            case 1:
            addBook(library);
            break;

            case 2:
            removeBook(library);
            break;

            case 3:
            searchBook(library);
            break;

            case 4:
            showAuthorsBook(library);
            break;

            case 5:
            showCategoryBook(library);
            break;

            case 6:
            updateBookData(library);
            break;

            case 7:
            displayTopBook(library);
            break;

            case 8:
            displayAllBooks(library);
            break;

            case 9:
            printf("Thank You For Visiting Our Book Managment System..");
            exit(0);

            default :
                printf("\nInvalid Choice Enter Choice Between 1 To 9");
        }
    }
}
// Function 01 To Add Books 
void addBook(Book* library)
{   
     //library = malloc(library, (book_count + 1) * sizeof(Book));
    printf("Enter Book ID: ");
    scanf("%d", &library[book_count].id);
    printf("Enter Book Name: ");
    scanf("%s", library[book_count].name);
    printf("Enter Author Name: ");
    scanf("%s", library[book_count].author);
    printf("Enter Category: ");
    scanf("%s", library[book_count].category);
    printf("Enter Price: ");
    scanf("%f", &library[book_count].price);
    printf("Enter Rating: ");
    scanf("%f", &library[book_count].rating);
    book_count++;
}
// Function 02 To Remove Books. (Delete)
void removeBook(Book* library)
{
    int id, i, found = 0;
    printf("Enter Book Id To Remove Book:");
    scanf("%d",&id);
    for (i = 0; i < book_count; i++) 
    {
        if (library[i].id == id)
        {
            found = 1;
            for (int j = i; j < book_count - 1; j++) 
            {
                library[j] = library[j + 1];
            }
           // library = realloc(library, (book_count - 1) * sizeof(Book));
            book_count--;
            break;
        }
    }
    if (!found) 
    {
        printf("Book not found!\n");
    } else 
    {
        printf("Book removed successfully.\n");
    }
}
// Function 03 To Search Book. (Search)
void searchBook(Book* library)
{
    int id, i, found = 0;
    char name[100];
    printf("Enter 1 to search Book by ID, 2 to search Book by Name: ");
    scanf("%d", &id);
    // Search Book By id 
    if (id == 1) 
    {
        printf("Enter Book ID: ");
        scanf("%d", &id);
        for (i = 0; i < book_count; i++) 
        {
            if (library[i].id == id) 
            {
                found = 1;
                printf("Book found: %s by %s\n", library[i].name, library[i].author);
                break;
            }
        }
    } 
    // Search Book By Name 
    else if (id == 2) 
    {
        printf("Enter Book Name: ");
        scanf("%s", name);
        for (i = 0; i < book_count; i++) 
        {
            if (strcmp(library[i].name, name) == 0) 
            {
                found = 1;
                printf("Book found: %s by %s\n", library[i].name, library[i].author);
                break;
            }
        }
    }
    if (!found) 
    {
        printf("Book not found!\n");
    }
}
// Function 04 To Show Authors Book 
void showAuthorsBook(Book* library)
{
    char authorName[100];
    printf("Enter Author Name To Show Book:");
    scanf("%s",authorName);
    printf("Book's By %s author:\n",authorName);
    for(int i = 0; i < book_count; i++)
    {
        if(strcmp(library[i].author,authorName)== 0)
        {   
            printf("%s\n",library[i].name);
        }
    }
}
// Function 05 Show Category Book
void showCategoryBook(Book* library)
{
    char category[50];
    printf("Enter Category Of Book To Display Books : ");
    scanf("%s",category);
    printf("Books in category %s:\n", category);
    for (int i = 0; i < book_count; i++) 
    {
        if (strcmp(library[i].category, category) == 0) 
        {
            printf("%s by %s\n", library[i].name, library[i].author);
        }
        else 
        {
            printf("Book Not Avalable");
        }
    }
}
// Function 06 To Update Book Data
void updateBookData(Book* library)
{
int id, i, found = 0;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);
    for (i = 0; i < book_count; i++) 
    {
        if (library[i].id == id) 
        {
            found = 1;
            printf("Enter New Price Of The Book: ");
            scanf("%f", &library[i].price);
            printf("Enter New Rating Of The  Book: ");
            scanf("%f", &library[i].rating);
            printf("Book updated successfully.\n");
            break;
        }
    }
}
// Function 07 To Display Sorted Books (Sort By Price, Rating)
void displayTopBook(Book* library)
{
    
    
    int choice;
    printf("\nChoose an option:\n");
    printf("1. Highest Priced\n");
    printf("2. Lowest Priced\n");
    printf("3. Highest Rated\n");
    printf("4. Lowest Rated\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            sortByPrice(library);
            printf("Highest Priced Books:\n");
            for (int i = book_count - 1; i >= 0; i--) 
            {
                printf("%s by %s - Price: Rs.%.2f\n", library[i].name, library[i].author, library[i].price);
            }
            break;
        case 2:
            sortByPrice(library);
            printf("Lowest Priced Books:\n");
            for (int i = 0; i < book_count; i++) 
            {
                printf("%s by %s - Price: Rs.%.2f\n", library[i].name, library[i].author, library[i].price);
            }
            break;
        case 3:
            sortByRating(library);
            printf("Highest Rated Books:\n");
            for (int i = 0; i < book_count; i++) 
            {
                printf("%s by %s - Rating: %.2f stars\n", library[i].name, library[i].author, library[i].rating);
            }
            break;
        case 4:
            sortByRating(library);
            printf("Lowest Rated Books:\n");
            for (int i = book_count - 1; i >= 0; i--) 
            {
                printf("%s by %s - Rating: %.2f stars\n", library[i].name, library[i].author, library[i].rating);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
}
// Function 7.1 To Sort Books By Ascending Order of Price
void sortByPrice(Book* library) 
{
    for (int i = 0; i < book_count - 1; i++) 
    {
        for (int j = 0; j < book_count - i - 1; j++) 
        {
            if (library[j].price > library[j + 1].price) 
            {
                // Swap books
                Book temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
        }
    }
}
// Function 7.2 To Sort Books By Ascending Order Of Rating
void sortByRating(Book* library) 
{
    for (int i = 0; i < book_count - 1; i++) 
    {
        for (int j = 0; j < book_count - i - 1; j++) 
        {
            if (library[j].rating < library[j + 1].rating) 
            {
                // Swap books
                Book temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
        }
    }
}
// Function 08 TO Display All Book's Available 
void displayAllBooks(Book* library)
{
    printf("All books in the database:\n");
    for (int i = 0; i < book_count; i++) 
    {
        printf("ID: %d\nName: %s\n Author: %s\n Category: %s\n Price: Rs.%.2f\n Rating: %.2f stars\n",library[i].id, library[i].name, library[i].author, library[i].category, library[i].price, library[i].rating);
    }
}