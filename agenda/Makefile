#
# Segunda tentativa de Makefile
#

C_COMP=gcc
FONTES=$(wildcard *.c)    # equivale a dizer FONTES=main.c regras.c letras.c
HEADERS=$(wildcard *.h)

.PHONY: all clean tar

all: agenda

agenda: $(FONTES:.c=.o)
	$(C_COMP) -o $@ $^

%.o: %.c $(HEADERS)
	$(C_COMP) -c $< -o $@

clean:
	rm -f *.o agenda *~

tar:
	tar cvjf agenda.tar.bz2 $(FONTES) $(HEADERS)