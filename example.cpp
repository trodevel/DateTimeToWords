#include <iostream>     // std::cout
#include <vector>
#include <iomanip>

#include "EnglishDateToWords.h" // EnglishDateToWords
#include "EnglishTimeToWords.h" // EnglishTimeToWords
#include "PopularEnglishTimeToWords.h" // PopularEnglishTimeToWords

void test_01()
{
    DateTimeToWords::EnglishDateToWords c;

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
    std::cout << "Date to words" << std::endl;

    for( auto & e : dates )
    {
        std::cout << e.y << "-" << e.m << "-" << e.d << ": " << c.to_words( e.y, e.m, e.d ) << std::endl;
    }
}

void test_time( DateTimeToWords::ITimeToWords * c, const char * descr )
{
    struct time_e
    {
        unsigned h;
        unsigned m;
        unsigned s;
    };

    std::vector<time_e> times =
    {
            { 7, 45, 0 },
            { 11, 6, 2 },
            { 7, 15, 15 },
            { 5, 30, 27 },
            { 7, 0, 58 },
            { 17, 20, 10 },
            { 3, 15, 1 },
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

void test_02()
{
    DateTimeToWords::EnglishTimeToWords c;

    test_time( &c, "Formal way" );

    DateTimeToWords::PopularEnglishTimeToWords c2;

    test_time( &c2, "Popular way" );
}

int main()
{
    test_01();

    test_02();

    return 0;
}
