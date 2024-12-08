#include <fstream>
#include <gtest/gtest.h>

#include "calculator/calculator.h"
#include "os/file_system_io.h"
#include "parser/parser.h"

int main(int argc, char **argv) {
    FileSystemIO fs;
    fs.TargetDirectory("./rsc");
    fs.TargetInputFile("test-input.txt");
    fs.TargetOutputFile("test-output.txt");

    auto parsedChars = parser::Parse( fs.Read() );

    CalculatorView calc;
    for(char parsed_char : parsedChars) calc.AppendInput( parsed_char );

    fs.Write( calc.GetOutput() );
}
