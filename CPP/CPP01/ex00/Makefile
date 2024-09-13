# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 13:50:09 by flo               #+#    #+#              #
#    Updated: 2024/09/12 07:38:00 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable name
TARGET = zombie

# Source files
SRC = zombie.cpp newZombie.cpp randomChump.cpp

# Header files (if you have multiple header files, list them here)
HEADERS = Zombie.hpp # Add any other headers you have, separated by spaces

# Default rule
all: $(TARGET)

# Rule to compile the target
$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Rule to clean up generated files
clean:
	rm -f $(TARGET)

# Rule to clean and recompile
re: clean all
