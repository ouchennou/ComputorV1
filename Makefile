CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
NAME = computor
SRC = main.cpp parser/Parser.cpp Polynomial/Polynomial.cpp
SRC_Header = parser/Parser.hpp Polynomial/Polynomial.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.cpp $(SRC_Header)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re