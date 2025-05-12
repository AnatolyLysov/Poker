/*The provided code is the main implementation of a Monte Carlo-based poker game simulation. It defines the game flow, player interactions, and decision-making logic. Here's a detailed explanation of the key components:

1. main Function
The main function is the entry point of the program. It initializes the game, manages the game loop, and handles cleanup.

Initialization
Variables:

setloop and roundloop: Control the game flow. setloop tracks sets (complete games), and roundloop tracks rounds within a set.
numbankruptplayers and numfolded: Track the number of bankrupt and folded players.
tmpCard, playingDeck, and players: Dynamically allocated memory for temporary cards, the deck, and the players.
sims: Number of Monte Carlo simulations to run, derived from the command-line argument.
maxdiscards, maxthrown, and maxvalue: Variables used by the Monte Carlo advisor to suggest discards and bets.
Game Setup:

Players are initialized using player_init.
The deck is initialized, filled with cards, and shuffled.
Game Rules Display
The rules of the game are printed to the console for the user.

2. Game Loop
The game loop consists of two nested loops:

Set Loop (while(setloop != 0)):

Represents a complete game from a full deck.
Ends when only one player has money left.
Round Loop (while(roundloop != 3)):

Each set has two rounds of betting.
Players can bet, fold, or discard cards during their turn.
Card Distribution
Cards are distributed to players at the start of each set.
Players with money receive cards, and their hands are sorted.
Player Turns
Each player takes a turn during the round:
Human Player:
Displays the player's hand and prompts for a bet.
Provides Monte Carlo advisor suggestions for discards.
Allows the player to discard cards or fold.
Computer Players:
Use the Monte Carlo advisor to determine bets and discards.
Automatically make decisions based on expected hand value.
Monte Carlo Advisor
The advisor runs simulations to evaluate the best cards to discard and the expected value of the hand.
This information is used to guide both human and computer players.
Round End
After all players have taken their turns, the round ends.
If only one player remains (others folded), they win the pool.
If multiple players remain, a showdown determines the winner.
3. Showdown
At the end of two rounds, players reveal their hands.
The player with the highest hand value wins the pool.
If only one player remains (others folded), they automatically win.
4. End of Set
Bankrupt players are identified and removed from the game.
The deck is reset and shuffled.
Player hands are reset, and fold statuses are updated.
5. Game End
The game ends when only one player has money left.
The winner is announced, and the game loop exits.
6. Cleanup
Memory allocated for the deck, players, and temporary variables is freed to prevent memory leaks.
7. Helper Functions
check_input
Validates the player's input for discarding cards.
Ensures the input is within the valid range and avoids duplicate discards.
get_max_incremental_bet
Determines the maximum bet a computer player is willing to make based on the expected hand value.
Considers the player's current money and the minimum required bet.
get_incremental_bet
Prompts the human player for a valid bet.
Ensures the bet meets the minimum requirement and does not exceed the player's money.
Key Features
Monte Carlo Simulation:

Simulates possible outcomes to guide decision-making for both human and computer players.
Helps determine optimal discards and betting strategies.
Dynamic Memory Management:

Uses malloc and free to allocate and deallocate memory for cards, players, and the deck.
Human and AI Interaction:

Provides a user interface for the human player.
Automates decisions for computer players based on simulations.
Game Rules Enforcement:

Ensures players follow the rules, such as matching the highest bet to stay in the game.
Showdown Logic:

Compares hands to determine the winner at the end of a set.
Potential Improvements
Error Handling:

Add checks for memory allocation failures in all malloc calls.
Handle invalid command-line arguments (e.g., missing or non-numeric input for sims).
Code Readability:

Add more comments to explain complex logic, especially in the Monte Carlo simulation and betting functions.
Input Validation:

Improve input validation for the human player's actions (e.g., discards and bets).
Monte Carlo Advisor:

Enhance the simulation logic to consider more advanced poker strategies.
Modularity:

Break the main function into smaller functions to improve readability and maintainability.
Example Game Flow
The game starts, and the human player enters their name.
Cards are distributed, and players take turns betting and discarding cards.
After two rounds, a showdown determines the winner of the pool.
The game continues until only one player has money left.
Let me know if you'd like further clarification or assistance with specific parts of the code!*/

