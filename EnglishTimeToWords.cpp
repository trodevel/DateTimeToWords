/*

EnglishTimeToWords.

Copyright (C) 2015 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 2403 $ $Date:: 2015-08-25 #$ $Author: serge $

#include "EnglishTimeToWords.h"     // self

#include <sstream>                  // std::ostringstream
#include <stdexcept>                // std::invalid_argument


#include "../HumanizerCpp/Configuration/Configurator.h" // Configurator

using namespace DateTimeToWords;
using namespace Humanizer::Localisation::NumberToWords;
using namespace Humanizer::Configuration;

/*
https://www.ego4u.com/en/cram-up/vocabulary/time

More popular way

Say the minutes first and then the hours. Use past and the preceding hour for minutes 01 through 30.
Use to and the forthcoming hour for minutes 31 through 59, but .

Example: 7.15 - fifteen minutes past seven

Example: 7.45 - fifteen minutes to eight

Another possibility of saying '15 minutes past' is: a quarter past

Another possibility of saying '15 minutes to' is: a quarter to

Another possibility of saying '30 minutes past' is: half past

Example: 5:30 - half past five

 */
std::string EnglishTimeToWords::to_words( unsigned int hour, unsigned int minute )
{
    if( hour < 0 || hour > 23 )
    {
        hour = 0;
    }

    if( minute < 0 || minute > 59 )
    {
        minute = 0;
    }

    std::ostringstream res;

    if( minute == 0 )
    {
        res << hour_to_words( hour ) << " o'clock";
    }
    else if( minute <= 30 )
    {
        res << minute_to_words( minute ) << " " << hour_to_words( hour );
    }
    else /*if( minute > 30 )*/
    {
        res << minute_to_words( minute ) << " " << hour_to_words( hour + 1 );
    }

    res << " " << hour_to_noon( hour ) ;

    return res.str();
}

std::string EnglishTimeToWords::to_words( unsigned int hour, unsigned int minute, unsigned int second )
{
    if( hour < 0 || hour > 23 )
    {
        hour = 0;
    }

    if( minute < 0 || minute > 59 )
    {
        minute = 0;
    }

    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "en" );

    std::ostringstream res;

    if( minute == 0 )
    {
        res << e->Convert( hour % 12 ) << " o'clock";
    }
    else
    {
        res << e->Convert( hour % 12 ) << " " << (( minute < 10 ) ? std::string( "oh " ):std::string( "" )) << e->Convert( minute );
    }

    res << " " << hour_to_noon( hour ) ;

    return res.str();
}

std::string EnglishTimeToWords::hour_to_words( unsigned int hour )
{
    hour %= 24; // to simplify rotating

    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "en" );

    std::ostringstream res;

    if( hour == 0 )
    {
        res << "midnight";
    }
    else if( hour == 12 )
    {
        res << "noon";
    }
    else
    {
        res << e->Convert( hour % 12 );
    }

    return res.str();
}

std::string EnglishTimeToWords::minute_to_words( unsigned int minute )
{
    if( minute < 0 || minute > 59 )
    {
        throw std::invalid_argument( "wrong minutes" );
    }

    if( minute == 0 )
    {
        throw std::invalid_argument( "wrong minutes" );
    }

    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "en" );

    std::ostringstream res;

    if( minute == 15 )
    {
        res << "a quarter past";
    }
    else if( minute == 30 )
    {
        res << "half past";
    }
    else if( minute == 45 )
    {
        res << "a quarter to";
    }
    else if( minute <= 30 )
    {
        res << e->Convert( minute ) << " minute" << (( minute == 1 ) ? std::string( "" ):std::string( "s" )) << " past";
    }
    else /*if( minute > 30 )*/
    {
        unsigned int rest_min = 60 - minute;

        res << e->Convert( rest_min ) << " minute" << (( rest_min == 1 ) ? std::string( "" ):std::string( "s" )) << " to";
    }

    return res.str();
}

const std::string & EnglishTimeToWords::hour_to_noon( unsigned int hour )
{
    static const std::string m( "in the morning" );
    static const std::string a( "in the afternoon" );

    return ( hour < 12 ) ? m : a;
}
