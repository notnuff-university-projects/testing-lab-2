#include "file_system_io.h"

#include <filesystem>
#include <fstream>

FileSystemIO::FileSystemIO() {
    TargetDirectory("./rsc");
    TargetInputFile("input.txt");
    TargetOutputFile("output.txt");
}

void FileSystemIO::Write(const std::string& text) {
    std::string separator = target_directory_.ends_with("/") ? "" : "/";
    std::string full_path = target_directory_ + separator + target_output_file_;

    if( !std::filesystem::exists(target_directory_) ) {
        throw std::runtime_error("Non-existing directory");
    }

    std::ofstream output_file(full_path, std::ios::out);

    if (!output_file.is_open()) {
        throw std::runtime_error("Unable to open or create file for writing");
    }

    output_file << text;
    output_file.close();
}

std::string FileSystemIO::Read() {
    std::string separator = target_directory_.ends_with("/") ? "" : "/";
    std::string full_path = target_directory_ + separator + target_input_file_;

    if( !std::filesystem::exists(full_path) ) {
        throw std::runtime_error("Non-existing file");
    }

    std::ifstream input_file(full_path);
    if (!input_file.is_open()) {
        throw std::runtime_error("Unable to open file for reading");
    }

    std::ostringstream buffer;
    buffer << input_file.rdbuf();

    input_file.close();

    return buffer.str();
}


std::string FileSystemIO::TargetDirectory() {
    return target_directory_;
}

void FileSystemIO::TargetDirectory(const std::string &new_target_dir) {
    target_directory_ = new_target_dir;
}

std::string FileSystemIO::TargetInputFile() {
    return target_input_file_;
}

void FileSystemIO::TargetInputFile(const std::string &new_input_file) {
    target_input_file_ = new_input_file;
}

std::string FileSystemIO::TargetOutputFile() {
    return target_output_file_;
}

void FileSystemIO::TargetOutputFile(const std::string &new_output_file) {
    target_output_file_ = new_output_file;
}
