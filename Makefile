CC = gcc
EXE_NAME = a.out

CFLAGS = -W -Wall -Wextra -Werror -pedantic
DEBUG_FLAGS = -ggdb3 -O0
RELEASE_FLAGS = -O3
IFLAGS = -Iinclude/
LDFLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image -lm


BUILD = build
DBG_BUILD_DIR = $(BUILD)/debug
HYB_BUILD_DIR = $(BUILD)/hybrid
REL_BUILD_DIR = $(BUILD)/release
SRC_DIR = src

ifneq "$(findstring debug, $(MAKECMDGOALS))" ""
	BUILD_DIR=$(DBG_BUILD_DIR)
	CFLAGS += $(DEBUG_FLAGS)
	CUSTOM_DEFINES=-DIS_DEBUG
else ifneq "$(findstring release, $(MAKECMDGOALS))" ""
	BUILD_DIR = $(REL_BUILD_DIR)
	CFLAGS += $(REL_FLAGS)
else
	BUILD_DIR = $(HYB_BUILD_DIR)
	CUSTOM_DEFINES=-DIS_DEBUG
endif


SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) $^ -c -o $@

all: $(EXE_NAME)

$(EXE_NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXE_NAME)
	@echo "Done compiling $<"

clean:
	rm -f  $(DBG_BUILD_DIR)/*.o $(HYB_BUILD_DIR)/*.o $(REL_BUILD_DIR)/*.o $(EXE_NAME)

debug: all
hybrid: all
release: all
