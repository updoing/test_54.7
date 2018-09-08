
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

.PHONY: all clean depM depMM autov
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


nullstring := #
space := $(nullstring)#

autov:
	@echo aaaaaa$(space)aaaaa


foo = $(bar)
bar = $(ugh)
ugh = Huh?

hehe:
	@echo $(foo)


dire := /foo/bar	# directory to put the frobs in
pdire:
	@echo aaaaaa$(dire)aaaaa

space := 
pspace:
	@echo aaaaa$(space)aaaaaa


nullstring :=
space := $(nullstring) # end of the line


FOO ?= bar

ifeq ($(origin FOO), undefined)
	FOO = bar
endif

foo := a.o b.o c.o
bar := $(foo:.o=.c)
pbar:
	@echo $(bar)

variable := value
variable += more
pvar:
	@echo $(variable)



foo := a.o b.o c.o
bar := $(foo:.o=.c)
define star
echo $(foo)
echo $(bar)
endef

pstar:
	@echo $(star)
	
	#@echo hello world
	@echo hhahha

command := "we are commands."

pcommand:
	@echo $(command)
	@#@echo hello world

exec:
	@cd decode; 
	pwd


submake := "test"
#export submake
subsystem:
	@pwd
	cd secondary && $(MAKE)
	@pwd


sub-dirs :=
sub-dirs += secondary
subdir: $(sub-dirs)
	@for dir in $(sub-dirs); do \
		make -C $$dir all; \
		ret=$$?; \
		echo ret is $$ret; \
		if [ ! $$ret -eq 0 ]; then \
			exit $$ret; \
		fi; \
	done;


#sources_test = foo.c bar.c
#ifneq ( $(MAKECMDGOALS),clean)
#include $(sources_test:.c=.d)
#endif


.PHONY: all
all: prog1 prog2 prog3 prog4

ret := $(subst ee,EE,feet on the street)
ret := $(patsubst %.c,%.o,x.c.c bar.c)
func:
	@echo $(ret)



reverse = $(1) $(2)
reverse = $(2) $(1)
foo = $(call reverse,aaa,ddb)

call:
	@echo $(foo)


ifdef bletch
ifeq "$(origin bletch)" "environment"
bletch = barf, gag, etc.
endif
endif



示例一：
ifdef ERROR_001
	$(error error is $(ERROR_001))
endif

示例二：
ERR = $(error found an error!)
.PHONY: err
	err: ; $(ERR)


foo : foo.o bar.o
	cc –o foo foo.o bar.o $(CFLAGS) $(LDFLAGS)



foo.o : foo.c
	cc –c foo.c $(CFLAGS)
bar.o : bar.c
	cc –c bar.c $(CFLAGS)



