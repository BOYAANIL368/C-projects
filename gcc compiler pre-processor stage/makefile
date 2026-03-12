# single line comment
# target : all dependent object files
# system command to get target

CC = gcc
target = main.o rem_single_line.o rem_multi_line.o header_include.o macro_replace.o

project: ${target}
	${CC} ${target} -o project

main.o: main.c
	${CC} -c main.c

rem_single_line.o: rem_single_line.c
	${CC} -c rem_single_line.c

rem_multi_line.o: rem_multi_line.c
	${CC} -c rem_multi_line.c

header_include.o: header_include.c
	${CC} -c header_include.c

macro_repace.o: macro_replace.c
	${CC} -c macro_replace.c

clean:
	@echo "cleaning up...."
	@rm -f *.o project

