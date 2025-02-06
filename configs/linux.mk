# install locations
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

# variables used during build
PLATFORM = linux
ARCH = x86_64
CFLAGS = -g -std=c23 -D_XOPEN_SOURCE=800 \
	-Iinclude \
	-w \
	-Wall \
	-Werror \
	-Wextra \
	-pedantic
CFLAGS_ = -g -std=c23 -D_XOPEN_SOURCE=800 \
	-Iinclude \
	-w \
	-Wall \
	-Werror \
	-Wextra \
 	-Wno-implicit-function-declaration \
 	-Wno-int-conversion \
	-pedantic
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