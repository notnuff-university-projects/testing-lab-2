# Laboratory work 2
##### by Yaroshenko Oleksandr Serhiyovych, IM-21
##### and Gundarev Rostyslav Oleksandrovych, IM-21
## Setup guide
to install all necessary packages to run the program, simply run the following command: 
```bash
sudo apt install gcc cmake libgtest-dev
```
## Run the app:
to run the app run the following command from root of project: 
```bash
cmake -S . -B build && cmake --build build && cd build && ./lab2 && cd ..
```
## Run the tests:
to run the app run the following command from root of project:

```bash
cmake -S . -B build && cmake --build build && cd build && ./tests-all && cd ..
```
or
```bash
cmake -S . -B build && cmake --build build && cd build && ctest && cd ..
```
