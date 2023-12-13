a.out: pg.o
	$(CC) -o $@ $?
pg.o:pg.c
	$(CC) -c $?

frames.o:frames.c
	$(CC) -c $?




