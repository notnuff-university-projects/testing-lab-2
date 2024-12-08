#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>

class CalculatorView {
  public:
    void AppendInput(char input_char);
    std::string GetOutput() const;
};



#endif //CALCULATOR_H
