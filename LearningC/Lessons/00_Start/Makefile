#vim: noexpandtab: ts=8: softtabstop=8
#/*minimal Makefile*/
TARGET 	= testing_C
PRINTF 	= format_testing_C
ARGV 	= arg_testing_C

CC 	= gcc
            
$(TARGET): minimal.c
	$(CC) minimal.c -o $(TARGET)

$(PRINTF): minimal_printf.c
	$(CC) minimal_printf.c -o $(PRINTF)

$(ARGV): minimal_w_args.c
	$(CC) minimal_w_args.c -o $(ARGV)

.phony: help run listfiles

help:
	@echo "\033[01;43m" 
	@echo "you can make :"
	@echo "run, mini, printf, argv and listfiles"
	@echo "\033[00m" 

mini: $(TARGET)
	@echo "-------------"
	@echo target $@ running $<
	./$(TARGET)
	@echo "-------------"

printf:	$(PRINTF)
	@echo "-------------"
	@echo target $@ running $<
	./$(PRINTF)
	@echo "-------------"

argv: $(ARGV)
	@echo "-------------"
	@echo target $@ running $<
	./$(ARGV)
	@echo "-------------"

run: mini printf argv 

listfiles:
	ls -lAh
