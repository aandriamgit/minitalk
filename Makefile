NAME = client

NAMETWO = server

NAMEB = client_bonus

NAMETWOB = server_bonus

CFLAGS = -Werror -Wall -Wextra -g

RM = rm -rf

SRCS = client.c \
			 ./lib/ft_atoi.c \
			 ./lib/utilities.c \
			 ./lib/sig_handler.c \

SRCSTWO = server.c \
				./lib/ft_atoi.c \
			 ./lib/utilities.c \

SRCSB = ./bonus/client_bonus.c \
		./bonus/lib_bonus/ft_atoi.c \
		./bonus/lib_bonus/utilities.c \
		./bonus/lib_bonus/sig_handler.c \

SRCSTWOB = ./bonus/server_bonus.c \
		   ./bonus/lib_bonus/ft_atoi.c \
		   ./bonus/lib_bonus/utilities.c \

OBJS = $(SRCS:.c=.o)
OBJSTWO = $(SRCSTWO:.c=.o)
OBJSB = $(SRCSB:.c=.o)
OBJSTWOB = $(SRCSTWOB:.c=.o)

$(NAME) $(NAMETWO) : $(OBJSTWO) $(OBJS)
				cc $(CFLAGS) $(OBJS) -o $(NAME)
				cc $(CFLAGS) $(OBJSTWO) -o $(NAMETWO)

$(NAMEB) $(NAMETWOB) : $(OBJSTWOB) $(OBJSB)
				cc $(CFLAGS) $(OBJSB) -o $(NAMEB)
				cc $(CFLAGS) $(OBJSTWOB) -o $(NAMETWOB)

all : $(NAME) $(NAMETWO)

bonus : $(NAMEB) $(NAMETWOB) 

fclean : clean
	$(RM) $(NAMETWO) $(NAME) $(NAMEB) $(NAMETWOB)

clean :
	$(RM) $(OBJS) $(OBJSTWO) $(OBJSB) $(OBJSTWOB)

re : fclean all
