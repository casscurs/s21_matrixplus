#Makefile by Casscurs

# Цвета для оформления вывода
COLOR_TITLE = \033[1;36m
COLOR_SUCCESS = \033[1;32m
COLOR_RESET = \033[0m

NAME = s21_matrix_oop.a
SRC_FILES = $(wildcard *.cpp)
HEADER_FILES = $(wildcard *.hpp)
OBJ_FILES = $(patsubst %.cpp, %.o, $(SRC_FILES))
DEP_FILES = $(patsubst %.cpp, %.d, $(SRC_FILES))

TESTS_DIR = tests/
TESTS_SRC = $(wildcard $(TESTS_DIR)*.cpp)
TESTS_OBJ = $(patsubst %.cpp,%.o, $(TESTS_SRC))

CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic -g -fsanitize=address,undefined,unreachable -fno-sanitize-recover -fstack-protector

AR = ar rcs 
LIBS = -lgtest_main -lgtest -lpthread 
COVERAGE = 

all : $(NAME)

gcov_report : add_coverage test
	@echo "$(COLOR_TITLE)=== Running tests ===$(COLOR_RESET)"
	./test
	@echo "$(COLOR_TITLE)=====================$(COLOR_RESET)"
	mkdir -p report
	lcov -o report/test.info -c -d .
	genhtml -o report report/test.info
	open report/index.html
	@rm -rf *.gcda *.gcno

add_coverage :
	$(eval COVERAGE += --coverage)

test : $(NAME) $(TESTS_OBJ)
	$(CC) $(CFLAGS) -c $(TESTS_SRC)
	$(CC) $(COVERAGE) $(TESTS_OBJ) $(LIBS) $(NAME) -o $@

$(NAME) : $(OBJ_FILES)
	$(AR) $(NAME) $?
	@echo "$(COLOR_SUCCESS)=== Build complete ===$(COLOR_RESET)"

%.o : %.cpp
	@echo "$(COLOR_TITLE)=== Compiling $< ===$(COLOR_RESET)"
	$(CC) $(CFLAGS) $(COVERAGE) -c $< -o $@
	$(CC) $(CFLAGS) -MM -MF $(patsubst %.o, %.d, $@) $<
	@echo "$(COLOR_SUCCESS)=== Compilation successful ===$(COLOR_RESET)"

-include $(DEP_FILES)

leaks: test
	leaks -atExit -- ./test

clean :
	@echo "$(COLOR_TITLE)=== Cleaning ===$(COLOR_RESET)"
	@rm -rf *.a *.o report *.gcda *.gcno $(DEP_FILES) test


cppcheck :
	@echo "$(COLOR_TITLE)=== Running cppcheck ===$(COLOR_RESET)"
	cppcheck --enable=all --suppress=missingIncludeSystem $(TESTS_DIR)

format :
	@echo "$(COLOR_TITLE)=== Formatting code ===$(COLOR_RESET)"
	clang-format -i -style=Google $(SRC_FILES) $(HEADER_FILES)

check-format :
	@echo "$(COLOR_TITLE)=== Checking code formatting ===$(COLOR_RESET)"
	clang-format -n -style=Google $(SRC_FILES) $(HEADER_FILES)
	cpplint $(SRC_FILES) $(HEADER_FILES)

.PHONY : all gcov_report add_coverage test leaks clean cppcheck format check-format