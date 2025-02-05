# install locations
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

# variables used during build
PLATFORM = linux
ARCH = x86_64
CFLAGS_OLD = -g -std=c23 \
	-Wall \
	-Werror \
	-Wextra \
 	-Iinclude \
 	-Wno-unused-parameter \
 	-Wmultichar \
 	-Wno-four-char-constants \
	-pedantic \
 	-D_XOPEN_SOURCE=800
CFLAGS = -g -std=c23 \
	-Wall \
	-Werror \
	-Wextra \
 	-Iinclude \
 	-Wno-unused-parameter \
	-pedantic \
 	-D_XOPEN_SOURCE=800
LDFLAGS =
LIBS = -lm

# commands used by the build script
CC = cc
GCC = gcc
CLANG = clang
AS = as
LD = ld

# build locations
CACHE = .cache
BINOUT = .bin

# variables that will be embedded in the binary with -D definitions
DEFAULT_TARGET = $(ARCH)
VERSION = $$(./scripts/version)