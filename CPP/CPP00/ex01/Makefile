# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo <flo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 15:14:34 by flo               #+#    #+#              #
#    Updated: 2024/07/07 15:09:44 by flo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable name
TARGET = phonebook

# Source files
SRC = phonebook.cpp

# Header files (if you have multiple header files, list them here)
HEADERS = Phonebook.Class.hpp # Add any other headers you have, separated by spaces

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
