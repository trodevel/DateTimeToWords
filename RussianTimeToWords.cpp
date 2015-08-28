/*

RussianTimeToWords.

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

// $Revision: 2441 $ $Date:: 2015-08-28 #$ $Author: serge $

#include "RussianTimeToWords.h"     // self

#include <sstream>                  // std::ostringstream
#include <vector>                   // std::vector

#include "RussianPlurality.h"       // RussianPlurality

#include "../HumanizerCpp/Configuration/Configurator.h" // Configurator

using namespace DateTimeToWords;
using namespace Humanizer::Localisation::NumberToWords;
using namespace Humanizer::Configuration;

std::string RussianTimeToWords::to_words( unsigned int hour, unsigned int minute ) const
{
    if( hour < 0 || hour > 23 )
    {
        hour = 0;
    }

    if( minute < 0 || minute > 59 )
    {
        minute = 0;
    }

    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "ru" );

    std::ostringstream res;

    res << e->Convert( hour ) << " " << hour_form( hour );

    res << " " << e->Convert( minute, Humanizer::GrammaticalGender::Feminine ) << " " << minute_form( minute );

    return res.str();
}

std::string RussianTimeToWords::to_words( unsigned int hour, unsigned int minute, unsigned int second ) const
{
    if( second < 0 || second > 59 )
    {
        second = 0;
    }

    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "ru" );

    std::ostringstream res;

    res << to_words( hour, minute ) << " " <<  e->Convert( second, Humanizer::GrammaticalGender::Feminine ) << " " << second_form( second );

    return res.str();
}

const std::string & select_by_plurality( Plurality p, const std::vector<std::string> & src )
{
    switch( p )
    {
    case Plurality::Singular:
        return src[0];
    case Plurality::Plural:
        return src[1];
    default:
        break;
    }

    return src[2];
}

const std::string & select_by_number( unsigned int v, const std::vector<std::string> & src )
{
    auto plurality = RussianPlurality::get_plurality( v );

    return select_by_plurality( plurality, src );

    return src[2];
}

const std::string & RussianTimeToWords::hour_form( unsigned int v )
{
    static const std::vector<std::string> src =
    {
            "час", "часа", "часов"
    };

    return select_by_number( v, src );
}

const std::string & RussianTimeToWords::minute_form( unsigned int v )
{
    static const std::vector<std::string> src =
    {
            "минута", "минуты", "минут"
    };

    return select_by_number( v, src );
}

const std::string & RussianTimeToWords::second_form( unsigned int v )
{
    static const std::vector<std::string> src =
    {
            "секунда", "секунды", "секунд"
    };

    return select_by_number( v, src );
}

