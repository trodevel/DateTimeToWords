/*

Example.

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

// $Revision: 2443 $ $Date:: 2015-08-28 #$ $Author: serge $

#include <iostream>     // std::cout
#include <vector>
#include <iomanip>

#include "Converter.h"           // Converter

void test_date( const DateTimeToWords::IDateToWords *c, const char *descr )
{
    struct date_e
    {
        unsigned y;
        unsigned m;
        unsigned d;
    };

    std::vector<date_e> dates =
    {
            { 2015, 8, 21 },
            { 1899, 8, 21 },
            { 1900, 8, 21 },
            { 1901, 8, 21 },
            { 1999, 8, 21 },
            { 2000, 8, 21 },
            { 2009, 8, 21 },
            { 2010, 8, 21 },
    };

    std::cout << "\n";
    std::cout << descr << std::endl;

    for( auto & e : dates )
    {
        std::cout << e.y << "-" << e.m << "-" << e.d << ": " << c->to_words( e.y, e.m, e.d ) << std::endl;
    }
}

void test_time( const DateTimeToWords::ITimeToWords * c, const char * descr )
{
    struct time_e
    {
        unsigned h;
        unsigned m;
        unsigned s;
    };

    std::vector<time_e> times =
    {
            { 0, 0, 0 },
            { 1, 1, 1 },
            { 2, 2, 2 },
            { 3, 15, 1 },
            { 4, 4, 4 },
            { 4, 33, 27 },
            { 5, 5, 5 },
            { 5, 30, 27 },
            { 6, 0, 58 },
            { 7, 15, 15 },
            { 8, 45, 0 },
            { 11, 6, 2 },
            { 12, 00, 00 },
            { 17, 22, 10 },
            { 21, 17, 10 },
    };

    std::cout << "\n";
    std::cout << descr << std::endl;

    for( auto & e : times )
    {
        std::cout <<
                std::setfill( '0' ) << std::setw( 2 ) << e.h << ":" <<
                std::setfill( '0' ) << std::setw( 2 ) << e.m << " - " << c->to_words( e.h, e.m ) << std::endl;
    }

    std::cout << "\n";
    std::cout << descr << " (with seconds)" << std::endl;

    for( auto & e : times )
    {
        std::cout <<
                std::setfill( '0' ) << std::setw( 2 ) << e.h << ":" <<
                std::setfill( '0' ) << std::setw( 2 ) << e.m << ":" <<
                std::setfill( '0' ) << std::setw( 2 ) << e.s << " - " << c->to_words( e.h, e.m, e.s ) << std::endl;
    }
}

void test_01( const DateTimeToWords::Converter * r )
{
    const DateTimeToWords::IDateToWords *c = r->get_date_converter( "en" );

    test_date( c, "English" );

    const DateTimeToWords::IDateToWords *c2 = r->get_date_converter( "de" );

    test_date( c2, "German" );
}

void test_02( const DateTimeToWords::Converter * r )
{
    const DateTimeToWords::ITimeToWords *c = r->get_time_converter( "en" );

    test_time( c, "Formal way" );

    const DateTimeToWords::ITimeToWords *c2 = r->get_time_converter( "en_GB" );

    test_time( c2, "Popular way" );

    const DateTimeToWords::ITimeToWords *c3 = r->get_time_converter( "de" );

    test_time( c3, "German" );

    const DateTimeToWords::ITimeToWords *c4 = r->get_time_converter( "ru" );

    test_time( c4, "Russian" );
}

int main()
{
    DateTimeToWords::Converter r;

    test_01( &r );

    test_02( &r );

    return 0;
}
