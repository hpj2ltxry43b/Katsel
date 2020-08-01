#include <iostream>
#include <fstream>

#include "lexer.h"
#include "parser.h"

std::string readFile(char *filename)
{
    std::ifstream filein;
    filein.open(filename);

    if (filein.is_open())
    {
        std::string contents;

        filein.seekg(0, std::ios::end);
        contents.resize(filein.tellg());

        filein.seekg(0, std::ios::beg);
        filein.read(&contents[0], contents.size());

        filein.close();
    
        return contents;
    }
    else
    {
        std::cerr << "Could not open file" << std::endl;
        return nullptr;
    }
}

void compileFile(char *filename)
{
    std::string source (readFile(filename));

    Lexer lexer (source);
    Parser parser (lexer);

    parser.expression();

    // int returnCode = parse(source);

    // if (returnCode != 0)
    // {
    //     exit(returnCode);
    // }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        // Compile file
        compileFile(argv[1]);
    }
    else
    {
        std::cerr << "Usage: " << argv[0] << " <file>\n"
            "\n"
            "file - the main file to compile\n" << std::endl;
        return 1;
    }
    return 0;
}
