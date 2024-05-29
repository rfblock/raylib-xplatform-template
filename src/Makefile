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
LIB_DIR   := ../lib
DEPS_DIR  := ../deps

SRCS := $(shell find . -name "*.c")
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)

ABS_LIB_DIR := $(realpath $(LIB_DIR))

LIBRAYLIB := libraylib.$(HOST_PLATFORM).a

CC := gcc

CFLAGS := -I$(LIB_DIR) -L$(LIB_DIR) -l:$(LIBRAYLIB) -lm

ifeq ($(HOST_PLATFORM),windows)
	CFLAGS += -lopengl32 -lgdi32 -lwinmm
endif

.PHONY: run raylib clean cleanall

main: $(OBJS) | $(OBJ_DIR) $(BUILD_DIR)
	@echo $(SRCS)
	$(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS)

run: main
	$(BUILD_DIR)/main

raylib: $(LIBRAYLIB)

$(LIBRAYLIB): | $(LIB_DIR)
# raylib needs to be cleaned when recompiling for a different OS
	$(MAKE) -C $(DEPS_DIR)/raylib/src clean
	$(MAKE) -C $(DEPS_DIR)/raylib/src PLATFORM=$(PLATFORM) RAYLIB_RELEASE_PATH=$(ABS_LIB_DIR) RAYLIB_LIB_NAME=raylib.$(HOST_PLATFORM)
	cp $(DEPS_DIR)/raylib/src/raylib.h $(LIB_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIB_DIR) $(OBJ_DIR) $(BUILD_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ_DIR_PARENT)

cleanall:
	$(RM) $(OBJ_DIR_PARENT)
	$(RM) $(BUILD_DIR_PARENT)