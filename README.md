Converts dates and times into words
===================================

- currently supports English, German and Russian
- uses HumanizerCpp library

Example:

```
$ ./example

English
1899-01-01: the first of January eighteen ninety-nine
1900-02-15: the fifteenth of February nineteen hundred
1901-03-31: the thirty-first of March one thousand nine hundred one
1999-04-30: the thirtieth of April nineteen ninety-nine
2000-05-29: the twenty-ninth of May two thousand
2009-06-21: the twenty-first of June two thousand nine
2010-07-21: the twenty-first of July twenty ten
2015-08-21: the twenty-first of August twenty fifteen
2015-09-21: the twenty-first of September twenty fifteen
2015-10-21: the twenty-first of October twenty fifteen
2015-11-21: the twenty-first of November twenty fifteen
2015-12-21: the twenty-first of December twenty fifteen

German
1899-01-01: erste Januar achtzehn hundert neunundneunzig
1900-02-15: fünfzehnte Februar neunzehn hundert
1901-03-31: einunddreißigste März neunzehn hundert eins
1999-04-30: dreißigste April eintausendneunhundertneunundneunzig
2000-05-29: neunundzwanzigste Mai zweitausend
2009-06-21: einundzwanzigste Juni zweitausendneun
2010-07-21: einundzwanzigste Juli zweitausendzehn
2015-08-21: einundzwanzigste August zweitausendfünfzehn
2015-09-21: einundzwanzigste September zweitausendfünfzehn
2015-10-21: einundzwanzigste Oktober zweitausendfünfzehn
2015-11-21: einundzwanzigste November zweitausendfünfzehn
2015-12-21: einundzwanzigste Dezember zweitausendfünfzehn

Russian
1899-01-01: первое января одна тысяча восемьсот девяносто девятого года
1900-02-15: пятнадцатое февраля одна тысяча девятисотого года
1901-03-31: тридцать первое марта одна тысяча девятьсот первого года
1999-04-30: тридцатое апреля одна тысяча девятьсот девяносто девятого года
2000-05-29: двадцать девятое мая двухтысячного года
2009-06-21: двадцать первое июня две тысячи девятого года
2010-07-21: двадцать первое июля две тысячи десятого года
2015-08-21: двадцать первое августа две тысячи пятнадцатого года
2015-09-21: двадцать первое сентября две тысячи пятнадцатого года
2015-10-21: двадцать первое октября две тысячи пятнадцатого года
2015-11-21: двадцать первое ноября две тысячи пятнадцатого года
2015-12-21: двадцать первое декабря две тысячи пятнадцатого года

English - Formal way
00:00 - zero o'clock in the morning
01:01 - one oh one in the morning
02:02 - two oh two in the morning
03:15 - three fifteen in the morning
04:04 - four oh four in the morning
04:33 - four thirty-three in the morning
05:05 - five oh five in the morning
05:30 - five thirty in the morning
06:00 - six o'clock in the morning
07:15 - seven fifteen in the morning
08:45 - eight forty-five in the morning
11:06 - eleven oh six in the morning
12:00 - zero o'clock in the afternoon
17:22 - five twenty-two in the afternoon
21:17 - nine seventeen in the afternoon

English - Formal way (with seconds)
00:00:00 - zero o'clock in the morning and zero seconds
01:01:01 - one oh one in the morning and one second
02:02:02 - two oh two in the morning and two seconds
03:15:01 - three fifteen in the morning and one second
04:04:04 - four oh four in the morning and four seconds
04:33:27 - four thirty-three in the morning and twenty-seven seconds
05:05:05 - five oh five in the morning and five seconds
05:30:27 - five thirty in the morning and twenty-seven seconds
06:00:58 - six o'clock in the morning and fifty-eight seconds
07:15:15 - seven fifteen in the morning and fifteen seconds
08:45:00 - eight forty-five in the morning and zero seconds
11:06:02 - eleven oh six in the morning and two seconds
12:00:00 - zero o'clock in the afternoon and zero seconds
17:22:10 - five twenty-two in the afternoon and ten seconds
21:17:10 - nine seventeen in the afternoon and ten seconds

English - Popular way
00:00 - midnight
01:01 - one minute past one in the morning
02:02 - two minutes past two in the morning
03:15 - a quarter past three in the morning
04:04 - four minutes past four in the morning
04:33 - twenty-seven minutes to five in the morning
05:05 - five minutes past five in the morning
05:30 - half past five in the morning
06:00 - six o'clock in the morning
07:15 - a quarter past seven in the morning
08:45 - a quarter to nine in the morning
11:06 - six minutes past eleven in the morning
12:00 - noon
17:22 - twenty-two minutes past five in the afternoon
21:17 - seventeen minutes past nine in the afternoon

English - Popular way (with seconds)
00:00:00 - midnight and zero second
01:01:01 - one minute past one in the morning and one second
02:02:02 - two minutes past two in the morning and two seconds
03:15:01 - a quarter past three in the morning and one second
04:04:04 - four minutes past four in the morning and four seconds
04:33:27 - twenty-seven minutes to five in the morning and twenty-seven seconds
05:05:05 - five minutes past five in the morning and five seconds
05:30:27 - half past five in the morning and twenty-seven seconds
06:00:58 - six o'clock in the morning and fifty-eight seconds
07:15:15 - a quarter past seven in the morning and fifteen seconds
08:45:00 - a quarter to nine in the morning and zero second
11:06:02 - six minutes past eleven in the morning and two seconds
12:00:00 - noon and zero second
17:22:10 - twenty-two minutes past five in the afternoon and ten seconds
21:17:10 - seventeen minutes past nine in the afternoon and ten seconds

German
00:00 - null Uhr
01:01 - eins Uhr eins
02:02 - zwei Uhr zwei
03:15 - drei Uhr fünfzehn
04:04 - vier Uhr vier
04:33 - vier Uhr dreiunddreißig
05:05 - fünf Uhr fünf
05:30 - fünf Uhr dreißig
06:00 - sechs Uhr
07:15 - sieben Uhr fünfzehn
08:45 - acht Uhr fünfundvierzig
11:06 - elf Uhr sechs
12:00 - zwölf Uhr
17:22 - siebzehn Uhr zweiundzwanzig
21:17 - einundzwanzig Uhr siebzehn

German (with seconds)
00:00:00 - null Uhr und null Sekunden
01:01:01 - eins Uhr eins und eine Sekunde
02:02:02 - zwei Uhr zwei und zwei Sekunden
03:15:01 - drei Uhr fünfzehn und eine Sekunde
04:04:04 - vier Uhr vier und vier Sekunden
04:33:27 - vier Uhr dreiunddreißig und siebenundzwanzig Sekunden
05:05:05 - fünf Uhr fünf und fünf Sekunden
05:30:27 - fünf Uhr dreißig und siebenundzwanzig Sekunden
06:00:58 - sechs Uhr und achtundfünfzig Sekunden
07:15:15 - sieben Uhr fünfzehn und fünfzehn Sekunden
08:45:00 - acht Uhr fünfundvierzig und null Sekunden
11:06:02 - elf Uhr sechs und zwei Sekunden
12:00:00 - zwölf Uhr und null Sekunden
17:22:10 - siebzehn Uhr zweiundzwanzig und zehn Sekunden
21:17:10 - einundzwanzig Uhr siebzehn und zehn Sekunden

Russian
00:00 - ноль часов ноль минут
01:01 - один час одна минута
02:02 - два часа две минуты
03:15 - три часа пятнадцать минут
04:04 - четыре часа четыре минуты
04:33 - четыре часа тридцать три минуты
05:05 - пять часов пять минут
05:30 - пять часов тридцать минут
06:00 - шесть часов ноль минут
07:15 - семь часов пятнадцать минут
08:45 - восемь часов сорок пять минут
11:06 - одиннадцать часов шесть минут
12:00 - двенадцать часов ноль минут
17:22 - семнадцать часов двадцать две минуты
21:17 - двадцать один час семнадцать минут

Russian (with seconds)
00:00:00 - ноль часов ноль минут ноль секунд
01:01:01 - один час одна минута одна секунда
02:02:02 - два часа две минуты две секунды
03:15:01 - три часа пятнадцать минут одна секунда
04:04:04 - четыре часа четыре минуты четыре секунды
04:33:27 - четыре часа тридцать три минуты двадцать семь секунд
05:05:05 - пять часов пять минут пять секунд
05:30:27 - пять часов тридцать минут двадцать семь секунд
06:00:58 - шесть часов ноль минут пятьдесят восемь секунд
07:15:15 - семь часов пятнадцать минут пятнадцать секунд
08:45:00 - восемь часов сорок пять минут ноль секунд
11:06:02 - одиннадцать часов шесть минут две секунды
12:00:00 - двенадцать часов ноль минут ноль секунд
17:22:10 - семнадцать часов двадцать две минуты десять секунд
21:17:10 - двадцать один час семнадцать минут десять секунд
$
```
