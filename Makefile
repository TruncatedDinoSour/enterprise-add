LIBS := -lcrypto
ifeq ($(NOQA),)
	CFLAGS += -std=c99 -Wall -Wextra -Wpedantic -pedantic -Wshadow -Werror -Wconversion -Wformat -Wuninitialized -Wmissing-prototypes -Wmissing-declarations -Wstrict-prototypes -Wredundant-decls -Wfloat-equal -Wcast-qual -Wnested-externs -Wvla -Winline -Wmissing-format-attribute -Wmissing-noreturn -pedantic-errors
endif

SRC_DIR := src
OBJ_DIR := obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

add: $(OBJ_FILES)
	$(CC) -o $@ $(CFLAGS) $(F_CFLAGS) $^ $(LIBS) $(LDFLAGS) $(F_LDFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/%.h | $(OBJ_DIR)
	$(CC) -c -o $@ $(CFLAGS) $< $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf add $(OBJ_DIR)

strip:
	strip --remove-section=.note.gnu.gold-version --remove-section=.note --remove-section=.gnu.version --remove-section=.eh_frame --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag --strip-symbol=__gmon_start__ --remove-section=.comment --remove-section=.eh_frame_ptr --strip-unneeded --strip-all --strip-debug --merge-notes --strip-dwo --discard-all --discard-locals --verbose add
