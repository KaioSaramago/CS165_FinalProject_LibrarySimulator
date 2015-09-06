/*****************************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name: Patron.hpp
 * Description: Patron.hpp is the class specification file for the Patron
 * class as part of The Library project.
 * **************************************************************************/
#ifndef PATRON_HPP
#define PATRON_HPP

#include <string>
#include <vector>

class LibraryItem;

class Patron
{
   private:
      std::string idNum;
      std::string name;
      std::vector<LibraryItem*> checkedOutItems;
      double fineAmount;
   public:
      Patron();
      Patron(std::string idn, std::string n);
      std::string getIdNum();
      std::string getName();
      void setIdNum(std::string); // Added Set Method
      void setName(std::string); // Added Set Method
      std::vector<LibraryItem*> getCheckedOutItems();
      void addLibraryItem(LibraryItem* b);
      void removeLibraryItem(LibraryItem* b);
      double getFineAmount();
      void amendFine(double amount);
};
#endif
