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

// $Revision: 2430 $ $Date:: 2015-08-27 #$ $Author: serge $

#include "Converter.h"                   // self

#include "AEnglishDateToWords.h"        // AEnglishDateToWords
#include "EnglishDateToWords.h"         // EnglishDateToWords
#include "EnglishTimeToWords.h"         // EnglishTimeToWords
#include "GermanDateToWords.h"          // GermanDateToWords
#include "GermanTimeToWords.h"          // GermanTimeToWords
#include "PopularEnglishTimeToWords.h"  // PopularEnglishTimeToWords

using namespace DateTimeToWords;

Converter::Converter():
        date_to_words_( new EnglishDateToWords(), true ),
        time_to_words_( new EnglishTimeToWords(), true )
{
    date_to_words_.insert( "en",    new EnglishDateToWords() );
    date_to_words_.insert( "de",    new GermanDateToWords() );
    date_to_words_.insert( "en_US", new AEnglishDateToWords() );

    time_to_words_.insert( "en",    new EnglishTimeToWords() );
    time_to_words_.insert( "de",    new GermanTimeToWords() );
    time_to_words_.insert( "en_GB", new PopularEnglishTimeToWords() );
}

const ITimeToWords* Converter::get_time_converter( const std::string & locale_code ) const
{
    return time_to_words_.find( locale_code );
}

const IDateToWords* Converter::get_date_converter( const std::string & locale_code ) const
{
    return date_to_words_.find( locale_code );
}
