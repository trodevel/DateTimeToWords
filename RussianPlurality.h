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

// $Revision: 2434 $ $Date:: 2015-08-28 #$ $Author: serge $

#ifndef RUSSIAN_PLURALITY_H
#define RUSSIAN_PLURALITY_H

#include "Plurality.h"          // Plurality

namespace DateTimeToWords
{

class RussianPlurality
{
public:

    static Plurality get_plurality( unsigned int v );
};

} // namespace DateTimeToWords

#endif // RUSSIAN_PLURALITY_H
