.POSIX:

all:

include configs/linux.mk

all: $(BINOUT)/sl

C_DEFINES = \
	-DVERSION='"'"$(VERSION)"'"' \
	-DDEFAULT_TARGET='"$(DEFAULT_TARGET)"'

sources = $(wildcard src/*.c)
headers = $(wildcard src/include/*.h)
objects = $(patsubst %.c,$(CACHE)/%.o,$(shell ls src/*.c))

$(BINOUT)/sl: $(objects)
	@mkdir -p -- $(BINOUT)
	@printf 'CCLD\t%s\n' '$@'
	@$(CC) $(LDFLAGS) -o $@ $(objects) $(LIBS)

.SUFFIXES:
.SUFFIXES: .c .o .s

.PRECIOUS: %.s %.o

$(CACHE)/%.o: %.c $(headers)
	@mkdir -p -- $(dir $@)
	@printf 'CC\t%-16s --> ${CACHE}/%s\n' '$<' $(notdir $@)
	@$(CC) -c $(CFLAGS) $(C_DEFINES) -o $@ $(patsubst $(CACHE)/%.o,%.c,$@)

.s.o:
	@$(AS) $(ASFLAGS) -o $@ $<

install: $(BINOUT)/sl
	@install -dm755 $(DESTDIR)$(BINDIR)
	install -m755 $(BINOUT)/sl $(DESTDIR)$(BINDIR)/sl

uninstall:
	rm -rf -- '$(DESTDIR)$(BINDIR)/sl'

clean:
	@rm -rf -- $(CACHE) $(BINOUT) $(objects)

.PHONY: install uninstall clean