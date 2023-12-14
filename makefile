a.out: frames.o pg.o tlb.o mmu.o pg_table.o
	$(CC) -o $@ $?
pg.o:pg.c
	$(CC) -c $?

frames.o:frames.c
	$(CC) -c $?

tlb.o:tlb.c
	$(CC) -c $?

mmu.o:mmu.c
	$(CC) -c $?
pg_table.o:pg_table.c
	$(CC) -c $?

