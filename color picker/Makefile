# COLOR PICKER

CC = @gcc -o

P4TH = -I../SDL2-core/include -L../SDL2-core/lib

LIBS = -lmingw32 -lSDL2main -lSDL2

EXE   = color_picker.exe
FILES = main.c

all:
	${CC} ${EXE} ${FILES} ${P4TH} ${LIBS}
	
run:
	@./${EXE}