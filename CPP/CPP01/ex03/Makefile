# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo <flo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 13:50:09 by flo               #+#    #+#              #
#    Updated: 2024/07/15 15:17:12 by flo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable name
TARGET = weapon

# Source files
SRC = Weapon.cpp main.cpp HumanA.cpp HumanB.cpp

# Header files (if you have multiple header files, list them here)
HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp

# Default rule
all: $(TARGET)

# Rule to compile the target
$(TARGET): $(SRC) $(HEADERS)
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
