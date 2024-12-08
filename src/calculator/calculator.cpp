#include "calculator.h"

#include <functional>
#include <map>
#include <stdexcept>

std::map<char, std::function<void(CalculatorState&)>> operations_factory {
    {
        '+',
        [](CalculatorState& state) {state.screen_number = state.first_number + state.screen_number;}
    },
    {
        '-',
        [](CalculatorState& state) {state.screen_number = state.first_number - state.screen_number;}
    },
    {
        '*',
        [](CalculatorState& state) {state.screen_number = state.first_number * state.screen_number;}
    },
    {
        '/',
        [](CalculatorState& state) {state.screen_number = state.first_number / state.screen_number;}
    },
};

void HandlePressKey(char input_key, CalculatorState& state) {
    if ( isdigit(input_key) ) {
        int input_number = input_key - '0';
        if (state.start_new_number) {
            state.screen_number = input_number;
            state.start_new_number = false;
        } else {
            state.screen_number *= 10;
            state.screen_number += input_number;
        }
    } else if (input_key == '=') {
        if(state.op == 'n') throw std::invalid_argument("Invalid operation");
        operations_factory[state.op](state);
    } else {
        state.op = input_key;
        state.start_new_number = true;
    }

}

void CalculatorView::AppendInput(char input_char) {
    HandlePressKey(input_char, current_state);
}

std::string CalculatorView::GetOutput() const {
    return std::to_string(current_state.screen_number);
}
