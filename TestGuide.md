# Socket-3-code Testing Guide

## Getting Started
To get the source code, clone the repository
```bash
git clone https://github.com/Fullstack-Alchemists-SJSU/socket3-code.git

cd socket3-code
```

## Running C++ Server/Client
C++ code uses `cmake` to build executables. We have divided payload, session and socket class files into `cmake` libraries.
Run the following commands to build the C++ project:
```bash
cd c++/session/src/payload
cmake -S . -B build
cd build
make

cd ../session
cmake -S . -B build
cd build
make

cd ../socket
cmake -S . -B build
cd build
make


cd ../../
cmake -S . -B build
cd build
make

#For Server
./Socket

#For Client
./Client
```

## Running Python Server/Client
Run the following commands to run Python server/client:
```bash
cd python-src

export PYTHONPATH=<path to current directory>

#For server
python3 basic/server.py

#For client
python3 basic/client.py
```
## Running Java Server/Client
Download and install [Intellij](https://www.jetbrains.com/idea/download/other.html) IDE.
Then simply run the files `src/ServerApp.java` for server and `src/ClientApp.java` for client.
