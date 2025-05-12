Readme.txt
Poker game

A five-card draw poker game written in C. One human player and 3 AI opponents.
AI programmed using Monte Carlo simulation technique. 

===========================
Build:
===========================
In Terminal:

make clean
make

OR

gcc -Wall -c card.c -I.
gcc -Wall -c deck.c -I.
gcc -Wall -c hand.c -I.
gcc -Wall -c player.c -I.
gcc -Wall -c mcadvisor.c -I.
gcc -Wall -c pokergame.c -I.
gcc -Wall -o pokergame pokergame.o card.o deck.o hand.o player.o mcadvisor.o

===========================
Functionality:
===========================
Run the simulation using the following command line input:
./pokergame 1000
The number 1000 can be varied. It is an argument containing the number of simulations to run per discard option. 
So inputting 1000 will run 32,000 simulations per hand, which takes about 4.6 seconds on a Macbook Air. 
I have found I can get correct Monte Carlo logic even at 200 simulations and the game runs significantly faster (<1 sec response time)

===========================
Rules:
===========================
(A) 2 rounds of betting per set. Bets go into the 'pool'.
(B) Every player must call at least the highest bet in round 1 in order to remain in the game. They don't have to call the highest bet in round 2.
(C) In each round, every player may discard and draw up to 5 cards from the deck.
(D) A player may also choose to fold at any time, during their turn but forfeits any bets they already made.
(E) Player with the highest set of cards at the end of 2 rounds wins all the money in the pool.
(F) If all players except one folds, the remaining player wins the pool, and does not need to show their hand.
(G) The game continues in sets of 2 rounds until all players except one is bankrupt.

===========================
Shortcomings:
===========================

--If a player doesn't have enough money to call a bet, I haven't implemented functionality for the player to go 'all-in'.
Implementing the 'all-in' feature will also need to split the pool of money and create side-bets.
--Also, since rare, I haven't implemented tie breaking. In the event of a tie, the winner will be the first player in order that has the tying hand.
Implementing tie-breaking requires introducing some logic to split the pool winnings.

--If the human player puts in a low bet in round 1, but then bluffs in round 2 by putting in an extraordinarily high bet, all the computer players will likely fold.
In this way, the human player can typically win all the bets the computer players made in round 1. This is because the computer players only bet on a scale linked to the expected value of their cards. The computer bets high when it has good cards, and low when it has bad cards. There isn't any mechanism for the computer to guess if someone is bluffing.
 
Since the betting features are independent of the project grade, I didn't go into these additional features.

===========================
Documentation:
===========================
--deck.c contains the Deck struct. This struct contains 52 consecutive in-memory pointers to Card structs. 
We can iterate through all 52 cards in the deck by iterating over the 52 pointers to Card structs.
The Deck struct has one integer that gives the index of the first pointer (out of 52 pointers) that is at the "top" of the deck. 
To dequeue a card, call dequeue_card, which saves the top card of the deck into one of the provided arguments. 
Then the integer will be incremented to point to the next card in the deck, which becomes the new 'top' card.
To enqueue all the cards back into the deck, we simply assign the integer the index of the first pointer.  

--hand.c contains the Hand struct. This struct contains 5 consecutive in-memory pointers to Card structs. 
We can iterate through all 5 cards in the hand by iterating over the pointers to Card structs.
There are functions to add cards, replace cards, and sort the hand.
This struct also contains a function to get the value of the hand, which is used by the Monte Carlo advisor.

--card.c contains the Card struct. This struct simply contains the data for the suit and rank of the card. 
Also there are some functions to print the card and compare the card to other cards.

--player.c contains a wrapper around the Hand struct. The Player struct contains one pointer to a Hand struct, and some additional information about the player such as their name, money they have, whether the player folded, and what they have bet into the pool in the current round.

--mcadvisor.c contains the logic of the Monte Carlo advisor. Only the first function (called mc) is public. The other two functions are private functions to be used by the mc function.More description on this is in the mcadvisor.c file.

--pokergame.c contains the game loop for the program. 

--pokergame.h contains the function prototypes, #include, and #define for all files

/////////////////////////////////////////////////////////////////////////////////

Readme.txt
Игра в покер

Игра в пятикарточный покер, написанная на языке C. Один игрок - человек, 3 противника - искусственный интеллект.
ИИ запрограммирован с использованием метода моделирования Монте-Карло. 

===========================
Постройте:
===========================
В терминале:

сделать чистым
сделать

ИЛИ

