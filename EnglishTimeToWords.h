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

#ifndef ENGLISH_TIME_TO_WORDS_H
#define ENGLISH_TIME_TO_WORDS_H

#include "ITimeToWords.h"       // ITimeToWords

namespace DateTimeToWords
{

class EnglishTimeToWords: public ITimeToWords
{
public:

    virtual std::string to_words( unsigned int hour, unsigned int minute );
    virtual std::string to_words( unsigned int hour, unsigned int minute, unsigned int second );

protected:

    static std::string hour_to_words( unsigned int hour );
    static std::string minute_to_words( unsigned int minute );
    static const std::string & hour_to_noon( unsigned int hour );

};

} // namespace DateTimeToWords

#endif // ENGLISH_TIME_TO_WORDS_H
