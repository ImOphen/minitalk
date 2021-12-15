GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

CFLAGS = -Wall -Werror -Wextra

CLIENT = client
SERVER = server

COMMON_FILES = ft_atoi.c ft_printf.c print_functions.c
SRC_CLIENT = $(COMMON_FILES) client.c
SRC_SERVER = $(COMMON_FILES) server.c
COBJ = $(SRC_CLIENT:%.c=%.o)
SOBJ = $(SRC_SERVER:%.c=%.o)

all : $(SERVER) $(CLIENT)

$(SERVER): $(SOBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)" "Compiling server"

$(CLIENT) : $(COBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)" "Compiling client"

%.o : %.c minitalk.h
	@$(CC) $(CFLAGS) $^ -c
	@echo "$(GREEN)" "Compiling $^"

clean:
	@rm -rf *.o *.gch
	@echo "$(RED)" "Cleaning..."

fclean : clean
	@rm -rf $(SERVER) $(CLIENT)
	@echo "$(RED)" "Full cleaning..."

re : fclean all
	@echo "$(YELLOW)" "Remaking"

