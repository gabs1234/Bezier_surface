SRC = $(src/wildcard *.cpp)

LDFLAGS = -lm

main: $(SRC)
	@$(CC) $(SRC) -o ./bin/main
