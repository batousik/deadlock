all: myapp

LDFLAGS+=libcl.a
LDFLAGS+= -lpthread

myapp: AES.o libcl.a
    $(CC) $^ $(LDFLAGS) -o $@

.depend: *.c
    $(CC) -M $< > $@

-include .depend
