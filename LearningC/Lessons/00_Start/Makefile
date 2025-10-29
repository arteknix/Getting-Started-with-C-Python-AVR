vim: noexpandtab: ts=8: softtabstop=8
#/*minimal Makefile*/
TARGET 	= testing_C
PRINTF 	= format_testing_C
ARGV 	= arg_testing_C

CC 	= gcc
            
$(TARGET):
	$(CC) minimal.c -o $(TARGET)
$(PRINTF):
	$(CC) minimal_ptintf.c -o $(TARGET)
$(ARGV):
	$(CC) minimal_w_args.c -o $(TARGET)

all:
	$(TARGET) $(PRINTF) $(ARGV)
mini:
	$(TARGET)
	./$(TARGET)
printf:
	$(PRINTF)
	./$(PRINTF)
argv:
	$(ARGV)
	./$(ARGV)

run: $(TARGET) $(PRINTF) $(ARGV)
	./$(TARGET)
	./$(PRINTF)
	./$(ARGV)


listfiles:
	ls -lAh
