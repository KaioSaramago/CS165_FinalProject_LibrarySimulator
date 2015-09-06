/*********************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name: Book.hpp
 * Description: Book.hpp is the class specification file for the Book
 * class as part of The Library project.
 * ******************************************************************/
#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book : public LibraryItem {
   private: 
      std::string author;
   public:
      Book(std::string idc, std::string t, std::string auth) : LibraryItem(idc, t)
      {
         setAuthor(auth);
         setItemType(BOOK);
      }

      static const int CHECK_OUT_LENGTH = 21;
      std::string getOrigin(); // Helper function override
      void setAuthor(std::string auth);
      std::string getAuthor();
      int getCheckOutLength(); // override function
};
#endif
