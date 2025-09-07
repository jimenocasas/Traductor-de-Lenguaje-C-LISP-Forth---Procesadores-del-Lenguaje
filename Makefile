# Makefile para compilar los traductores trad3 y back4

all: trad back

# Reglas para trad
trad: trad.tab.c trad.tab.h
	gcc -o trad trad.tab.c

trad.tab.c trad.tab.h: trad.y
	bison -d trad.y

# Reglas para back
back: back.tab.c back.tab.h
	gcc -o back back.tab.c

back.tab.c back.tab.h: back.y
	bison -d -Wcounterexamples back.y

# Regla para limpiar los archivos generados
clean:
	rm -f trad trad.tab.c trad.tab.h back back.tab.c back.tab.h
