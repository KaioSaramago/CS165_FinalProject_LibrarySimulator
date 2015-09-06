/******************************************************************
 * Author: Larissa Hahn
 * Date 3-11-15
 * File name: Album.cpp
 * Description: Album.cpp is the class function implementation file
 * for the Album class.
 * ***************************************************************/
#include "LibraryItem.hpp"
#include "Album.hpp"



/*************************************************
 *       Album class Get Method Helper
 * **********************************************/

std::string Album::getOrigin()
{
   return getArtist();
}



/*************************************************
 *       Album class Set Method for Artist
 * **********************************************/

void Album::setArtist(std::string art)
{
   artist = art;
}



/*************************************************
 *       Album class Get Method for Artist
 * **********************************************/

std::string Album::getArtist()
{
   return artist;
}



/*************************************************
 *      Album class Get method for Check Out
 * **********************************************/

int Album::getCheckOutLength()
{
   return CHECK_OUT_LENGTH;
}


