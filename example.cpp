#include <iostream>     // std::cout
#include <sstream>                      // std::ostringstream

#include "../HumanizerCpp/Configuration/Configurator.h" // Configurator

using namespace Humanizer::Localisation::NumberToWords;
using namespace Humanizer::Configuration;


std::string to_word( int number, const std::string & loc, bool is_ordinal )
{
    const INumberToWordsConverter * e = Configurator::GetNumberToWordsConverter( loc );

    return is_ordinal ? e->ConvertToOrdinal( number ) :e->Convert( number );
}

class DateToText
{
public:

    // http://english.stackexchange.com/questions/5442/what-are-the-rules-for-pronunciation-of-years-in-english
/*

For one thing, "Two Thousand" is shorter to say than "twenty hundred".

    1899: eighteen ninety-nine (shorter than one thousand eight hundred ninety-nine)
    1900: nineteen hundred (shorter than one thousand nine hundred)
    1901: nineteen oh one (shorter than nineteen hundred one, shorter than one thousand nine hundred one)
    1999: nineteen ninety nine (shorter than one thousand nine hundred ninety-nine)
    2000: two thousand (or 2 "K"?) (shorter than twenty hundred)
    2009: two thousand nine (shorter than twenty hundred nine)
    2010: twenty ten (shorter than two thousand ten)

     Basically when the number has three zeros it is shorter to say "thousand" than "hundred".
     Once there are fewer than three zeros it's shorter to say "Y thousand X" for Y00X and "Y hundred X" for YYXX.

     This usage isn't limited to years either. Any numbers in the same range will have the same kinds of contractions.
     There's a Simpsons episode where this is played for laughs, when they need eighty-five-hundred dollars to fix their roof,
     and they only have $500, and Homer whines that they still need eighty-hundred.

 */

    static std::string to_text( unsigned int year, unsigned int month, unsigned int day )
    {
        static const std::string months[] =
        {
                "January", "February", "March", "April", "Mai", "June", "July", "August", "September", "October", "November", "December"
        };

        if( month < 1 || month > 12 )
        {
            month = 1;
        }

        std::string day_str = to_word( day, "en", true );
        const std::string & month_str = months[month - 1];

        auto year_high = year / 100;
        auto year_low = year % 100;

        std::string year_hi_str = to_word( year_high, "en", false );
        std::string year_low_str = to_word( year_low, "en", false );

        std::ostringstream res;

        res << day_str << " of " << month_str << " " << year_hi_str << " " << year_low_str;

        return res.str();
    }
};


int main()
{
    std::cout << "Hello" << std::endl;

    std::cout << DateToText::to_text( 2015, 8, 21 ) << std::endl;

    return 0;
}
