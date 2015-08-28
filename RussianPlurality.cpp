/*

RussianPlurality.

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

// $Revision: 2442 $ $Date:: 2015-08-28 #$ $Author: serge $

#include "RussianPlurality.h"     // self


using namespace DateTimeToWords;

Plurality RussianPlurality::get_plurality( unsigned int v )
{
    auto v_low = v % 10;

    if( v_low == 0 )
        return Plurality::IrregularPlural;

    if( v >= 11 && v <= 19 )
        return Plurality::IrregularPlural;

    if( v_low == 1 )
        return Plurality::Singular;

    if( v_low >= 2 && v_low <= 4 )
    {
        return Plurality::Plural;
    }

    return Plurality::IrregularPlural;
}

