OS := $(shell uname)
OS_SUBDIR := unknown

ifeq ($(OS),Windows_NT)
	OS_SUBDIR := windows
else
	OS_SUBDIR := linux
endif

ODIR_PARENT := ../obj
BDIR_PARENT := ../build

ODIR := $(ODIR_PARENT)/$(OS_SUBDIR)
BDIR := $(BDIR_PARENT)/$(OS_SUBDIR)
LDIR := ../lib
DDIR := ../deps

ABS_LDIR = $(realpath $(LDIR))

LIBRAYLIB := libraylib.$(OS_SUBDIR).a

CC := gcc

CFLAGS := -I$(LDIR) -L$(LDIR) -l:$(LIBRAYLIB) -lm

ifeq ($(OS),Windows_NT)
	CFLAGS += -lopengl32 -lgdi32 -lwinmm
endif

.PHONY: run raylib clean cleanall

main: $(ODIR)/main.o | $(ODIR) $(BDIR)
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS)

run: main
	$(BDIR)/main

raylib: $(LIBRAYLIB)

$(LIBRAYLIB): | $(LDIR)
# raylib needs to be cleaned when recompiling for a different OS
	$(MAKE) -C $(DDIR)/raylib/src clean
	$(MAKE) -C $(DDIR)/raylib/src PLATFORM=PLATFORM_DESKTOP RAYLIB_RELEASE_PATH=$(ABS_LDIR) RAYLIB_LIB_NAME=raylib.$(OS_SUBDIR)
	cp $(DDIR)/raylib/src/raylib.h $(LDIR)

$(ODIR)/%.o: %.c | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LDIR) $(ODIR) $(BDIR):
	echo $@
	mkdir -p $@

clean:
	rm -rf $(ODIR_PARENT)

cleanall:
	rm -rf $(ODIR_PARENT)
	rm -rf $(BDIR_PARENT)