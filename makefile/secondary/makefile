







LIBS=foo.gao bar.gao
.INTERMEDIATE:$(LIBS)
.SECONDARY:bar.gao

submake := "sub makefile"
all-submake:
	@echo $(submake)
	@echo makefiles is $(MAKEFILES)
	@echo makeflags is $(MAKEFLAGS)

all: $(LIBS)

foo.gao:
	gcc -c a.c -o $@
	@echo $@
	touch $@

bar.gao:
	@echo $@
	touch $@　


