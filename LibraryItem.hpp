/*************************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name: LibraryItem.hpp
 * Description: LibraryItem.hpp is the class specification file for the
 * LibraryItem class as part of The Library project.
 * **********************************************************************/
#ifndef LIBRARY_ITEM_HPP
#define LIBRARY_ITEM_HPP

#include <string>
class Patron;

// These three locations are mutually exclusive, but note that
// a LibraryItem can be on request for a Patron while being checked
// out to another Patron.  In that case the LibraryItem's location is
// CHECKED_OUT, and when it is returned, it's location will
// become ON_HOLD_SHELF.
enum Locale {ON_SHELF, ON_HOLD_SHELF, CHECKED_OUT};

//Added Item Type:
enum Item {ALBUM = 1, BOOK, MOVIE};

class LibraryItem
{
   private:
      std::string idCode;
      std::string title;
      Locale location;
      Patron* checkedOutBy;
      Patron* requestedBy;
      int dateCheckedOut;
      Item itemType; // Added type description
   public:
      LibraryItem();
      LibraryItem(std::string idc, std::string t);
      virtual int getCheckOutLength() = 0;
      virtual std::string getOrigin() = 0; // Added get method
      std::string getIdCode();
      void setIdCode(std::string id); // Added set method
      std::string getTitle();
      void setTitle(std::string t); // Added set method
      Locale getLocation();
      void setLocation(Locale lo);
      Patron* getCheckedOutBy();
      void setCheckedOutBy(Patron* p);
      Patron* getRequestedBy();
      void setRequestedBy(Patron* p);
      int getDateCheckedOut();
      void setDateCheckedOut(int d);
      Item getItemType(); // Added get
      void setItemType(Item type); // Added set
};
#endif
