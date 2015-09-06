/*******************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name: Book.cpp
 * Description: Book.cpp is the class function implementation file
 * for the Book class.
 * ****************************************************************/
#include "LibraryItem.hpp"
#include "Book.hpp"



/*************************************************
 *       Book class Get Method Helper
 * **********************************************/

std::string Book::getOrigin()
{
   return getAuthor();
}



/*************************************************
 *       Book class Set Method for Author
 * **********************************************/

void Book::setAuthor(std::string auth)
{
   author = auth;
}



/*************************************************
 *       Book class Get Method for Author
 * **********************************************/

std::string Book::getAuthor() 
{
   return author;
}



/*************************************************
 *       Book class Get method for Check Out
 * **********************************************/

int Book::getCheckOutLength()
{
   return CHECK_OUT_LENGTH;
}

