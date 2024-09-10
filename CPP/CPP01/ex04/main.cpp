/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:43:10 by flo               #+#    #+#             */
/*   Updated: 2024/07/16 19:26:29 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iterator>

// Function to replace all occurrences of s1 with s2 in the given content
std::string repl_occ(std::string& cont, std::string& s1, std::string& s2)
{
	std::string				result;
	std::string::size_type	pos = 0;
	std::string::size_type	found;

	while ((found = cont.find(s1, pos)) != std::string::npos)
	{
		// Append part of the content before the found substring to the result
		result.append(cont, pos, found - pos);
		// Append the replacement substring to the result
		result.append(s2);
		pos = found + s1.length();
	}
	// Append the remaining part of the content after the last found substring
	result.append(cont, pos, std::string::npos);
	return (result);
}

// Function to handle the file actions for both the input and output files
void handle_files(std::string filename, std::string s1, std::string s2)
{
		std::string new_filename;

		std::ifstream infile(filename.c_str());
		if (!infile)
			throw std::runtime_error("Error: Cannot open input file.");
		// Read the entire content of the input file into a string
		std::string content((std::istreambuf_iterator<char>(infile)),
			std::istreambuf_iterator<char>());
		infile.close();

		new_filename = filename + ".replace";
		// Open the output file
		std::ofstream outfile(new_filename.c_str());
		if (!outfile)
			throw std::runtime_error("Error: Cannot open output file.");
		outfile << repl_occ(content, s1, s2);
		outfile.close();
		// Inform the user that the new file was created successfully
		std::cout << new_filename << " created successfully." << std::endl;
}

int main(int argc, char* argv[])
{
	// Argument check
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	try
	{
		// Call the function to handle file operations
		handle_files(filename, s1, s2);
	}
	catch (const std::exception& e)
	{
		//  what() returns a C-style character string (const char*) describing the exception.
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
