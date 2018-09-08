
vpath %.h ./decode
vpath %.c ./decode

source = $(wildcard *.c)
source += decode.c
object = $(patsubst %.c,%.o,$(source))

include $(source:.c=.d)

all: print null main

main: $(object)
	@echo $^
	@echo $@
	gcc -o $@  $^

#decode/decode.o: decode/decode.c
null: decode/decode.c
	@echo $(@D)
	@echo $(@F)
	gcc -o decode/decode.o -c $^
	touch null

print:
	@echo $(source)

.PHONY: all clean depM depMM
clean:
	-rm -f main $(object)
depM:
	@gcc -M main.c
depMM:
	@gcc -MM main.c

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$


