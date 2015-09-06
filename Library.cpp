/****************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name: Library.cpp
 * Description: Library.cpp is the class function implementation
 * file for the Library class.
 * *************************************************************/
#include "LibraryItem.hpp"
#include "Patron.hpp"
#include "Library.hpp"
#include <cstdlib> // Included for use of NULL pointers.
#include <iostream>
#include <iomanip>
using namespace std;


/***************************************************
 *        Library Class Default Constructor
 * ************************************************/

Library::Library()
{
   currentDate = 0;
}



/***************************************************
 *             Library Class Destructor
 * ************************************************/

Library::~Library()
{ 
   for (int patron = 0; patron < (members.size()); patron++)
   {
      delete members[patron];
   }

   for (int item = 0; item < (holdings.size()); item++)
   {        
      delete holdings[item];
   }
}



/***************************************************
 *               findHolding
 * -find LibraryItem* in the holdings vector
 * ************************************************/

LibraryItem* Library::findHolding(std::string ItemID)
{
   int size = holdings.size();
   for (int index = 0; index < size; index++)
   {
      if ((holdings[index]->getIdCode()) == ItemID)
      {
         return holdings[index];
      }
   }   

   return NULL;
}



/***************************************************
 *               findMember
 * -find Patron* in the members vector
 * ************************************************/

Patron* Library::findMember(std::string patronID)
{
   int size = members.size();
   for (int index = 0; index < size; index++)
   {
      if ((members[index]->getIdNum()) == patronID)
      {
         return members[index];
      }
   }
   
   return NULL;
}



/***************************************************
 *               addLibraryItem
 * -add LibraryItem* item to holdings vector
 * ************************************************/

void Library::addLibraryItem(LibraryItem* item)
{
   holdings.push_back(item);
}



/***************************************************
 *               addMember
 * -add Patron* member to members vector
 * ************************************************/

void Library::addMember(Patron* member)
{
   members.push_back(member);
}



/***************************************************
 *               checkOutLibraryItem
 * -input validation
 * -update holding and patron information to reflect
 *  a successful checked out of a library item by a
 *  patron of the library
 * ************************************************/

void Library::checkOutLibraryItem(std::string patronID, std::string ItemID)
{
   LibraryItem* holding = findHolding(ItemID);
   Patron* member = findMember(patronID);

   if (holding == NULL)
   {
      cout << "Item with ID# " << ItemID;
      cout << " is not a holding in this library." << endl;
      if (member == NULL)
      {
         cout << "A Patron with ID# " << patronID;
         cout << " is not a member of this library." << endl;
      }
      return;
   }
   else if (member == NULL)
   {
      cout << "A Patron with ID# " << patronID;
      cout << " is not a member of this library." << endl;
      if (holding == NULL)
      {
         cout << "Item with ID# " << ItemID;
         cout << " is not a holding in this library." << endl;
      }
      return;
   }
 
   if (holding->getLocation() == CHECKED_OUT) 
   {
      Patron* checker = holding->getCheckedOutBy();
      if ((checker->getIdNum()) == patronID)
      {
         cout << "Item with ID# " << ItemID;
         cout << " is already checked out by " << member->getName();
         cout << "." << endl;
         return;
      }

      cout << holding->getTitle() << " with ID# " << ItemID;
      cout << " is already checked out by another Patron." << endl;
      return;
   }

   if ((holding->getRequestedBy()) != NULL)
   {
      Patron* holder = holding->getRequestedBy();
      if ((holding->getLocation() == ON_HOLD_SHELF) && (holder->getIdNum() != patronID))
      {
         cout << holding->getTitle() << " with ID# " << ItemID;
         cout << " is on hold by another Patron." << endl;
         return;
      }
   }

   //Update LibraryItem's checkedOutBy, dateCheckedOut, and Location.
   holding->setCheckedOutBy(member);
   holding->setDateCheckedOut(currentDate);
   holding->setLocation(CHECKED_OUT);

   //If patron requested this item, update requestedBy.
   if ((holding->getRequestedBy()) != NULL)
   {
      Patron* holder = holding->getRequestedBy();
      if (holder->getIdNum() == patronID)
      {
         holding->setRequestedBy(NULL);
      }
   }   

   //Update Patron's list.
   member->addLibraryItem(holding);

   //Print checked out confirmation.
   cout << holding->getTitle() << " with ID# " << ItemID;
   cout << " has been checked out to " << member->getName() << "." << endl;
}



/***************************************************
 *               returnLibraryItem
 * -input validation
 * -update holding and patron information to reflect
 *  a successful return of a holding of the library
 *  by a patron of the library
 * ************************************************/

