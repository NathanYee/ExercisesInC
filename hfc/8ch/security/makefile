encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c

checksum.o: checksum.c checksum.h
		gcc -c checksum.c

bank.o: bank.c encrypt.c encrypt.h checksum.c checksum.h
	gcc -c bank.c

bank: bank.o encrypt.o checksum.o
	gcc bank.o encrypt.o checksum.o -o bank

libhfsecurity.a: encrypt.o checksum.o
	ar -rcs libhfsecurity.a encrypt.o checksum.o

bank_vault: bank_vault.c libhfsecurity.a
	gcc bank_vault.c -I. -L. -lhfsecurity -o bank_vault
