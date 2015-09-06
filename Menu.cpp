/******************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name:  Menu.cpp
 * Description: This is the main for the Final Project in CS 165.
 * ***************************************************************/
#include "LibraryItem.hpp"
#include "Book.hpp"
#include "Album.hpp"
#include "Movie.hpp"
#include "Patron.hpp"
#include "Library.hpp"

#include <iostream> // input and output
#include <limits> // Used with cin.ignore() in programMenu()
#include <cstdlib> // For system clear
using namespace std;

//Function Prototypes:
int programMenu();

//Main function:
int main () {

   Library simulation;

   int input = 0; // Variable for program menu choice
   while (input !=12)
   {
      system("clear");
      input = programMenu();

      if (input == 1) // Add Book to Library Holdings
      {
         string title, author, id;

         //User input:
         cout << " ADD BOOK TO LIBRARY HOLDINGS" << endl;
         cout << "------------------------------" << endl;
         cout << " Enter Title:  ";
         getline(cin, title);
         cout << " Enter Author:  ";
         getline(cin, author);
         cout << " Assign Unique ID#:  ";
         getline(cin, id);
        
         //Input validation: 
         LibraryItem* check = simulation.findHolding(id);
         if (check != NULL)
         {
            cout << endl << "That ID is already in use." << endl;
         }
         else
         {
            Book *newItem; // Allocate memory for Library Item
            newItem = new Book(id, title, author); // Create Library Item

            simulation.addLibraryItem(newItem); // Add item to Library
            cout << endl << "The book has been added to the library." << endl;         
         } 
 
         cout << endl << "Press [Enter] to return to the main menu." << endl;
         cin.ignore();         
      }

      if (input == 2) // Add Movie to Library Holdings
      {   
         string title, director, id;

         //User input:
         cout << " ADD MOVIE TO LIBRARY HOLDINGS" << endl;
         cout << "-------------------------------" << endl;
         cout << " Enter Title:  ";
         getline(cin, title);
         cout << " Enter Director:  ";
         getline(cin, director);
         cout << " Assign Unique ID#:  ";
         getline(cin, id);
         
         //Input validation: 
         LibraryItem* check = simulation.findHolding(id);
         if (check != NULL)
         {
            cout << endl << "That ID is already in use." << endl;
         }
         else
         {
            Movie *newItem; // Allocate memory for Library Item
            newItem = new Movie(id, title, director); // Create Library Item
 
            simulation.addLibraryItem(newItem); // Add item to Library
            cout << endl << "The movie has been added to the library." << endl;
         }  

         cout << endl << "Press [Enter] to return to the main menu." << endl;
         cin.ignore();         
      }

      if (input == 3) // Add Album to Library Holdings
      {
         string title, artist, id;

         //User input:
         cout << " ADD ALBUM TO LIBRARY HOLDINGS" << endl;
         cout << "-------------------------------" << endl;
         cout << " Enter Title:  ";
         getline(cin, title);
         cout << " Enter Artist:  ";
         getline(cin, artist);
         cout << " Assign Unique ID#:  ";
         getline(cin, id);
         
         //Input validation: 
         LibraryItem* check = simulation.findHolding(id);
         if (check != NULL)
         {
            cout << endl << "That ID is already in use." << endl;
         }
         else
         {
            Album *newItem; // Allocate memory for Library Item
            newItem = new Album(id, title, artist); // Create Library Item

            simulation.addLibraryItem(newItem); // Add item to Library         
            cout << endl << "The album has been added to the library." << endl;
         }

         cout << endl << "Press [Enter] to return to the main menu." << endl;
         cin.ignore();         
      } 

      if (input == 4) // Add New Library Member
      {
         string name, id;         

         // User input:
         cout << " ADD NEW LIBRARY MEMBER" << endl;
         cout << "------------------------" << endl;
         cout << " Enter Name:  ";
         getline(cin, name);
         cout << " Enter Unique ID#:  ";
         getline(cin, id);

         //Input validation: 
         Patron* check = simulation.findMember(id);
         if (check != NULL)
         {
            cout << endl << "That ID is already in use." << endl;
         }
         else
         {
            Patron *patron; // Allocate memory for Patron
            patron = new Patron(id, name); // Create Patron

            simulation.addMember(patron); //Add member to Library
            cout << endl << "The patron has been added to the library." << endl;
         }

         cout << endl << "Press [Enter] to return to the main menu." << endl;
         cin.ignore();         
      } 

      if (input == 5) // Pay Library Fine
      {
         string id;
         double payment;

         cout << " MAKE A PAYMENT ON A LIBRARY FINE " << endl;
         cout << "----------------------------------" << endl;
         cout << " Enter Patron ID#:  ";
         getline(cin, id);
         cout << " Enter Payment Amount:  $";
         cin >> payment;
         payment *= -1;

         cout << endl;
         simulation.payFine(id, payment);

         cin.ignore(); 
         cout << endl << "Press [Enter] to return to the main menu." << endl;
         cin.ignore();         
      } 

      if (input == 6) // View Library Member Account
      {
         string id;

         cout << " VIEW LIBRARY MEMBER ACCOUNT" << endl;
         cout << "-----------------------------" << endl;
         cout << " Enter Patron ID#:  ";
         cin >> id;

         cout << endl;
         simulation.viewPatronInfo(id);
         cin.ignore();

         cout << endl << "Press [Enter] to return to the main menu." << endl;
         cin.ignore();         
      } 

      if (input == 7) // View Library Item Information
      {
         string id;
 
         cout << " VIEW LIBRARY ITEM INFORMATION" << endl;
         cout << "-------------------------------" << endl;
         cout << " Enter Item ID#:  ";
         getline(cin, id);
          
         cout << endl;
         simulation.viewItemInfo(id);

         cout << endl << "Press [Enter] to return to the main menu." << endl;
         cin.ignore();         
      } 

      if (input == 8) // Request Item from Library
      {
         string ID, ItemID;

         cout << " REQUEST ITEM FROM LIBRARY" << endl;
         cout << "---------------------------" << endl;
         cout << " Enter Patron ID#:  ";
         getline(cin, ID);
         cout << " Enter Item ID#:  ";
         getline(cin, ItemID);

         cout << endl;
         simulation.requestLibraryItem(ID, ItemID);
         
         cout << endl << "Press [Enter] to return to the main menu." << endl;
         cin.ignore();         
      } 

      if (input == 9) // Check Out Library Item
      {
         string ID, ItemID;

         cout << " CHECK OUT LIBRARY ITEM" << endl;
         cout << "------------------------" << endl;
         cout << " Enter Patron ID#:  ";
         getline(cin, ID);
         cout << " Enter Item ID#:  ";
         getline(cin, ItemID);

         cout << endl;
         simulation.checkOutLibraryItem(ID, ItemID);
         
         cout << endl << "Press [Enter] to return to the main menu." << endl;
         cin.ignore();         
      } 

      if (input == 10) // Return Library Item
      {
         string id;

         cout << " RETURN LIBRARY ITEM" << endl;
         cout << "---------------------" << endl;
         cout << " Enter Item ID#:  ";
         getline(cin, id);

         cout << endl;
         simulation.returnLibraryItem(id);
         
         cout << endl << "Press [Enter] to return to the main menu." << endl;
         cin.ignore();         
      } 

      if (input == 11) // Increment Current Date
      {
         simulation.incrementCurrentDate();
         cout << "The date has been incremented." << endl;         
         
         cout << endl << "Press [Enter] to return to the main menu." << endl;
         cin.ignore();         
      } 
   }

   return 0;
}


