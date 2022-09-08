GCCFLAGS = -Wall -Werror -Wextra
RM = rm -rf	
EXECUTABLE_Q1 = ../build/Quest_1
EXECUTABLE_Q2 = ../build/Quest_2
EXECUTABLE_Q3 = ../build/Quest_3


.PHONY: clean door_struct list_test

door_struct: $(EXECUTABLE_Q1)

$(EXECUTABLE_Q1): dmanager_module.c
	gcc $(GCCFLAGS) -o $(EXECUTABLE_Q1) dmanager_module.c

list_test: $(EXECUTABLE_Q2)

$(EXECUTABLE_Q2): list_test.c list.c
	gcc $(GCCFLAGS) -o $(EXECUTABLE_Q2) list.c list_test.c


clean: 
	$(RM) $(EXECUTABLE_Q1) $(EXECUTABLE_Q2) $(EXECUTABLE_Q3)
	$(RM) *.o
