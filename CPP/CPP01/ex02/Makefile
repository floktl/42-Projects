# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo <flo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 10:56:10 by flo               #+#    #+#              #
#    Updated: 2024/07/15 10:57:11 by flo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable name
TARGET = brain

# Source files
SRC = main.cpp

# Default rule
all: $(TARGET)

# Rule to compile the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean the build directory
clean:
	rm -f $(OBJ) all

# Full clean (remove all generated files)
fclean: clean
	rm -f $(NAME)

# Clean the build directory
clean:
	rm -f $(TARGET)

# Full clean (remove all generated files)
fclean: clean
	rm -f $(TARGET)

# Rule to clean and recompile
re: fclean all
