trout: trout.o util.o
	gcc trout.o util.o -o trout

trout.o: trout.c trout.h
	gcc -c trout.c

trout.o: util.c util.h
	gcc -c util.c



encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c

message_hider.o: message_hider.c encrypt.o encrypt.h
	gcc -c message_hider.c

message_hider: message_hider.o encrypt.o
	gcc message_hider.o encrypt.o -o message_hider
