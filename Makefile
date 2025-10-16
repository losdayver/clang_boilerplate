APP = bin/app
SRC_DIR = src
OBJ_DIR = obj
PKGCONF = conan
INCLUDE_DIR = include

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Пути и флаги от raylib через pkg-config
CFLAGS := -I$(INCLUDE_DIR) $(shell PKG_CONFIG_PATH=$(PKGCONF) pkg-config --cflags raylib 2>/dev/null)
LDFLAGS := $(shell PKG_CONFIG_PATH=$(PKGCONF) pkg-config --libs raylib 2>/dev/null)

# Conan окружение
CONAN_ENV = . $(PKGCONF)/conanbuild.sh

# ==== Правила ====
all: $(APP)

$(APP): $(OBJ)
	@mkdir -p $(dir $(APP))
	@echo "==> Linking $(APP)..."
	@$(CONAN_ENV) && gcc $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(APP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "==> Compiling $<"
	@$(CONAN_ENV) && gcc -c $< $(CFLAGS) -o $@

run: all
	@$(CONAN_ENV) && ./$(APP)

clean:
	rm -f $(APP) $(OBJ_DIR)/*.o