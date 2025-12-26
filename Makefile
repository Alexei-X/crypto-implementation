# Nom de l'exécutable principal
TARGET = crypto_implementation
TEST_TARGET = test_runner

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./src
LDFLAGS = 
TEST_FLAGS = -lcunit

# Dossiers
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Exclure le fichier contenant 'main' pour éviter des conflits
MAIN_FILE = $(SRC_DIR)/main/main.c
SRC_FILES = $(filter-out $(MAIN_FILE), $(wildcard $(SRC_DIR)/**/*.c))
SRC_OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

TEST_FILES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/tests/%.o, $(TEST_FILES))

# Cible par défaut
all: $(BUILD_DIR)/$(TARGET)

# Cible pour l'application principale
$(BUILD_DIR)/$(TARGET): $(SRC_OBJ_FILES) $(BUILD_DIR)/main/main.o
	@mkdir -p $(dir $@)
	$(CC) $^ -o $@ $(LDFLAGS)

# Compilation des fichiers sources (hors fichier contenant `main`)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation du fichier contenant `main`
$(BUILD_DIR)/main/main.o: $(MAIN_FILE)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation des fichiers de test
$(BUILD_DIR)/tests/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Cible pour les tests
test: $(BUILD_DIR)/tests/$(TEST_TARGET)

$(BUILD_DIR)/tests/$(TEST_TARGET): $(TEST_OBJ_FILES) $(SRC_OBJ_FILES)
	@mkdir -p $(BUILD_DIR)/tests
	$(CC) $^ -o $@ $(TEST_FLAGS)
	$(BUILD_DIR)/tests/$(TEST_TARGET)

# Nettoyage des fichiers générés
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean test
