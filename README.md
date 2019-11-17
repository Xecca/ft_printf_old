# ft_printf
My version function printf() in C language.

----------------------------------
Check status by 42filechacker:
dif```
+ 1 -> author file						aponomar$
# 2 -> norminette						Command not found
- 3 -> makefile							4 error(s)
- 4 -> forbidden functions				Cannot compile
- 5 -> basic tests						Cannot compile
- 6 -> undefined behavior tests			Cannot compile
- 7 -> leaks							Cannot compile
- 8 -> speed test						Cannot compile
- 9 -> moulitest						Cannot compile
- A -> PFT								PFT has aborted
```
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
