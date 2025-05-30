pokergame: pokergame.o card.o deck.o hand.o player.o mcadvisor.o pokergame.h
	gcc -Wall -g -o pokergame pokergame.o card.o deck.o hand.o player.o mcadvisor.o pokergame.h

pokergame.o: pokergame.c card.o deck.o hand.o player.o mcadvisor.o pokergame.h
	gcc -Wall -g -c pokergame.c -I.

mcadvisor.o: mcadvisor.c card.o deck.o hand.o player.o pokergame.h
	gcc -Wall -g -c mcadvisor.c -I.

player.o: player.c card.o deck.o hand.o pokergame.h
	gcc -Wall -g -c player.c -I.

hand.o: hand.c card.o deck.o pokergame.h
	gcc -Wall -g -c hand.c -I.

deck.o: deck.c card.o pokergame.h
	gcc -Wall -g -c deck.c -I.

card.o: card.c pokergame.h
	gcc -Wall -g -c card.c -I.

clean: 
	\rm -f *.o *# *~ pokergame