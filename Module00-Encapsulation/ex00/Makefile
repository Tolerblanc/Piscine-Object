NAME = ex00.out

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
		
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re