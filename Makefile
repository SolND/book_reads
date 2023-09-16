# Biến
CXX = g++  # Compiler
CFLAGS = -Wall -I./include  # C Flags và đường dẫn đến thư mục chứa header files
LDFLAGS =  # Linker Flags

# Danh sách các tệp nguồn và tệp đối tượng
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
EXECUTABLE = $(BIN_DIR)/book_reads

# Quy tắc mặc định: Xây dựng chương trình
all: $(EXECUTABLE)

# Quy tắc biên dịch các tệp nguồn thành các tệp đối tượng
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CFLAGS) -c $< -o $@

# Quy tắc xây dựng chương trình từ các tệp đối tượng
$(EXECUTABLE): $(OBJ_FILES)
	@mkdir -p $(@D)
	$(CXX) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Phần dọn dẹp
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Mục tiêu giúp kiểm tra sự tồn tại của các thư mục
.PHONY: directories

# Tạo các thư mục nếu chưa tồn tại
directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Mục tiêu mặc định
.DEFAULT_GOAL := all