void Library::returnLibraryItem(std::string ItemID)
{
   LibraryItem* holding = findHolding(ItemID);

   if (holding == NULL)
   {
      cout << "Item with ID# " << ItemID;
      cout << " is not a holding in this library." << endl;
      return;
   }

   if (holding->getLocation() != CHECKED_OUT) 
   {
      cout << "Item with ID# " << ItemID;
      cout << " is not checked out." << endl;
      return;
   }
   
   Patron* member = holding->getCheckedOutBy();
   
   //Update Patron's list.
   member->removeLibraryItem(holding);
   
   //Update LibraryItem's location.
   if ((holding->getRequestedBy()) != NULL)
   {
      holding->setLocation(ON_HOLD_SHELF);
   }
   else
   {
      holding->setLocation(ON_SHELF);
   }

   //Update checkedOutBy.
   holding->setCheckedOutBy(NULL);

   //Print return confirmation.
   cout << holding->getTitle() << " has been returned." << endl;
}



/***************************************************
 *               requestLibraryItem
 * -input validation
 * -update holding and patron information to 
 *  reflect a successful request for a holding by a
 *  patron of the library
 * ************************************************/

void Library::requestLibraryItem(std::string patronID, std::string ItemID)
{ 
   LibraryItem* holding = findHolding(ItemID);
   Patron* member = findMember(patronID);

   if (holding == NULL)
   {
      cout << "Item with ID# " << ItemID;
      cout << " is not a holding in this library." << endl;
      if (member == NULL)
      {
         cout << "A Patron with ID# " << patronID;
         cout << " is not a member of this library." << endl;
      }
      return;
   }
   else if (member == NULL)
   {
      cout << "A Patron with ID# " << patronID;
      cout << " is not a member of this library." << endl;
      if (holding == NULL)
      {
         cout << "Item with ID# " << ItemID;
         cout << " is not a holding in this library." << endl;
      }
      return;
   }

   if (holding->getRequestedBy() != NULL)
   {
      Patron* holder = holding->getRequestedBy();
      if ((holder->getIdNum()) == patronID)
      {
         cout << "Item with ID# " << ItemID;
         cout << " is already requested by " << member->getName();
         cout << "." << endl;
         return;
      }

      cout << "Item with ID# " << ItemID;
      cout << " is already requested by another Patron." << endl;
      return;
   }

   if (holding->getCheckedOutBy() == member)
   {
      cout << "Item with ID# " << ItemID;
      cout << " is already checked out by Patron ID# " << patronID;
      cout << "." << endl;
      return;
   }

   //Update LibraryItem's requestedBy.
   holding->setRequestedBy(member);

   //Update LibraryItem's location.
   if (holding->getLocation() == ON_SHELF)
   {
      holding->setLocation(ON_HOLD_SHELF);
   }

   //Print request confirmation.
   cout << holding->getTitle() << " is now on request for " << member->getName();
   cout << "." << endl;
}



/***************************************************
 *               incrementCurrentDate
 * -increment currentDate by one
 * -determine for each patron for each of the
 * checkedOutItems if item is overdue
 * -if overdue, add .10 to fine using amendFine
 * ************************************************/

void Library::incrementCurrentDate()
{
   currentDate++;

   for (int patron = 0; patron < (members.size()); patron++)
   {
      vector<LibraryItem*> payment = members[patron]->getCheckedOutItems();
      for (int items = 0; items < (payment.size()); items++)
      {        
         //Determine if overdue
         LibraryItem* checked = payment[items];
         
         int days_checked_out  = currentDate - (checked->getDateCheckedOut());
         int days_left = (checked->getCheckOutLength()) - days_checked_out;
         
         if (days_checked_out > (checked->getCheckOutLength()))
         {
            members[patron]->amendFine(.10);
         }
      }
   }
}



/***************************************************
 *               payFine
 * -input validation
 * -use amendFine for user to pay fine
 * ************************************************/

void Library::payFine(std::string patronID, double payment)
{ 
   Patron* member = findMember(patronID);
 
   if (member == NULL)
   {
      cout << "A Patron with ID# " << patronID;
      cout << " is not a member of this library." << endl;
      return;
   }
   
   //Update fine amount.
   member->amendFine(payment);

   //Print fine confimration.
   cout << "The fines for " << member->getName();
   cout << " are now $" << fixed << setprecision(2) << member->getFineAmount() <<  endl;
}



/***************************************************
 *               viewPatronInfo
 * -input validation
 * -display current info for a Patron of the library
 * ************************************************/

