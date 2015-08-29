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

#ifndef RUSSIAN_DATE_TO_WORDS_H
#define RUSSIAN_DATE_TO_WORDS_H

#include "IDateToWords.h"       // IDateToWords

namespace DateTimeToWords
{

class RussianDateToWords: public IDateToWords
{
public:

    virtual std::string to_words( unsigned int month, unsigned int day ) const;
    virtual std::string to_words( unsigned int year, unsigned int month, unsigned int day ) const;

protected:

    static std::string to_genetive( unsigned int n );
    static std::string year_to_words( unsigned int year );
    static const std::string & month_to_words( unsigned int month );
    static std::string day_to_words( unsigned int day );
};

} // namespace DateTimeToWords

#endif // RUSSIAN_DATE_TO_WORDS_H
