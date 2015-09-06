/*****************************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name: Library.hpp
 * Description: Library.hpp is the class specification file for the Library
 * class as part of The Library project.
 * **************************************************************************/
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>

class Patron;
class LibraryItem;

class Library
{
   private:
      std::vector<LibraryItem*> holdings;
      std::vector<Patron*> members;
      int currentDate;
   public:
      //Added two helper functions, findHolding and findMember.
      Library();
      ~Library(); //Added destructor
      LibraryItem* findHolding(std::string ItemID);
      Patron* findMember(std::string patronID);
      void addLibraryItem(LibraryItem* item);
      void addMember(Patron* member);
      void checkOutLibraryItem(std::string patronID, std::string ItemID);
      void returnLibraryItem(std::string ItemID);
      void requestLibraryItem(std::string patronID, std::string ItemID);
      void incrementCurrentDate();
      void payFine(std::string patronID, double payment);
      void viewPatronInfo(std::string patronID);
      void viewItemInfo(std::string ItemID);
};
#endif
