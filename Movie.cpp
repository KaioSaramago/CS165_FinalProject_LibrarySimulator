/*******************************************************************
 * Author: Larissa Hahn
 * Date: 3-11-15
 * File name: Movie.cpp
 * Description: Movie.cpp is the class function implementation file
 * for the Movie class.
 * ****************************************************************/
#include "LibraryItem.hpp"
#include "Movie.hpp"



/*************************************************
 *       Movie class Get Method Helper
 * **********************************************/

std::string Movie::getOrigin()
{
   return getDirector();
}



/************************************************
 *      Movie class Set method for Director
 * *********************************************/

void Movie::setDirector(std::string direct)
{
   director = direct;
}



/************************************************
 *      Movie class Get method for Director
 * *********************************************/

std::string Movie::getDirector()
{
   return director;
}



/************************************************
 *      Movie class Get method for Check Out
 * *********************************************/

int Movie::getCheckOutLength()
{
   return CHECK_OUT_LENGTH;
}


