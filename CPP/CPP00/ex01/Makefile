# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 15:14:34 by flo               #+#    #+#              #
#    Updated: 2024/09/11 15:39:55 by fkeitel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable name
TARGET = phonebook

# Source files
SRC = phonebook.cpp main.cpp Contact.cpp
# Header files (if you have multiple header files, list them here)
HEADERS = Phonebook.hpp Contact.hpp

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
