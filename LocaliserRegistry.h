/*

interface LocaliserRegistry.

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

// $Revision: 2432 $ $Date:: 2015-08-27 #$ $Author: serge $

#ifndef DateTimeToWords_LocaliserRegistry_h
#define DateTimeToWords_LocaliserRegistry_h

#include <map>                      // std::map
#include <string>                   // std::string

namespace DateTimeToWords
{

template< class TLocaliser >
class LocaliserRegistry
{

public:
    LocaliserRegistry( TLocaliser *default_localiser, bool delete_in_dtor = false ):
        default_localiser_( default_localiser ),
        delete_in_dtor_( delete_in_dtor )
    {
    }

    ~LocaliserRegistry()
    {
        if( delete_in_dtor_ )
        {
            for( auto & e : localisers_ )
                delete e.second;

            if( default_localiser_ )
                delete default_localiser_;
        }
    }

    void insert( const std::string & locale_code, TLocaliser * localiser )
    {
        localisers_[locale_code] = localiser;
    }

    const TLocaliser* find( const std::string &locale_code ) const
    {
        if( locale_code.empty() )
            return default_localiser_;

        auto it = localisers_.find( locale_code );
        if( it != localisers_.end() )
            return it->second;

        return default_localiser_;
    }

private:

    std::map<std::string, TLocaliser*>  localisers_;

    TLocaliser                          * default_localiser_;
    bool                                delete_in_dtor_;
};
}

#endif // DateTimeToWords_LocaliserRegistry_h
