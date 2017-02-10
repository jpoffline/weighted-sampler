CC = g++ -std=c++0x

INC = -I/usr/local/include
LIBS = -L/usr/local/lib -lm

# Make rules

OBJECTMAIN = main.o 

.PHONY: all
all: main

main: $(OBJECTMAIN)
	$(CC) $(OBJECTMAIN) $(LIBS) -o ../$@

clean:
	-rm -rf $(OBJECTMAIN) ../main

%.o: ../src/%.cpp
	$(CC) -c $(INC) $< -o $@
