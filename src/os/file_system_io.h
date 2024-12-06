#ifndef FILESYSTEMIO_H
#define FILESYSTEMIO_H

#include <string>

class FileSystemIO {
  public:
    // creates filesystem io object with default targets
    // target_directory - rsc
    // target_input_file - test-input.txt
    // target_output_file - test-output.txt
    FileSystemIO();

    // making those virtual,
    // so we could implement dependency injection in our tests
    virtual void Write(const std::string& text);
    virtual std::string Read();

    std::string TargetDirectory();
    void TargetDirectory(const std::string& new_target_dir);

    std::string TargetInputFile();
    void TargetInputFile(const std::string& new_input_file);

    std::string TargetOutputFile();
    void TargetOutputFile(const std::string& new_output_file);

  protected:
    std::string target_directory_;
    std::string target_input_file_;
    std::string target_output_file_;
};



#endif //FILESYSTEMIO_H
