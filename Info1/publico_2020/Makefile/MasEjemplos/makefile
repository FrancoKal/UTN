################################################################
# AUTHOR INFORMATION #
################################################################

AUTHOR		= "Spataro, Hector"
CLASS		= "r1022/r1023/r1041/r1042"
TP		= "Sonido"
YEAR		= "2020"

################################################################
# COMPILER AND ARGUMENTS                                       #
################################################################

CC		= gcc
CFLAGS		= -c -Wall -Iinc
LDFLAGS		= -Wall
LIBS		=

################################################################
# SOURCES, HEADERS, OBJECTS AND EXECUTABLE                     #
################################################################

SRC_DIR		= src
LIBS_DIR	= libs
BUILD_DIR	= build
BIN_DIR		= bin

SOURCES		= Play.c Record.c Sound.c funciones.c
OBJSP		= funciones.o Play.o
OBJSR		= Record.o funciones.o
OBJSS		= Sound.o funciones.o
HEADERS		= funciones.h
PLAY		= Play
REC		= Record
SOUND		= Sound

################################################################
# TAR FILE INFORMATION                                         #
################################################################

FILE_NAME   = $(AUTHOR)-$(CLASS)-$(TP)-$(YEAR).tar.gz

################################################################
# MAKE TARGETS                                                 #
################################################################

.PHONY: all clean compress help

all: $(PLAY) $(REC) $(SOUND)

$(PLAY): $(BUILD_DIR)/$(OBJSP)
	@echo ''
	@echo '*****************************************************'
	@echo '---> $(PLAY)'
	@echo '---> Linking...'
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJSP) $(LDFLAGS) $(LIBS) -o $(BIN_DIR)/$@ -Wall
	@echo '---> Linking Complete!'
	@echo '*****************************************************'
	@echo ''

$(REC): $(OBJSR)
	@echo ''
	@echo '*****************************************************'
	@echo '---> $(REC)'
	@echo '---> Linking...'
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJSR) $(LDFLAGS) $(LIBS) -o $(BIN_DIR)/$@ -Wall
	@echo '---> Linking Complete!'
	@echo '*****************************************************'
	@echo ''

$(SOUND): $(OBJSS)
	@echo ''
	@echo '*****************************************************'
	@echo '---> $(SOUND)'
	@echo '---> Linking...'
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJSS) $(LDFLAGS) $(LIBS) -o $(BIN_DIR)/$@ -Wall
	@echo '---> Linking Complete!'
	@echo '*****************************************************'
	@echo ''

%.o: $(SRC_DIR)/%.c Makefile
	@echo ''
	@echo '*****************************************************'
	@echo '---> Compiling... $@ '
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $(BUILD_DIR)/$@
	@echo '---> Compiling Complete!'
	@echo '*****************************************************'
	@echo ''

clean:
	@echo ''
	@echo '*****************************************************'
	@echo '---> Cleaning...'
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo '---> Cleaning Complete!'
	@echo '*****************************************************'
	@echo ''

compress: $(SRC_DIR) Makefile 
	@echo ''
	@echo '*****************************************************'
	@echo '---> Packing...'
	tar -zcvf $(FILE_NAME) $(SRC_DIR) Makefile
	@echo '---> Packing Complete!'
	@echo '*****************************************************'
	@echo ''

help:
	@echo ''
	@echo '*****************************************************'
	@echo '  Uso:'
	@echo '    make all:		Compiles and Links'
	@echo '    make $(PLAY):		Compiles and Links program $(PLAY)'
	@echo '    make $(REC):	Compiles and Links program $(REC)'
	@echo '    make $(SOUND):		Compiles and Links program $(SOUND)'
	@echo '    make clean:		Removes objects and executable'
	@echo '    make compress:	Generates .tar.gz file'
	@echo '    make help:		Shows help'
	@echo '*****************************************************'
	@echo ''
