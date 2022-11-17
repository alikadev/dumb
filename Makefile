# +===========================+
# | Author: Alikadev          |
# | Version: 0.1.1            |
# |                           |
# | Desc: Create the dumb.a   |
# |                           |
# | (May only work in my PC)  |
# +===========================+


# Project specific
CC 			:= 	gcc
LINKER		:=	ar
D_INC		:= 	include
D_SRC		:=	src
D_BUILD		:=	build
D_TEST		:=	test
OUTPUT		:=	dumb.a


# Project + Computer Specific
CFLAGS		:=	-Ofast -std=c11 -Wno-unused-command-line-argument -fshort-enums -g
LDFLAGS 	:=
LINKFLAGS	:=	rcs


# Will auto-generate
SRC 		:=	$(shell find $(D_SRC) -name '*.c')
OBJS		:=	$(subst $(D_SRC), $(D_BUILD), $(SRC:%c=%o))


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
default: $(OUTPUT)
help:
	@echo "List of command:"
	@echo "  all     | Clean and build to .a lib"
	@echo "  clean   | Clean"
	@echo "  help    | Print this"
	@echo "  tests   | Build the test"
	@echo "  $(OUTPUT) = default"
	@exit 0

clean:
	@mkdir -p $(D_BUILD)
	@rm -rf $(D_BUILD)/*
	@rm -f $(OUTPUT)
	@$(MAKE) -C $(D_TEST) clean

tests:
	@$(MAKE) -C $(D_TEST) all
	@$(MAKE) -C $(D_TEST) test

all: clean $(OUTPUT)

$(OUTPUT): $(OBJS)
	@echo 
	@echo Linking sources to $@
	@$(LINKER) $(LINKFLAGS) $(OUTPUT) $(OBJS)

$(D_BUILD)/%.o: $(D_SRC)/%.c
	@mkdir -p $(dir $@)
	@echo Building $< to $@
	@$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@

