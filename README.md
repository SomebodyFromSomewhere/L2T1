# L2T1

Смотреть лучше в режиме raw: https://raw.githubusercontent.com/SomebodyFromSomewhere/L2T1/master/README.md

3.1. Заяц (5)
Имеется лестница, состоящая из N ступенек. При подъеме по лестнице заяц может прыгать на
любое количество ступенек от 1 до K. Сколько у зайца способов подъема по лестнице?
Ввод из файла INPUT.TXT. Единственная строка содержит целые положительные числа N и K.
Вывод в файл OUTPUT.TXT. Выводится единственное число - количество способов подъема по
лестнице.
Ограничения: 1 ≤ K ≤ N ≤ 100.
Пример
Ввод
3 2
Вывод
3

Логика работы алгоритма:

K = 2
F(N)
F(0) = |0|
/1\
F(1) = |1|
/1\
F(2) = |1, 2|, |2|
/2\
F(3) = |1, 2, 3|, |1, 3|, |2, 3|
/3\
F(4) = |1, 2, 3, 4|, |1, 2, 4|, |1, 3, 4|, |2, 3, 4|, |2, 4|
/5\
F(5) = |1, 2, 3, 4, 5|, |1, 2, 3, 5|, |1, 2, 4, 5|, |1, 3, 4, 5|, |1, 3, 5|, |2, 3, 4, 5|, |2, 3, 5|, |2, 4, 5|
/8\
F(6) = |1, 2, 3, 4, 5, 6|, |1, 2, 3, 4, 6|, |1, 2, 3, 5, 6|, |1, 2, 4, 5, 6|, |1, 2, 4, 6|, |1, 3, 4, 5, 6|, |1, 3, 4, 6|, |1, 3, 5, 6|, |2, 3, 4, 5, 6|, |2, 3, 4, 6|, |2, 3, 5, 6|, |2, 4, 5, 6|, |2, 4, 6|
/13\

//при K = 2 F(N) - последовательность фибоначи, F(N) = F(N-2) + F(N-1), со сдвигом на 1: 0:1, 1:1, 2:2 ...

K = 3
F(N)
F(0) = |0|
/1\
F(1) = |1|
/1\
F(2) = |1, 2|, |2|
/2\
F(3) = |1, 2 , 3|, |1, 3|, |2, 3|, |3|
/4\
F(4) = |1, 2, 3, 4|, |1, 2, 4|, |1, 3, 4|, |1, 4|, |2, 3, 4|, |2, 4|, |3, 4|
/7\
F(5) = |1, 2, 3, 4, 5|, |1, 2, 3, 5|, |1, 2, 4, 5|, |1, 2, 5|, |1, 3, 4, 5|, |1, 3, 5|, |1, 4, 5|, |2, 3, 4, 5|, |2, 3, 5|, |2, 4, 5|, |2, 5|, |3, 4, 5|, |3, 5|
/13\

//при K = 3 F(N) = 1, 1, 2, 4, 7, 13, F(N) = F(N-3) + F(N-2) + F(N-1), тут тоже сдвиг на 1

//при K = I, n = n - 1, n - 2, ..., 3, 2, 1;
F(N) = F(N - (I - n)) + ... + F(N - (I - 2)) + F(N - (I - 1)) + ... + F(N - 2) + F(N - 1) 
тут тоже сдвиг на 1
