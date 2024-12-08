#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

struct CalculatorState {
    int screen_number = 0;
    int first_number = 0;
    char op = 'n';
    bool start_new_number = true;
};

class CalculatorView {
public:
    void AppendInput(char input_char);
    std::string GetOutput() const;

protected:
  CalculatorState current_state;
};



#endif //CALCULATOR_H
