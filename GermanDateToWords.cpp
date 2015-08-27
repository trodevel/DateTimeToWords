/*

GermanDateToWords.

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

// $Revision: 2428 $ $Date:: 2015-08-27 #$ $Author: serge $

#include "GermanDateToWords.h"     // self

#include <sstream>                      // std::ostringstream


#include "../HumanizerCpp/Configuration/Configurator.h" // Configurator

using namespace DateTimeToWords;
using namespace Humanizer::Localisation::NumberToWords;
using namespace Humanizer::Configuration;

/*
http://german.stackexchange.com/questions/7244/how-to-tell-date-in-german

It can be nominative:

    Heute ist der vierzehnte Februar.

Or dative:

    Am vierzehnten Februar war ich in Urlaub (already mentioned by Benedikt Brünner)

Or accusative:

    [Captain's logbook]: 32° 12' W 14° 34' S, wir schreiben den vierzehnten Februar.

Or genitive:

    Am Morgen des vierzehnten Februars sammelten wir uns zur Abreise.

So you see, all four cases can and do occur.
And there are more prepositions besides am that can go with a date.
Note the terminal -s in Februars for the genitive*,
note the terminal -n in the adjective vierzehnten for dative, accusative and genitive.

Finally, another nominative form without an article is

    Vierzehnter Februar.

* However: Not marking the genitive case of the month with a terminal 's' is becoming increasingly popular;
at present, it is a matter of subjective choice.

 */
std::string GermanDateToWords::to_words( unsigned int month, unsigned int day ) const
{
    std::ostringstream res;

    res << day_to_words( day ) << " " << month_to_words( month );

    return res.str();
}

std::string GermanDateToWords::to_words( unsigned int year, unsigned int month, unsigned int day ) const
{
    std::ostringstream res;

    res << to_words( month, day ) << " " << year_to_words( year );

    return res.str();
}

// http://german.stackexchange.com/questions/23325/how-to-read-years-in-german
/*
In German generally (i.e. not just in Germany but also in Austria and in Switzerland), years are pronounced like this:

    1015 (ein)tausendfünfzehn
    1115 elfhundertfünfzehn
    1215 zwölfhundertfünfzehn
    1315 dreizehnhundertfünfzehn
    ...
    1815 achtzehnhundertfünfzehn
    1915 neunzehnhundertfünfzehn
    2015 zweitausendfünfzehn
    2115 zweitausendeinhundertfünfzehn

Or in words, the numbers are pronounced normally except that from 1100 to 1999, XYAB is pronounced as XY hundert AB.

PS: The English style of pronouncing years is also used occasionally as it is shorter, but it's only borderline correct.
*/
std::string GermanDateToWords::year_to_words( unsigned int year )
{
    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "de" );

    std::ostringstream res;

    if( year >= 1100 && year < 1999 )
    {
        auto year_high          = year / 100;
        auto year_low           = year % 100;

        res << e->Convert( year_high ) << " hundred";

        if( year_low > 0 )
        {
           res << " " << e->Convert( year_low );
        }
    }
    else
    {
        res << e->Convert( year );
    }

    return res.str();
}

const std::string & GermanDateToWords::month_to_words( unsigned int month )
{
    static const std::string months[] =
    {
        "Januar", "Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember",
    };

    if( month < 1 || month > 12 )
    {
        month = 1;
    }

    return months[ month - 1 ];
}

std::string GermanDateToWords::day_to_words( unsigned int day )
{
    if( day < 1 || day > 31 )
    {
        day = 1;
    }

    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "de" );

    return e->ConvertToOrdinal( day, Humanizer::GrammaticalGender::Feminine );
}
