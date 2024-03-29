CC = @gcc -Wall

FILES_C = main.c
FILES_O = ./objects/$(FILES_C:.c=.o)

P4TH = -I./include -L./lib
LIBS = -lmingw32 -lSDL2main -lSDL2

all:	${FILES_O}
	${CC} -o Shooter.exe ${FILES_O} ${P4TH} ${LIBS}

${FILES_O}:
	${CC} -c ${FILES_C} -o $@
	