/*********************************************
 *               programMenu()
 * This function prints the menu options each
 * time it is called and allows the user
 * to select a menu choice. Then it returns
 * this choice back to the main program.
 * ******************************************/

int programMenu()
{
   int input; // Local variable
   bool integerFail = false; // Ensure integer input

   cout << endl << endl << endl;
   cout << "       ==========================================" << endl;
   cout << "       |             The Library Menu           |" << endl;
   cout << "       ==========================================" << endl;
   cout << "       |   1.  Add Book to Library Holdings     |" << endl;
   cout << "       |   2.  Add Movie to Library Holdings    |" << endl;
   cout << "       |   3.  Add Album to Library Holdings    |" << endl;
   cout << "       |   4.  Add New Library Member           |" << endl;
   cout << "       |   5.  Pay Library Fine                 |" << endl;
   cout << "       |   6.  View Library Member Account      |" << endl;
   cout << "       |   7.  View Library Item Information    |" << endl;
   cout << "       |   8.  Request Item from Library        |" << endl;
   cout << "       |   9.  Check Out Library Item           |" << endl;
   cout << "       |   10. Return Library Item              |" << endl;
   cout << "       |   11. Increment Current Date           |" << endl;
   cout << "       |   12. Quit Program                     |" << endl;
   cout << "       ==========================================" << endl;
   cout << "        Enter:  ";

   do {
      cin >> input; // User input here
      integerFail = cin.fail();
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while (integerFail == true);
   cout << endl;

   return input;
}
