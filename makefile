CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

SRC = assembler.c first_pass.c second_pass.c lexer.c preproc.c handle_text.c code_conversion.c table.c data_strct.c Errors.c util.c
OBJ = $(SRC:.c=.o)
DEPS = first_pass.h second_pass.h lexer.h preproc.h handle_text.h code_conversion.h table.h data_strct.h Errors.h util.h globals.h

assembler: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f assembler $(OBJ)

.PHONY: clean