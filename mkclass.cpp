#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<locale>

std::string toUpper(std::string original){
	std::string temp = "";
	std::locale loc;;

	for(std::string::size_type i = 0; i < original.length(); i++){
		temp += std::toupper(original[i], loc);
	}

	return temp;

}

int main(int argc, char *argv[]){
	
	// building full list
	char* files[argc-1];
	int currentPosition = 0;

	for(int i = 1; i < argc; i++){
		std::string filename = argv[i];
		std::string header = filename + ".h";
		std::string source = filename + ".cpp";
	
		std::ofstream file1;
		file1.open(header);
		
		// filling out the header
		file1 << "#ifndef " << toUpper(filename) << "_H_\n";
		file1 << "#define " << toUpper(filename) << "_H_\n";
		file1 << "class " << filename << "{\nprivate:\npublic:\n\t" << filename << "();\n\tvirtural ~" << filename << "();\n};\n\n";
		file1 << "#endif\n";
		file1.close();
		
		std::ofstream file2;
		file2.open(source);
		
		// filling out the source file
		file2 << "#include \"" << header << "\"\n\n";
		file2 << filename << "::" << filename << "(){}\n";
		file2 << filename << "::~" << filename << "(){}\n\n";

		file2.close();
	}	
	

	return 0;
}
