# +===========================+
# | Author: Alikadev          |
# | Version: 0.1              |
# |                           |
# | Desc: Test dumb lib       |
# |                           |
# | (May only work in my PC)  |
# +===========================+


# Project specific
CC		:=	gcc
D_SRC 	:=	src
D_BUILD	:=	build
LIB		:= 	../dumb.a


# Project + Computer Specific
CFLAGS	:=	-Ofast -std=c11 -Wno-unused-command-line-argument -fshort-enums
LDFLAGS	:=	-I../include $(LIB)


# Will auto-generate
TESTSRC	:=	$(shell find $(D_SRC) -name '*.c')
TESTS	:=	$(subst $(D_SRC), $(D_BUILD), $(TESTSRC:%c=%out))


# OS Specific
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CFLAGS+=-DOSX -I/opt/homebrew/include
	LDFLAGS+=-L/opt/homebrew/lib
endif
ifeq ($(UNAME_S),Linux)
	CFLAGS+=-DLINUX
	LDFLAGS+=
endif


# Implementation
all: clean $(TESTS)

$(D_BUILD)/%.out: $(D_SRC)/%.c
	@mkdir -p $(dir $@)
	@echo Building test $< to $@
	@$(CC) $< -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	@mkdir -p $(D_BUILD)
	@rm -rf $(D_BUILD)/*
