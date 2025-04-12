# Имя исполняемого файла
NAME = megaphone

# Компилятор и флаги
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Файлы
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

# Правило для сборки программы
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Правило для компиляции .cpp в .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка объектных файлов
clean:
	rm -f $(OBJS)

# Полная очистка (включая исполняемый файл)
fclean: clean
	rm -f $(NAME)

# Пересборка проекта
re: fclean all
