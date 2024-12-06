#include "parser.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(Parser, Simple) {
    std::string input = "4 + 2 = ";
    std::vector expected = {'4', '+', '2', '='};

    EXPECT_THAT( parser::Parse(input), testing::ContainerEq(expected) );
}

TEST(Parser, NoInput) {
    EXPECT_THAT( parser::Parse(""), testing::ElementsAre() );
}

TEST(Parser, IncorrectInputNoSpaces) {
    EXPECT_THROW({
        try {
            parser::Parse("445566");
        } catch( const std::runtime_error& e ) {
            EXPECT_STREQ( "Wrong format", e.what() );
            throw;
        }
    }, std::runtime_error );
}