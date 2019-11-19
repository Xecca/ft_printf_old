# ft_printf
My version function printf() in C language.

----------------------------------
Check status by 42filechacker:
1 -> author file            aponomar$								OK
2 -> norminette             Command not found						NO
3 -> makefile               All tests passed                    	OK
4 -> forbidden functions    No forbidden function found				OK
5 -> basic tests			50 failed test(s) out of 182 tests		NO
6 -> undefined behavior 	34 failed test(s) out of 55 tests		NO
tests
7 -> leaks					0 leaks for 0 total leaked bytes		OK
8 -> speed test				Estimated speed rate: 7%				NO
9 -> moulitest				20 failed test(s)						NO
A -> PFT					1340/1765 tests passed					NO

----------------------------------

- Good title about printf(): http://www.c-cpp.ru/content/printf


Функция printf() записывает в stdout аргументы из списка arg-list под управлением строки, на которую указывает аргумент format.

Строка, на которую указывает format, состоит из объектов двух различных назначений. Во- первых, это символы, которые сами должны быть выведены на экран. Во-вторых, это специфика­торы формата, определяющие вид, в котором будут выведены аргументы из списка arg-list. Спе­цификаторы формата состоят из символа процент, за которым следует код формата. Команды форматирования приведены в таблице. Количество аргументов должно точно соответство­вать количеству спецификаторов формата, причем следовать они должны в одинаковом порядке. Например, следующий вызов функции printf()

- printf ("Hi %с %d %s", 'с', 10, "there!");

приведет к выводу «Hi с 10 there!»

/////////

# Used resource:
http://www.cplusplus.com/reference/cstdio/printf/

https://linux.die.net/man/3/printf

https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html
