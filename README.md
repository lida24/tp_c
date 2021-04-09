Ленкова Лидия Павловна АПО-12
Вариант #41
В оперативную память загружен файл размером 100 Мб. Необходимо подсчитать количество пар соседних байт, разность значений которых равна 0, 1, 2, …, 10. Составьте наивный алгоритм подсчета, который сначала ищет все пары с нулевой разностью, затем — с единичной и т.д., а затем реализуйте параллельную обработку текста несколькими потоками с учетом оптимизации работы с кэш-памятью.

--------------------------------------------------------------
Результат работы программы:
С потоками:
lida@lida-VirtualBox:~/TechnoPark/yz/tp_c/iz2$ time ./parallel
cash L1 size = 64 
allThreads = 8 

Diff Count
0 425185
1 414400
2 380482
3 343332
4 343950
5 335233
6 350155
7 332710
8 336482
9 327771
10 323957

real 0m3,287s
user 0m3,200s
sys 0m0,020s

--------------------------------------------------

Без потоков:
lida@lida-VirtualBox:~/TechnoPark/yz/tp_c/iz2$ time ./static
cash L1 size = 64 
allThreads = 1 

Diff Count
0 425185
1 414400
2 380482
3 343332
4 343950
5 335233
6 350155
7 332710
8 336482
9 327771
10 323957

real 0m3,302s
user 0m3,219s
sys 0m0,028s