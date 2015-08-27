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

// $Revision: 2418 $ $Date:: 2015-08-27 #$ $Author: serge $

#ifndef GERMAN_TIME_TO_WORDS_H
#define GERMAN_TIME_TO_WORDS_H

#include "ITimeToWords.h"       // ITimeToWords

namespace DateTimeToWords
{

class GermanTimeToWords: public ITimeToWords
{
public:

    virtual std::string to_words( unsigned int hour, unsigned int minute ) const;
    virtual std::string to_words( unsigned int hour, unsigned int minute, unsigned int second ) const;

protected:

    static const std::string & plural_ending( bool b );
};

} // namespace DateTimeToWords

#endif // GERMAN_TIME_TO_WORDS_H
