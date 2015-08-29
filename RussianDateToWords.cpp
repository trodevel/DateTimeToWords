/*

RussianDateToWords.

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

// $Revision: 2457 $ $Date:: 2015-08-29 #$ $Author: serge $

#include "RussianDateToWords.h"     // self

#include <sstream>                      // std::ostringstream


#include "../HumanizerCpp/Configuration/Configurator.h" // Configurator

using namespace DateTimeToWords;
using namespace Humanizer::Localisation::NumberToWords;
using namespace Humanizer::Configuration;

std::string RussianDateToWords::to_words( unsigned int month, unsigned int day ) const
{
    std::ostringstream res;

    res << day_to_words( day ) << " " << month_to_words( month );

    return res.str();
}

std::string RussianDateToWords::to_words( unsigned int year, unsigned int month, unsigned int day ) const
{
    std::ostringstream res;

    res << to_words( month, day ) << " " << year_to_words( year );

    return res.str();
}

std::string RussianDateToWords::to_genetive( unsigned int n )
{
    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "ru" );

    std::string ordinal = e->ConvertToOrdinal( n, Humanizer::GrammaticalGender::Masculine );

    // need to remove last 2 characters, that corresponds to 4 bytes

    return ordinal.substr( 0, ordinal.size() - 4 ) + "ого";
}

std::string RussianDateToWords::year_to_words( unsigned int year )
{
    std::ostringstream res;

    // need to remove last 2 characters, that corresponds to 4 bytes
    res << to_genetive( year ) << " года";

    return res.str();
}

const std::string & RussianDateToWords::month_to_words( unsigned int month )
{
    static const std::string months[] =
    {
        "января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября", "ноября", "декабря",
    };

    if( month < 1 || month > 12 )
    {
        month = 1;
    }

    return months[ month - 1 ];
}

std::string RussianDateToWords::day_to_words( unsigned int day )
{
    if( day < 1 || day > 31 )
    {
        day = 1;
    }

    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "ru" );

    return e->ConvertToOrdinal( day, Humanizer::GrammaticalGender::Neuter );
}
