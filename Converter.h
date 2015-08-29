/*

Localizers Registry.

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

// $Revision: 2460 $ $Date:: 2015-08-29 #$ $Author: serge $

#ifndef DateTimeToWords_Converter_h
#define DateTimeToWords_Converter_h

#include "IDateToWords.h"           // IDateToWords
#include "ITimeToWords.h"           // ITimeToWords
#include "LocaliserRegistry.h"      // LocaliserRegistry

namespace DateTimeToWords
{

class Converter
{
public:

    static const ITimeToWords* get_time_converter( const std::string & locale_code );
    static const IDateToWords* get_date_converter( const std::string & locale_code );

    static const Converter* get();

private:
    Converter();

private:

    LocaliserRegistry<IDateToWords> date_to_words_;
    LocaliserRegistry<ITimeToWords> time_to_words_;
};
}

#endif // DateTimeToWords_Converter_h
