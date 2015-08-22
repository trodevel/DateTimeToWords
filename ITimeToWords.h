/*

interface ITimeToWords.

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

// $Revision: 2385 $ $Date:: 2015-08-22 #$ $Author: serge $

#ifndef I_TIME_TO_WORDS_H
#define I_TIME_TO_WORDS_H

#include <string>               // std::string

namespace DateTimeToWords
{

class ITimeToWords
{
public:
    virtual ~ITimeToWords() {}
    virtual std::string to_words( unsigned int hour, unsigned int minute ) = 0;
    virtual std::string to_words( unsigned int hour, unsigned int minute, unsigned int second ) = 0;
};

} // namespace DateTimeToWords

#endif // I_TIME_TO_WORDS_H
