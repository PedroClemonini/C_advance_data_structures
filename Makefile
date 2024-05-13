CC = clang
CFLAGS = -fsanitize=address -fprofile-generate -Wall -Wextra -Iinclude 
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
TARGET = code

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(wildcard $(INCLUDE_DIR)/*.h)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(BUILD_DIR)/$(TARGET)
	@$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean
