#include <iostream>     // std::cout
#include <vector>

#include "EnglishDateToWords.h" // EnglishDateToWords
#include "EnglishTimeToWords.h" // EnglishTimeToWords

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

void test_02()
{
    struct time_e
    {
        unsigned h;
        unsigned m;
    };

    std::vector<time_e> times =
    {
            { 7, 45 },
            { 11, 6 },
            { 7, 15 },
            { 5, 30 },
            { 7, 0 },
            { 17, 20 },
            { 3, 15 },
    };

    DateTimeToWords::EnglishTimeToWords c;

    std::cout << "\n";
    std::cout << "Popular way" << std::endl;

    for( auto & e : times )
    {
        std::cout << e.h << ":" << e.m << " - " << c.to_words( e.h, e.m ) << std::endl;
    }

    std::cout << "\n";
    std::cout << "Formal way" << std::endl;

    for( auto & e : times )
    {
        std::cout << e.h << ":" << e.m << " - " << c.to_words( e.h, e.m, 0 ) << std::endl;
    }
}

int main()
{
    test_01();

    test_02();

    return 0;
}
