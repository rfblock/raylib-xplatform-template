OS := $(shell uname)
HOST_PLATFORM := unknown
PLATFORM := PLATFORM_DESKTOP
PLATFORM_SHELL := shell

ifeq ($(HOST_PLATFORM),unknown)
	ifeq ($(OS),Windows_NT)
		HOST_PLATFORM := windows
	else
		HOST_PLATFORM := linux
	endif
endif

OBJ_DIR_PARENT   := ../obj
BUILD_DIR_PARENT := ../build

OBJ_DIR   := $(OBJ_DIR_PARENT)/$(HOST_PLATFORM)
BUILD_DIR := $(BUILD_DIR_PARENT)/$(HOST_PLATFORM)
LIB_DIR   := ../lib/$(HOST_PLATFORM)
DEPS_DIR  := ../deps

SRCS := $(shell find . -name "*.c")
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)

ABS_LIB_DIR := $(realpath $(LIB_DIR))

LIBRAYLIB := libraylib.a

CC := gcc

CFLAGS := -I$(LIB_DIR) -L$(LIB_DIR) -l:$(LIBRAYLIB) -lm

ifeq ($(HOST_PLATFORM),windows)
	CFLAGS += -lopengl32 -lgdi32 -lwinmm
endif

.PHONY: help run raylib clean cleanall

help:
	@echo "make <command>"
	@echo " - help: This message"
	@echo " - run: Build and run"
	@echo " - raylib: Build raylib (requires rebuilding when switching between OS's)"
	@echo " - clean: Remove objects"
	@echo " - clean: Remove objects and builds"

main: $(OBJS) | $(OBJ_DIR) $(BUILD_DIR)
	@echo $(SRCS)
	$(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS)

run: main
	$(BUILD_DIR)/main

raylib: $(LIBRAYLIB)

$(LIBRAYLIB): | $(LIB_DIR)
# raylib needs to be cleaned when recompiling for a different OS
	$(MAKE) -C $(DEPS_DIR)/raylib/src clean
	$(MAKE) -C $(DEPS_DIR)/raylib/src PLATFORM=$(PLATFORM) RAYLIB_RELEASE_PATH=$(ABS_LIB_DIR)
	cp $(DEPS_DIR)/raylib/src/raylib.h $(LIB_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIB_DIR) $(OBJ_DIR) $(BUILD_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR_PARENT)

cleanall: clean
	$(RM) -r $(BUILD_DIR_PARENT)