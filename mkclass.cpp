/*
 * creates header and source files so you don't have to do so much on the console
 */
 
#include<iostream>
#include<sstream>
#include<fstream>

int main(int argc, char *argv[]){
	try{
		std::string filename = argv[1];
		std::string header = filename + ".h";
		std::string source = filename + ".cpp";
	
		std::ofstream file1;
		file1.open(header);
		file1.close();

		std::ofstream file2;
		file2.open(source);
		file2.close();

		std::cout << "created " << filename << " files" << std::endl;
		
	}catch(std::logic_error le){
		std::cout << "error: no file name provided" << std::endl;
	}

	return 0;
}

// TODO: make it so when we catch the exception we allow the user to enter a new file
// TODO: allow the user to enter in a list of files
// TODO: fill out the header files in the program
