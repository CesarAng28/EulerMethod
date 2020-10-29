CC = gcc
CFLAGS = -lm -I -Wall
DEPS = model.h view.h controller.h test_bungee.h
OBJ = test_bungee.o model.o view.o controller.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_bungee: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(shell bash countFiles.sh)

clean:
	rm *.o