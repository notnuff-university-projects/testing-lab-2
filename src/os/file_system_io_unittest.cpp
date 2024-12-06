#include "file_system_io.h"

#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>

// helper function to create a file
void CreateFile(const std::string& path, const std::string& content) {
    std::ofstream ofs(path);
    if (!ofs) {
        throw std::runtime_error("Failed to create file: " + path);
    }
    ofs << content;
    ofs.close();
}


TEST(FileSystemIO, ReadExisting) {
    std::filesystem::create_directories("./test");
    CreateFile("./test/test-input.txt", "test-input-written");

    FileSystemIO fs;
    fs.TargetDirectory("./test");
    fs.TargetInputFile("test-input.txt");

    EXPECT_EQ(fs.Read(), "test-input-written");

    std::filesystem::remove("./test/test-input.txt");
    std::filesystem::remove_all("./test");
}

TEST(FileSystemIO, ReadNonExisting) {
    FileSystemIO fs;
    fs.TargetDirectory("./nonexistent-directory");
    fs.TargetInputFile("nonexistent.txt");

    // scary structure: test that exception is thrown and has certain message
    EXPECT_THROW({
        try {
            fs.Read();
        } catch( const std::runtime_error& e ) {
            // and this tests that it has the correct message
            EXPECT_STREQ( "Non-existing file", e.what() );
            throw;
        }
    }, std::runtime_error );

}

TEST(FileSystemIO, OverwriteExisting) {
    std::filesystem::create_directories("./test");
    CreateFile("./test/test-output.txt", "test-output");

    FileSystemIO fs;
    fs.TargetDirectory("./test");
    fs.TargetOutputFile("test-output.txt");
    fs.TargetInputFile("test-output.txt");

    fs.Write("test-output-rewritten");
    EXPECT_EQ(fs.Read(), "test-output-rewritten");

    std::filesystem::remove("./test/test-output.txt");
    std::filesystem::remove_all("./test");
}

TEST(FileSystemIO, WriteFailNonExistingDirectory) {
    FileSystemIO fs;
    fs.TargetDirectory("./nonexistent-directory");
    fs.TargetOutputFile("test-output.txt");

    EXPECT_THROW({
        try {
            fs.Write("test-output-rewritten");
        } catch( const std::runtime_error& e ) {
            // and this tests that it has the correct message
            EXPECT_STREQ( "Non-existing directory", e.what() );
            throw;
        }
    }, std::runtime_error );
}

// should just create new file
TEST(FileSystemIO, WriteNewNonExistingFile) {
    std::filesystem::create_directories("./test");
    EXPECT_FALSE( std::filesystem::exists("./test-output.txt") );

    FileSystemIO fs;
    fs.TargetDirectory("./test");
    fs.TargetOutputFile("test-output.txt");

    fs.Write("test-output");

    EXPECT_TRUE( std::filesystem::exists("./test-output.txt") );
    EXPECT_EQ(fs.Read(), "test-output");

    std::filesystem::remove("./test/test-output.txt");
    std::filesystem::remove_all("./test");
}

