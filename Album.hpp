/***********************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name: Album.hpp
 * Description: Album.hpp is the class specification file for the Album
 * class as part of The Library project.
 * ********************************************************************/
#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>

class Album : public LibraryItem {
   private: 
      std::string artist;
   public:
      Album(std::string idc, std::string t, std::string art) : LibraryItem(idc, t)
      {
         setArtist(art);
         setItemType(ALBUM);
      }

      static const int CHECK_OUT_LENGTH = 14;
      std::string getOrigin(); // Override helper function
      void setArtist(std::string art);
      std::string getArtist();
      int getCheckOutLength(); // Override pure virtual function in parent class
};
#endif

