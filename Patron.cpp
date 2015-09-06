/****************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name: Patron.cpp
 * Description: Patron.cpp is the class function implemenation
 * file for the Patron class.
 * *************************************************************/
#include "LibraryItem.hpp"
#include "Patron.hpp"



/***************************************************
 *       Patron Class Default Constructor
 * ************************************************/

Patron::Patron()
{
   setIdNum("");
   setName("");   
}



/***************************************************
 *            Patron Class Constructor
 * ************************************************/

Patron::Patron(std::string idn, std::string n)
{
   setIdNum(idn);
   setName(n);
}



/***************************************************
 *       Patron Class Get Method for idNum
 * ************************************************/

std::string Patron::getIdNum()
{
   return idNum;
}



/***************************************************
 *        Patron Class Get Method for name
 * ************************************************/

std::string Patron::getName()
{
   return name;
}



/***************************************************
 *       Patron Class Set Method for idNum
 * ************************************************/

void Patron::setIdNum(std::string id)
{
   idNum = id;
}



/***************************************************
 *       Patron Class Set Method for name
 * ************************************************/

void Patron::setName(std::string n)
{
   name = n;
}



/***************************************************
 *   Patron Class Get Method for checkedOutItems
 * ************************************************/

std::vector<LibraryItem*> Patron::getCheckedOutItems()
{
   return checkedOutItems;
}



/***************************************************
 *          addLibraryItem
 * -add LibraryItem* b to checkedOutItems vector
 * ************************************************/

void Patron::addLibraryItem(LibraryItem* b)
{
   checkedOutItems.push_back(b);   
}



/***************************************************
 *          removeLibraryItem
 * -for checked out items, if the item matches
 *  the id code of the item being returned, that
 *  item is deleted
 * ************************************************/

void Patron::removeLibraryItem(LibraryItem* b)
{
   std::string id;
   id = b->getIdCode();
   
   int size = checkedOutItems.size();
   for (int index = 0; index < size; index++)
   {
      if ((checkedOutItems[index]->getIdCode()) == id)
      {
         checkedOutItems.erase(checkedOutItems.begin() + index);
         size = index;
      }
   }
}



/***************************************************
 *     Patron Class Get Method for fineAmount
 * ************************************************/

double Patron::getFineAmount()
{
   return fineAmount;
}



/***************************************************
 *          amendFine
 * -add amount to fineAmount
 * ************************************************/

void Patron::amendFine(double amount)
{
   fineAmount += amount;
   //If amount is positive, it increases the fine.
   //If amount is negative, it decreases the fine.
}
