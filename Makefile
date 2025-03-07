# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retahri <retahri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 12:00:48 by retahri           #+#    #+#              #
#    Updated: 2025/02/08 20:01:01 by retahri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all: $(CLIENT) $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT): src/client.c src/utils.c
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): src/server.c src/utils.c
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_BONUS): src/client_bonus.c src/utils.c
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER_BONUS): src/server_bonus.c src/utils.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	
fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: clean all

bonus_re: clean bonus

.PHONY: all bonus clean re bonus_re