///////////////////////////////////////////////////////////////////////////////////
/*Представленный код является основной реализацией симулятора игры в покер на основе Монте-Карло. 
Он определяет ход игры, взаимодействие игроков и логику принятия решений. Вот подробное объяснение 
ключевых компонентов:

1. основная функция
Функция main - это точка входа в программу. Она инициализирует игру, управляет игровым циклом и 
выполняет очистку.

Инициализация
Переменные:

setloop и roundloop: Управляйте течением игры. setloop отслеживает наборы (полные игры), 
а roundloop - раунды внутри набора.
numbankruptplayers и numfolded: Отслеживают количество обанкротившихся и сложенных игроков.
tmpCard, playingDeck и players: Динамически выделяемая память для временных карт, колоды и игроков.
sims: Количество запущенных симуляций Монте-Карло, полученное из аргумента командной строки.
maxdiscards, maxthrown и maxvalue: Переменные, используемые советником Монте-Карло для предложения 
выбросов и ставок.
Настройка игры:

Игроки инициализируются с помощью player_init.
Колода инициализируется, заполняется картами и тасуется.
Дисплей с правилами игры
Правила игры выводятся на консоль для пользователя.

2. Игровая петля
Игровой цикл состоит из двух вложенных циклов:

Установить цикл (while(setloop != 0)):

Представляет собой полную партию из полной колоды.
Заканчивается, когда деньги остаются только у одного игрока.
Круглый цикл (while(roundloop != 3)):

Каждый сет состоит из двух раундов ставок.
Во время своего хода игроки могут делать ставки, складывать или сбрасывать карты.
Распространение карт
Карточки раздаются игрокам в начале каждого сета.
Игроки с деньгами получают карты, и их руки сортируются.
Повороты игрока
Каждый игрок делает ход в течение раунда:
Человек-игрок:
Отображает руку игрока и предлагает сделать ставку.
Предоставляет рекомендации советника Монте-Карло по отбраковке.
Позволяет игроку сбросить карты или сложить.
Компьютерные игроки:
Используйте советник Монте-Карло для определения ставок и сбросов.
Автоматически принимайте решения на основе ожидаемой стоимости руки.
Советник Монте-Карло
Советник запускает симуляцию, чтобы оценить лучшие карты для сброса и ожидаемую ценность руки.
Эта информация используется для руководства как человеческими, так и компьютерными игроками.
Круглый конец
После того как все игроки сделают свои ходы, раунд заканчивается.
Если остался только один игрок (остальные сдались), он выигрывает пул.
Если остается несколько игроков, победитель определяется в шоудауне.
3. Шоудаун
По окончании двух раундов игроки раскрывают свои руки.
Игрок с наибольшим значением руки выигрывает пул.
Если остался только один игрок (остальные сдались), он автоматически выигрывает.
4. Конец набора
Игроки-банкроты выявляются и удаляются из игры.
Колода сбрасывается и перетасовывается.
Руки игроков сбрасываются, а статусы фолдов обновляются.
5. Конец игры
Игра заканчивается, когда деньги остаются только у одного игрока.
Объявляется победитель, и цикл игры завершается.
6. Очистка
Память, выделенная для колоды, игроков и временных переменных, освобождается, чтобы предотвратить 
утечку памяти.
7. Вспомогательные функции
проверка_ввода
Проверяет вводимые игроком данные для сброса карт.
Убедитесь, что входные данные находятся в пределах допустимого диапазона, и избегайте дублирования.
get_max_incremental_bet
Определяет максимальную ставку, которую готов сделать компьютерный игрок, исходя из ожидаемого 
значения руки.
Учитывает текущие деньги игрока и минимально необходимую ставку.
get_incremental_bet
Предлагает игроку сделать правильную ставку.
Обеспечивает соответствие ставки минимальному требованию и не превышает сумму денег игрока.
Основные характеристики
Моделирование методом Монте-Карло:

Моделирование возможных исходов для принятия решений как человеком, так и компьютером.
Помогает определить оптимальные стратегии отбрасывания и ставок.
Динамическое управление памятью:

Использует malloc и free для выделения и удаления памяти для карт, игроков и колоды.
Взаимодействие человека и ИИ:

Предоставляет пользовательский интерфейс для игрока-человека.
Автоматизирует принятие решений для компьютерных игроков на основе симуляций.
Соблюдение правил игры:

Следит за тем, чтобы игроки соблюдали правила, например, делали максимальную ставку, чтобы 
статься в игре.
Логика шоудауна:

Сравнивает руки, чтобы определить победителя в конце сета.
Потенциальные улучшения
Обработка ошибок:

Добавьте проверку на ошибки выделения памяти во всех вызовах malloc.
Обработка неверных аргументов командной строки (например, отсутствующих или нечисловых аргументов 
для sims).
Читаемость кода:

Добавьте больше комментариев для объяснения сложной логики, особенно в функциях моделирования 
Монте-Карло и ставок.
Проверка достоверности ввода:

Улучшение проверки ввода для действий игрока-человека (например, сбросов и ставок).
Советник Монте-Карло:

Усовершенствуйте логику симуляции, чтобы учитывать более сложные стратегии игры в покер.
Модульность:

Разбейте главную функцию на более мелкие, чтобы улучшить читаемость и сопровождаемость.
Пример игрового потока
Игра начинается, и игрок-человек вводит свое имя.
Раздаются карты, и игроки по очереди делают ставки и сбрасывают карты.
После двух раундов победителя определит шоу-битва.
Игра продолжается до тех пор, пока деньги не останутся только у одного игрока.
Дайте мне знать, если вам нужны дальнейшие разъяснения или помощь с конкретными частями кода! */

