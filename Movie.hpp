/***********************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name: Movie.hpp
 * Description: Movie.hpp is the class specification file for the Movie
 * class as part of The Library project.
 * ********************************************************************/

#include <string>

#ifndef MOVIE_HPP
#define MOVIE_HPP
class Movie : public LibraryItem {
   private: 
      std::string director;
   public:
      Movie(std::string idc, std::string t, std::string direct) : LibraryItem(idc, t)
      {
         setDirector(direct);
         setItemType(MOVIE);
      }

      static const int CHECK_OUT_LENGTH = 7;
      std::string getOrigin(); // Override helper function
      void setDirector(std::string direct);
      std::string getDirector();
      int getCheckOutLength(); // Override function
};
#endif
