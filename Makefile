SRC := $(wildcard src/*.cpp)
HEADERS := $(wildcard src/*.hpp)

OUTPUT := bin/main
LDFLAGS := -lm

main: $(SRC) $(HEADERS)
	@g++ $(SRC) -o $(OUTPUT) $(LDFLAGS)