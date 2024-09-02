This code implements a Book Management System in C, designed to manage a library's collection of books. The program uses a structured approach, with various functions to handle different operations such as adding, removing, searching, and sorting books. Here's a simplified description of the code:

Code Overview:
Book Structure:

The Book structure is defined to store details about each book, including id, name, author, category, price, and rating.
Global Variables:

book_count: Keeps track of the number of books in the library.
Functions:

addBook(Book*): Adds a new book to the library.
removeBook(Book*): Removes a book based on its ID.
searchBook(Book*): Searches for a book either by ID or name.
showAuthorsBook(Book*): Displays all books by a specific author.
showCategoryBook(Book*): Displays all books in a specific category.
updateBookData(Book*): Updates the price and rating of a book based on its ID.
displayTopBook(Book*): Displays books sorted by price or rating.
sortByPrice(Book*): Sorts the books by price in ascending order.
sortByRating(Book*): Sorts the books by rating in descending order.
displayAllBooks(Book*): Displays all the books currently in the library.
Main Function:

The program runs in a loop, displaying a menu with various options (e.g., Add Book, Remove Book, Search Book, etc.).
The user can choose an option to perform a specific task. The loop continues until the user chooses to exit the program.
This system can handle up to 100 books and allows basic operations like adding, removing, and searching for books, as well as sorting and displaying them.
