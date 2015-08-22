#include <iostream>     // std::cout

#include "EnglishDateToWords.h" // EnglishDateToWords

int main()
{
    DateTimeToWords::EnglishDateToWords e;

    std::cout << "2015-08-21: " << e.to_words( 2015, 8, 21 ) << std::endl;
    std::cout << "1899-08-21: " << e.to_words( 1899, 8, 21 ) << std::endl;
    std::cout << "1900-08-21: " << e.to_words( 1900, 8, 21 ) << std::endl;
    std::cout << "1901-08-21: " << e.to_words( 1901, 8, 21 ) << std::endl;
    std::cout << "1999-08-21: " << e.to_words( 1999, 8, 21 ) << std::endl;
    std::cout << "2000-08-21: " << e.to_words( 2000, 8, 21 ) << std::endl;
    std::cout << "2009-08-21: " << e.to_words( 2009, 8, 21 ) << std::endl;
    std::cout << "2010-08-21: " << e.to_words( 2010, 8, 21 ) << std::endl;

    return 0;
}
