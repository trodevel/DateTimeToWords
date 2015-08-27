/*

AEnglishDateToWords.

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

// $Revision: 2412 $ $Date:: 2015-08-27 #$ $Author: serge $

#include "AEnglishDateToWords.h"        // self

#include <sstream>                      // std::ostringstream

using namespace DateTimeToWords;

/*
https://www.ego4u.com/en/cram-up/vocabulary/date/written

3. Writing and saying the date in American English

rule: month – day – year
    Month       Day     Year
You write:  January         1st,    2010
You say:    January     (the)*  first   twenty ten

* The definite article ›the‹ can be left out.

*/
std::string AEnglishDateToWords::to_words( unsigned int month, unsigned int day ) const
{
    std::ostringstream res;

    res << month_to_words( month ) << " "  << day_to_words( day );

    return res.str();
}

std::string AEnglishDateToWords::to_words( unsigned int year, unsigned int month, unsigned int day ) const
{
    std::ostringstream res;

    res << to_words( month, day ) << " " << year_to_words( year );

    return res.str();
}
