/*

EnglishDateToWords.

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

// $Revision: 2391 $ $Date:: 2015-08-24 #$ $Author: serge $

#include "EnglishDateToWords.h"     // self

#include <sstream>                      // std::ostringstream


#include "../HumanizerCpp/Configuration/Configurator.h" // Configurator

using namespace DateTimeToWords;
using namespace Humanizer::Localisation::NumberToWords;
using namespace Humanizer::Configuration;

std::string EnglishDateToWords::to_words( unsigned int month, unsigned int day )
{
    std::ostringstream res;

    res << day_to_words( day ) << " of " << month_to_words( month );

    return res.str();
}

std::string EnglishDateToWords::to_words( unsigned int year, unsigned int month, unsigned int day )
{
    std::ostringstream res;

    res << day_to_words( day ) << " of " << month_to_words( month ) << " " << year_to_words( year );

    return res.str();
}

// http://english.stackexchange.com/questions/5442/what-are-the-rules-for-pronunciation-of-years-in-english
/*

For one thing, "Two Thousand" is shorter to say than "twenty hundred".

1899: eighteen ninety-nine (shorter than one thousand eight hundred ninety-nine)
1900: nineteen hundred (shorter than one thousand nine hundred)
1901: nineteen oh one (shorter than nineteen hundred one, shorter than one thousand nine hundred one)
1999: nineteen ninety nine (shorter than one thousand nine hundred ninety-nine)
2000: two thousand (or 2 "K"?) (shorter than twenty hundred)
2009: two thousand nine (shorter than twenty hundred nine)
2010: twenty ten (shorter than two thousand ten)

 Basically when the number has three zeros it is shorter to say "thousand" than "hundred".
 Once there are fewer than three zeros it's shorter to say "Y thousand X" for Y00X and "Y hundred X" for YYXX.

 This usage isn't limited to years either. Any numbers in the same range will have the same kinds of contractions.
 There's a Simpsons episode where this is played for laughs, when they need eighty-five-hundred dollars to fix their roof,
 and they only have $500, and Homer whines that they still need eighty-hundred.

*/
std::string EnglishDateToWords::year_to_words( unsigned int year )
{
    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "en" );

    auto year_high          = year / 100;
    auto year_low           = year % 100;
    auto rest_of_thousands  = year % 1000;

    std::ostringstream res;

    if( rest_of_thousands == 0 )
    {
        res << e->Convert( year );
    }
    else if( year_low == 0 )
    {
        res << e->Convert( year_high ) << " hundred";
    }
    else if( year_low < 10 )
    {
        res << e->Convert( year_high * 100 ) << " " << e->Convert( year_low );
    }
    else
    {
        res << e->Convert( year_high ) << " " << e->Convert( year_low );
    }

    return res.str();
}

/*
https://www.ego4u.com/en/cram-up/vocabulary/date/written

2. Writing and saying the date in British English

rule: day – month – year
        Day         Month   Year
You write:      1st         January,    2010
You say:    the     first   of  January     twenty ten

Note: The two letters at the end of the number and the comma are often left out.
3. Writing and saying the date in American English

rule: month – day – year
    Month       Day     Year
You write:  January         1st,    2010
You say:    January     (the)*  first   twenty ten

* The definite article ›the‹ can be left out.
4. Sample sentences and the correct prepositions:

    I was born in 1999. (Use in with the year.)
    I was born in August. (Use in with the month.)
    I was born on 12th May, 2000. (Use on in the complete date.)
 *
 */
const std::string & EnglishDateToWords::month_to_words( unsigned int month )
{
    static const std::string months[] =
    {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };

    if( month < 1 || month > 12 )
    {
        month = 1;
    }

    return months[ month - 1 ];
}

std::string EnglishDateToWords::day_to_words( unsigned int day )
{
    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( "en" );

    return e->ConvertToOrdinal( day );
}
