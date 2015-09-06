/*************************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name: LibraryItem.cpp
 * Description: LibraryItem.cpp is the class function implementation file
 * for the LibraryItem class. 
 * **********************************************************************/
#include "LibraryItem.hpp"



/*************************************************
 *     LibraryItem Class Default Constructor
 * **********************************************/

LibraryItem::LibraryItem()
{
   setIdCode("");
   setTitle("");
   setCheckedOutBy(NULL);
   setRequestedBy(NULL);
   setLocation(ON_SHELF);
}



/*************************************************
 *         LibraryItem Class Constructor
 * **********************************************/

LibraryItem::LibraryItem(std::string idc, std::string t)
{
   setIdCode(idc);
   setTitle(t);
   setCheckedOutBy(NULL);
   setRequestedBy(NULL);
   setLocation(ON_SHELF);
}



/*************************************************
 *    LibraryItem Class Get Method for idCode
 * **********************************************/

std::string LibraryItem::getIdCode()
{
   return idCode;
}



/*************************************************
 *    LibraryItem Class Set Method for idCode
 * **********************************************/

void LibraryItem::setIdCode(std::string id)
{
   idCode = id;
}



/*************************************************
 *    LibraryItem Class Get Method for title
 * **********************************************/

std::string LibraryItem::getTitle()
{
   return title;
}



/*************************************************
 *    LibraryItem Class Set Method for title
 * **********************************************/

void LibraryItem::setTitle(std::string t)
{
   title = t;
}



/*************************************************
 *   LibraryItem Class Get Method for location
 * **********************************************/

Locale LibraryItem::getLocation()
{
   return location;
}



/*************************************************
 *   LibrayItem Class Set Method for location
 * **********************************************/

void LibraryItem::setLocation(Locale lo)
{
   location = lo;
}



/*************************************************
 * LibraryItem Class Get Method for checkedOutBy
 * **********************************************/

Patron* LibraryItem::getCheckedOutBy()
{
   return checkedOutBy;
}



/*************************************************
 * LibraryItem Class Set Method for checkedOutBy
 * **********************************************/

void LibraryItem::setCheckedOutBy(Patron *p)
{
   checkedOutBy = p;
}



/*************************************************
 * LibraryItem Class Get Method for requestedBy
 * **********************************************/

Patron* LibraryItem::getRequestedBy()
{
   return requestedBy;
}



/*************************************************
 * LibraryItem Class Set Method for requestedBy
 * **********************************************/

void LibraryItem::setRequestedBy(Patron* p)
{
   requestedBy = p;
}



/*************************************************
 * LibraryItem Class Get Method for dateCheckedOut
 * **********************************************/

int LibraryItem::getDateCheckedOut()
{
   return dateCheckedOut;
}



/*************************************************
 * LibraryItem Class Set Method for dateCheckedOut
 * **********************************************/

void LibraryItem::setDateCheckedOut(int d)
{
   dateCheckedOut = d;
}



/*************************************************
 * LibraryItem Class Get Method for itemType
 * **********************************************/

Item LibraryItem::getItemType()
{
   return itemType;
}



/*************************************************
 * LibraryItem Class Set Method for itemType
 * **********************************************/

void LibraryItem::setItemType(Item type)
{
   itemType = type;
}