void Library::viewPatronInfo(std::string patronID)
{ 
   Patron* member = findMember(patronID);
 
   if (member == NULL)
   {
      cout << "A Patron with ID# " << patronID;
      cout << " is not a member of this library." << endl;
      return;
   }

   cout << "-----------------------------------------------" << endl;   
   cout << " Patron ID#:  " << member->getIdNum() << endl;
   cout << " Name:  " << member->getName() << endl;
   cout << "-----------------------------------------------" << endl;
   cout <<"             Checked Out Items:";

   vector<LibraryItem*> items = member->getCheckedOutItems();
   
   if (items.empty())
   {
      cout << " None." << endl;
   }
   else 
   {
      cout << endl << endl;
      int size = items.size();
      if (size == 1)
      {
         LibraryItem* checked = items[0];
         string title = checked->getTitle();
         string origin = checked->getOrigin();
         string id = checked->getIdCode();

         if ((checked->getItemType()) == 1)
         {
            cout << "   Album: ";
         }
         if ((checked->getItemType()) == 2)
         {
            cout << "   Book: ";
         }
         if ((checked->getItemType()) == 3)
         {
            cout << "   Movie: ";
         }
         cout <<  title << " by " << origin << ", ID# " << id << endl << endl;
      }
      else if (size > 1)
      { 
         LibraryItem* checked;
         string title, origin, id;
         for (int index = 0; index < size; index++)
         {
            checked = items[index];
            title = checked->getTitle();
            origin = checked->getOrigin();
            id = checked->getIdCode();
            
            if ((checked->getItemType()) == 1)
            {
               cout << "   Album: ";
            }
            if ((checked->getItemType()) == 2)
            {
               cout << "   Book: ";
            }
            if ((checked->getItemType()) == 3)
            {
               cout << "   Movie: ";
            }
            cout  << title << " by " << origin << ", ID# " << id << endl;
         }
         cout << endl;
      }
   }
 
   cout << "-----------------------------------------------" << endl;
   cout << " Current Library Fines:  $" << fixed << setprecision(2) << member->getFineAmount() << endl;
   cout << "-----------------------------------------------" << endl;
}



/***************************************************
 *               viewItemInfo
 * -input validation
 * -display current info for holding in the library
 * ************************************************/

void Library::viewItemInfo(std::string ItemID)
{
   LibraryItem* holding = findHolding(ItemID);

   if (holding == NULL)
   {
      cout << "Item with ID# " << ItemID;
      cout << " is not a holding in this library." << endl;
      return;
   }

   //Print item info.
   cout << "-----------------------------------------------" << endl;   
  
   //ID number:
   cout << " Item ID#:  " << ItemID << endl;

   //Origin (Author/Artist/Director):
   if ((holding->getItemType()) == BOOK)
   {
      cout << " Item Description:  Book" << endl;
      cout << " Author:  " << holding->getOrigin() << endl;
   }
   else if ((holding->getItemType()) == ALBUM)
   {
      cout << " Item Description:  Album" << endl;
      cout << " Artist:  " << holding->getOrigin() << endl;
   }
   else if ((holding->getItemType()) == MOVIE)
   {
      cout << " Item Description:  Movie" << endl;
      cout << " Director:  " << holding->getOrigin() << endl;
   }

   //Title:
   cout << " Title:  " << holding->getTitle() << endl;
   cout << "-----------------------------------------------" << endl << endl;
   
   //Location:
   cout << "         Current Location:  ";
   if ((holding->getLocation()) == 0)
   {
      cout << "On Shelf" << endl;
   }
   else if ((holding->getLocation()) == 1)
   {
      cout << "On Hold Shelf" << endl;
   }
   else if ((holding->getLocation()) == 2)
   {
      cout << "Checked Out" << endl;
   }

   //Requested by:
   if ((holding->getRequestedBy()) != NULL)
   {
      Patron* requester = holding->getRequestedBy();

      cout << "         Requested By:  " << requester->getName() << endl;
   }
   else
   {
      cout << "         Requested By:  None" << endl;
   }  

   //Checked out by:
   if ((holding->getCheckedOutBy()) != NULL)
   {
      Patron* checker = holding->getCheckedOutBy();
      
      cout << "         Checked Out By:  " << checker->getName() << endl;
   }
   else
   {
      cout << "         Checked Out By:  None" << endl;
   }
   
   //Due status: 
   if ((holding->getLocation()) == 2)
   {
      int days_checked_out  = currentDate - (holding->getDateCheckedOut());
      int days_left = (holding->getCheckOutLength()) - days_checked_out;
      if (days_checked_out > (holding->getCheckOutLength()))
      {
         cout << "         Status:  OVERDUE" << endl;
      }
      else if (days_checked_out < (holding->getCheckOutLength()))
      {
         cout << "         Status:  " << days_left << " DAYS LEFT TILL DUE" << endl;
      }
      else if (days_checked_out == (holding->getCheckOutLength()))
      {   
         cout << "         Status:  DUE TODAY" << endl;
      }
   }
   else
   {
      cout << "         Status:  Not Checked Out" << endl;
   } 

   cout << endl << "-----------------------------------------------" << endl;
}
