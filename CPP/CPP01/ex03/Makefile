# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 13:50:09 by flo               #+#    #+#              #
#    Updated: 2024/09/12 08:32:26 by fkeitel          ###   ########.fr        #
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

# Header files
HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp

# Default rule
all: $(TARGET)

# Rule to compile the target
$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean the build directory
clean:
	rm -f $(TARGET)

# Full clean (remove all generated files)
fclean: clean
	rm -f $(TARGET)

# Rule to clean and recompile
re: fclean all