gcc -Wall -c card.c -I.
gcc -Wall -c deck.c -I.
gcc -Wall -c hand.c -I.
gcc -Wall -c player.c -I.
gcc -Wall -c mcadvisor.c -I.
gcc -Wall -c pokergame.c -I.
gcc -Wall -o pokergame pokergame.o card.o deck.o hand.o player.o mcadvisor.o

===========================
Функциональность:
===========================
Запустите моделирование, используя следующий ввод командной строки:
./pokergame 1000
Число 1000 может быть изменено. Это аргумент, содержащий количество симуляций для каждой опции отбрасывания. 
Таким образом, при вводе 1000 будет выполнено 32 000 симуляций на каждую руку, что займет около 4,6 секунды на Macbook Air. 
Я обнаружил, что могу получить правильную логику Монте-Карло даже при 200 симуляциях, и игра работает значительно быстрее (время отклика <1 секунды).

===========================
Правила:
===========================
(A) 2 раунда ставок на сет. Ставки идут в "пул".
(B) Каждый игрок должен сделать как минимум самую высокую ставку в раунде 1, чтобы остаться в игре. Они не обязаны делать самую высокую ставку во втором раунде.
(C) В каждом раунде каждый игрок может сбросить и взять из колоды до 5 карт.
(D) Игрок также может отказаться от игры в любой момент во время своего хода, но при этом он теряет все сделанные им ставки.
(E) Игрок с наибольшим набором карт в конце 2 раунда выигрывает все деньги в пуле.
(F) Если все игроки, кроме одного, фолдят, оставшийся игрок выигрывает пул, и ему не нужно показывать свою руку.
(G) Игра продолжается сериями по 2 раунда, пока все игроки, кроме одного, не станут банкротами.

===========================
Недостатки:
===========================

--Если у игрока недостаточно денег, чтобы сделать колл, я не реализовал функцию, позволяющую игроку пойти "олл-ин".
Реализация функции "олл-ин" также потребует разделения денежного пула и создания побочных ставок.
-Также, с редких пор, я не вводил тай-брейк. В случае ничьей победителем станет первый по порядку игрок, у которого окажется ничья.
Реализация тай-брейка требует введения логики для разделения выигрыша в пуле.

--Если человек делает низкую ставку в первом раунде, а затем блефует во втором раунде, делая чрезвычайно высокую ставку, все компьютерные игроки, скорее всего, откажутся.
Таким образом, человеческий игрок обычно может выиграть все ставки, сделанные компьютерными игроками в первом раунде. Это происходит потому, что компьютерные игроки делают ставки только по шкале, связанной с ожидаемой стоимостью их карт. Компьютер делает высокие ставки, когда у него хорошие карты, и низкие, когда у него плохие карты. У компьютера нет никакого механизма, позволяющего ему угадать, блефует ли кто-то.

Поскольку функции ставок не зависят от оценки проекта, я не стал углубляться в эти дополнительные возможности.

===========================
Документация:
===========================
--deck.c содержит структуру Deck. Эта структура содержит 52 последовательных указателя в памяти на структуры Card. 
Мы можем перебрать все 52 карты в колоде, перебирая 52 указателя на структуры Card.
В структуре Deck есть одно целое число, которое дает индекс первого указателя (из 52 указателей), находящегося на "вершине" колоды. 
Чтобы снять карту, вызовите команду dequeue_card, которая сохраняет верхнюю карту колоды в один из предоставленных аргументов. 
Затем целое число увеличивается и указывает на следующую карту в колоде, которая становится новой "верхней" картой.
Чтобы вернуть все карты в колоду, мы просто присваиваем целому числу индекс первого указателя.  

--hand.c содержит структуру Hand. Эта структура содержит 5 последовательных указателей в памяти на структуры Card. 
Мы можем перебрать все 5 карт в руке, перебирая указатели на структуры Card.
Есть функции добавления карт, замены карт и сортировки рук.
Эта структура также содержит функцию для получения значения руки, которое используется советником Монте-Карло.

--card.c содержит структуру Card. Эта структура просто содержит данные о масти и ранге карты. 
Также есть функции печати карты и сравнения ее с другими картами.

--player.c содержит обертку вокруг Hand struct. Структура Player содержит один указатель на структуру Hand и некоторую дополнительную информацию об игроке, такую как его имя, деньги, которые у него есть, фолдит ли он, и сколько он поставил в пул в текущем раунде.

--mcadvisor.c содержит логику работы советника Монте-Карло. Только первая функция (называется mc) является публичной. Две другие функции являются частными функциями, которые используются функцией mc. Более подробное описание этого находится в файле mcadvisor.c.

--pokergame.c содержит игровой цикл программы. 

--pokergame.h содержит прототипы функций, #include и #define для всех файлов

 






