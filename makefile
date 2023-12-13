a.out: frames.o
	$(CC) -o $@ $?
# pg.o:pg.c
# 	$(CC) -c $?

frames.o:frames.c
	$(CC) -c $?

# tlb.o:tlb.c
# 	$(CC) -c $?

