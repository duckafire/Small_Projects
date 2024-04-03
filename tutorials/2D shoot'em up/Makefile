CC = @gcc

FILES_C = main.c init.c input.c draw.c

P4TH = -I../!SDL2/include -L../!SDL2/lib
LIBS = -lmingw32 -lSDL2_image -lSDL2main -lSDL2

GAME = Shoot-em_up.exe

all:
	${CC} -o ../!Build/${GAME} ${FILES_C} ${P4TH} ${LIBS}
	
run:
	@cd ../!Build && ${GAME}
