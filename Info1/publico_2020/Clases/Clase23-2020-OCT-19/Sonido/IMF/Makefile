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

SOURCES		= Play.c Record.c Sound.c funciones.c Convert_a_imf.c Convert_a_raw.c
OBJSP		= $(BUILD_DIR)/funciones.o $(BUILD_DIR)/Play.o
OBJSR		= $(BUILD_DIR)/Record.o $(BUILD_DIR)/funciones.o
OBJSS		= $(BUILD_DIR)/Sound.o $(BUILD_DIR)/funciones.o
OBJSC1		= $(BUILD_DIR)/Convert_a_imf.o
OBJSC2		= $(BUILD_DIR)/Convert_a_raw.o
HEADERS		= funciones.h
PLAY		= $(BIN_DIR)/Play
REC			= $(BIN_DIR)/Record
SOUND		= $(BIN_DIR)/Sound
RAW			= $(BIN_DIR)/Conv_a_imf
IMF			= $(BIN_DIR)/Conv_a_raw

################################################################
# TAR FILE INFORMATION                                         #
################################################################

FILE_NAME   = $(AUTHOR)-$(CLASS)-$(TP)-$(YEAR).tar.gz

################################################################
# MAKE TARGETS                                                 #
################################################################

.PHONY: all clean compress help

all: $(PLAY) $(REC) $(SOUND) $(RAW) $(IMF)

$(PLAY): $(OBJSP)
	@echo ''
	@echo '*****************************************************'
	@echo '---> $(PLAY)'
	@echo '---> Linking...'
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJSP) $(LDFLAGS) $(LIBS) -o $@ -Wall
	@echo '---> Linking Complete!'
	@echo '*****************************************************'
	@echo ''

$(REC): $(OBJSR)
	@echo ''
	@echo '*****************************************************'
	@echo '---> $(REC)'
	@echo '---> Linking...'
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJSR) $(LDFLAGS) $(LIBS) -o $@ -Wall
	@echo '---> Linking Complete!'
	@echo '*****************************************************'
	@echo ''

$(SOUND): $(OBJSS)
	@echo ''
	@echo '*****************************************************'
	@echo '---> $(SOUND)'
	@echo '---> Linking...'
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJSS) $(LDFLAGS) $(LIBS) -o $@ -Wall
	@echo '---> Linking Complete!'
	@echo '*****************************************************'
	@echo ''

$(RAW): $(OBJSC2)
	@echo ''
	@echo '*****************************************************'
	@echo '---> $(RAW)'
	@echo '---> Linking...'
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJSC2) $(LDFLAGS) $(LIBS) -o $@ -Wall
	@echo '---> Linking Complete!'
	@echo '*****************************************************'
	@echo ''

$(IMF): $(OBJSC1)
	@echo ''
	@echo '*****************************************************'
	@echo '---> $(IMF)'
	@echo '---> Linking...'
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJSC1) $(LDFLAGS) $(LIBS) -o $@ -Wall
	@echo '---> Linking Complete!'
	@echo '*****************************************************'
	@echo ''

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@echo ''
	@echo '*****************************************************'
	@echo '---> Compiling... $@ '
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@
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
	@echo '    make $(RAW):		Compiles and Links program $(RAW)'
	@echo '    make $(IMF):		Compiles and Links program $(IMF)'
	@echo '    make clean:		Removes objects and executable'
	@echo '    make compress:	Generates .tar.gz file'
	@echo '    make help:		Shows help'
	@echo '*****************************************************'
	@echo ''
