# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malbrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 12:34:33 by malbrand          #+#    #+#              #
#    Updated: 2021/01/07 12:55:30 by malbrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
OBJ_DIR	= obj

GCC		= cc -Wall -Werror -Wextra

# Mémoire
SRC		+= src/mem/ft_memset.c
SRC		+= src/mem/ft_bzero.c
SRC		+= src/mem/ft_memcpy.c
SRC		+= src/mem/ft_memccpy.c
SRC		+= src/mem/ft_memmove.c
SRC		+= src/mem/ft_memchr.c
SRC		+= src/mem/ft_memcmp.c
SRC		+= src/mem/ft_calloc.c

# Chaînes de base
SRC		+= src/str/ft_strlen.c
SRC		+= src/str/ft_strdup.c
SRC		+= src/str/ft_strlcpy.c
SRC		+= src/str/ft_strlcat.c
SRC		+= src/str/ft_strchr.c
SRC		+= src/str/ft_strrchr.c
SRC		+= src/str/ft_strncmp.c
SRC		+= src/str/ft_strnstr.c

# Caractères
SRC		+= src/char/ft_isalpha.c
SRC		+= src/char/ft_isdigit.c
SRC		+= src/char/ft_isalnum.c
SRC		+= src/char/ft_isascii.c
SRC		+= src/char/ft_isprint.c
SRC		+= src/char/ft_toupper.c
SRC		+= src/char/ft_tolower.c

# Conversion
SRC		+= src/conv/ft_atoi.c
SRC		+= src/conv/ft_itoa.c

# Affichage
SRC		+= src/put/ft_putchar_fd.c
SRC		+= src/put/ft_putstr_fd.c
SRC		+= src/put/ft_putendl_fd.c
SRC		+= src/put/ft_putnbr_fd.c

# Chaînes avancées
SRC		+= src/str_extra/ft_substr.c
SRC		+= src/str_extra/ft_strjoin.c
SRC		+= src/str_extra/ft_strtrim.c
SRC		+= src/str_extra/ft_split.c
SRC		+= src/str_extra/ft_strmapi.c
SRC		+= src/str_extra/ft_striteri.c

# Bonus - Listes chaînées
SRCBON		+= src/lst/ft_lstnew.c
SRCBON		+= src/lst/ft_lstadd_front.c
SRCBON		+= src/lst/ft_lstsize.c
SRCBON		+= src/lst/ft_lstlast.c
SRCBON		+= src/lst/ft_lstadd_back.c
SRCBON		+= src/lst/ft_lstdelone.c
SRCBON		+= src/lst/ft_lstclear.c
SRCBON		+= src/lst/ft_lstiter.c
SRCBON		+= src/lst/ft_lstmap.c

OBJ		= $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

OBJBON	= $(addprefix $(OBJ_DIR)/,$(notdir $(SRCBON:.c=.o)))

INC		+= libft.h

all: $(NAME)
	@echo "✓ Everything is OK"

$(NAME): $(OBJ_DIR) $(OBJ) $(INC)
	@echo "📦 Creating library..."
	@ar rc $@ $(OBJ)
	@ranlib $@
	@echo "✓ Library created: $(NAME)"

bonus : $(OBJ_DIR) $(OBJ) $(OBJBON) $(INC)
	@echo "📦 Creating library with bonus..."
	@ar rc $(NAME) $(OBJ) $(OBJBON)
	@ranlib $(NAME)
	@echo "✓ Everything is OK (with bonus)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Règle générique pour compiler depuis n'importe quel sous-dossier
$(OBJ_DIR)/%.o: src/mem/%.c $(INC) | $(OBJ_DIR)
	@$(GCC) -I. -o $@ -c $<

$(OBJ_DIR)/%.o: src/str/%.c $(INC) | $(OBJ_DIR)
	@$(GCC) -I. -o $@ -c $<

$(OBJ_DIR)/%.o: src/char/%.c $(INC) | $(OBJ_DIR)
	@$(GCC) -I. -o $@ -c $<

$(OBJ_DIR)/%.o: src/conv/%.c $(INC) | $(OBJ_DIR)
	@$(GCC) -I. -o $@ -c $<

$(OBJ_DIR)/%.o: src/put/%.c $(INC) | $(OBJ_DIR)
	@$(GCC) -I. -o $@ -c $<

$(OBJ_DIR)/%.o: src/str_extra/%.c $(INC) | $(OBJ_DIR)
	@$(GCC) -I. -o $@ -c $<

$(OBJ_DIR)/%.o: src/lst/%.c $(INC) | $(OBJ_DIR)
	@$(GCC) -I. -o $@ -c $<

clean:
	@echo "🧹 Cleaning object files..."
	@rm -rf $(OBJ_DIR) 2>/dev/null || true
	@echo "✓ Clean done"

fclean: clean
	@echo "🧹 Cleaning library..."
	@rm -rf $(NAME) 2>/dev/null || true
	@echo "✓ Full clean done"

re: fclean all

.PHONY: clean fclean re bonus
