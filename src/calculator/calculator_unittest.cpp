#include <filesystem>
#include <fstream>
#include "calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorUnitTest, NoInput) {
  CalculatorView calculator;

  EXPECT_EQ(calculator.GetOutput(), "0");
}

TEST(CalculatorUnitTest, SingleDigit) {
  CalculatorView calculator;
  calculator.AppendInput('5');

  EXPECT_EQ(calculator.GetOutput(), "5");
}

TEST(CalculatorUnitTest, SingleNumber) {
  CalculatorView calculator;
  calculator.AppendInput('5');
  calculator.AppendInput('6');
  calculator.AppendInput('2');

  EXPECT_EQ(calculator.GetOutput(), "562");
}

TEST(CalculatorUnitTest, SingleNumberAndOperation) {
  CalculatorView calculator;
  calculator.AppendInput('5');
  calculator.AppendInput('6');
  calculator.AppendInput('2');
  calculator.AppendInput('/');

  EXPECT_EQ(calculator.GetOutput(), "562");
}

TEST(CalculatorUnitTest, OperationNotDone) {
  CalculatorView calculator;
  calculator.AppendInput('1');
  calculator.AppendInput('2');
  calculator.AppendInput('+');
  calculator.AppendInput('9');
  calculator.AppendInput('7');

  EXPECT_EQ(calculator.GetOutput(), "97");
}

TEST(CalculatorUnitTest, SumNumbers) {
  CalculatorView calculator;
  calculator.AppendInput('5');
  calculator.AppendInput('8');
  calculator.AppendInput('2');
  calculator.AppendInput('+');
  calculator.AppendInput('9');
  calculator.AppendInput('3');
  calculator.AppendInput('6');
  calculator.AppendInput('=');

  EXPECT_EQ(calculator.GetOutput(), "1518");
}

TEST(CalculatorUnitTest, SumZero) {
  CalculatorView calculator;
  calculator.AppendInput('5');
  calculator.AppendInput('8');
  calculator.AppendInput('2');
  calculator.AppendInput('+');
  calculator.AppendInput('0');
  calculator.AppendInput('=');

  EXPECT_EQ(calculator.GetOutput(), "582");
}

TEST(CalculatorUnitTest, SubtractNumbers) {
  CalculatorView calculator;
  calculator.AppendInput('4');
  calculator.AppendInput('2');
  calculator.AppendInput('-');
  calculator.AppendInput('9');
  calculator.AppendInput('=');

  EXPECT_EQ(calculator.GetOutput(), "33");
}

TEST(CalculatorUnitTest, SubtractNumbersNegativeSign) {
  CalculatorView calculator;
  calculator.AppendInput('4');
  calculator.AppendInput('2');
  calculator.AppendInput('-');
  calculator.AppendInput('6');
  calculator.AppendInput('9');
  calculator.AppendInput('=');

  EXPECT_EQ(calculator.GetOutput(), "-27");
}

TEST(CalculatorUnitTest, MultiplyNumbers) {
  CalculatorView calculator;
  calculator.AppendInput('4');
  calculator.AppendInput('2');
  calculator.AppendInput('*');
  calculator.AppendInput('6');
  calculator.AppendInput('9');
  calculator.AppendInput('=');

  EXPECT_EQ(calculator.GetOutput(), "2898");
}

TEST(CalculatorUnitTest, DivideNumbers) {
  CalculatorView calculator;
  calculator.AppendInput('4');
  calculator.AppendInput('2');
  calculator.AppendInput('/');
  calculator.AppendInput('2');
  calculator.AppendInput('=');

  EXPECT_EQ(calculator.GetOutput(), "21");
}

TEST(CalculatorUnitTest, DivideNumbersRoundDown) {
  {
    CalculatorView calculator;
    calculator.AppendInput('4');
    calculator.AppendInput('2');
    calculator.AppendInput('/');
    calculator.AppendInput('6');
    calculator.AppendInput('9');
    calculator.AppendInput('=');

    EXPECT_EQ(calculator.GetOutput(), "0");
  }
  {
    CalculatorView calculator;
    calculator.AppendInput('6');
    calculator.AppendInput('9');
    calculator.AppendInput('/');
    calculator.AppendInput('4');
    calculator.AppendInput('2');
    calculator.AppendInput('=');

    EXPECT_EQ(calculator.GetOutput(), "1");
  }
  {
    CalculatorView calculator;
    calculator.AppendInput('1');
    calculator.AppendInput('0');
    calculator.AppendInput('0');
    calculator.AppendInput('/');
    calculator.AppendInput('3');
    calculator.AppendInput('=');

    EXPECT_EQ(calculator.GetOutput(), "33");
  }
}

