/*

GermanTimeToWords.

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

// $Revision: 2423 $ $Date:: 2015-08-27 #$ $Author: serge $

#include "GermanTimeToWords.h"      // self

#include <sstream>                  // std::ostringstream

#include "../HumanizerCpp/Configuration/Configurator.h" // Configurator

using namespace DateTimeToWords;
using namespace Humanizer::Localisation::NumberToWords;
using namespace Humanizer::Configuration;

/*
http://german.stackexchange.com/questions/544/wie-dr%C3%BCckt-man-auf-deutsch-die-uhrzeit-aus



Die offizielle Verwendung unterscheidet sich in Deutsch von der gesprochenen.

Offiziell:

10.00: zehn Uhr
10.05: zehn Uhr fünf
10.10: zehn Uhr zehn
10.15: zehn Uhr fünfzehn
10.20: zehn Uhr zwanzig
10.25: zehn Uhr fünfundzwanzig
10.30: zehn Uhr dreißig
10.35: zehn Uhr fünfunddreißig
10.40: zehn Uhr vierzig
10.45: zehn Uhr fünfundvierzig
10.50: zehn Uhr fünfzig
10.55: zehn Uhr fünfundfünfzig
11.00: elf Uhr

14.00: vierzehn Uhr
14.05: vierzehn Uhr fünf
14.10: vierzehn Uhr zehn
14.15: vierzehn Uhr fünfzehn
14.20: vierzehn Uhr zwanzig
14.25: vierzehn Uhr fünfundzwanzig
14.30: vierzehn Uhr dreißig
14.35: vierzehn Uhr fünfunddreißig
14.40: vierzehn Uhr vierzig
14.45: vierzehn Uhr fünfundvierzig
14.50: vierzehn Uhr fünfzig
14.55: vierzehn Uhr fünfundfünfzig
15.00: fünfzehn Uhr

Umgangssprache:

9.00/21.00: neun
9.05/21.05: fünf nach neun
9.10/21.10: zehn nach neun
9.15/21.15: viertel nach neun
9.20/21.20: zwanzig nach neun / zehn vor halb zehn
9.25/21.25: fünf vor halb zehn
9.30/21.30: halb zehn
9.35/21.35: fünf nach halb zehn
9.40/21.40: zwanzig vor zehn / zehn nach halb zehn
9.45/21.45: viertel vor zehn
9.50/21.50: zehn vor zehn
9.55/21.55: fünf vor zehn
10.00/22.00: zehn

Während die Mitte zwischen zwei vollen Stunden einheitlich mit halb und der Angabe der folgenden Stunde
bezeichnet wird (z.B. halb drei für 2 Uhr 30 Minuten), gibt es verschiedene regionale Unterschiede für die Viertelstunden.

...
 */
std::string GermanTimeToWords::to_words( unsigned int hour, unsigned int minute ) const
{
    if( hour < 0 || hour > 23 )
    {
        hour = 0;
    }

    if( minute < 0 || minute > 59 )
    {
        minute = 0;
    }

    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "de" );

    std::ostringstream res;

    res << e->Convert( hour ) << " Uhr";

    if( minute > 0 )
    {
        res << " " << e->Convert( minute );
    }

    return res.str();
}

std::string GermanTimeToWords::to_words( unsigned int hour, unsigned int minute, unsigned int second ) const
{
    if( second < 0 || second > 59 )
    {
        second = 0;
    }

    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "de" );

    std::ostringstream res;

    res << to_words( hour, minute ) << " und ";

    if( second == 1 )
    {
        res << "eine";
    }
    else
    {
        res << e->Convert( second );
    }

    res << " Sekunde" << plural_ending( second != 1 );

    return res.str();
}

const std::string & GermanTimeToWords::plural_ending( bool b )
{
    static const std::string empty;
    static const std::string s( "n" );

    return b ? s : empty;
}
