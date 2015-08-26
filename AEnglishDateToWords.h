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

// $Revision: 2396 $ $Date:: 2015-08-25 #$ $Author: serge $

#ifndef AENGLISH_DATE_TO_WORDS_H
#define AENGLISH_DATE_TO_WORDS_H

#include "EnglishDateToWords.h"     // EnglishDateToWords

namespace DateTimeToWords
{

class AEnglishDateToWords: public EnglishDateToWords
{
public:
    virtual std::string to_words( unsigned int month, unsigned int day );
    virtual std::string to_words( unsigned int year, unsigned int month, unsigned int day );
};

} // namespace DateTimeToWords

#endif // AENGLISH_DATE_TO_WORDS_H
