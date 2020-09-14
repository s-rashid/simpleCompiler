# SCAPES Project D1
# 2019-11-12
Team: 22-404 Team Name Not Found

To build:
source build

To run:
./scapes

All files will be stored in ./storage/
Examples:
./storage/exampleProgram1.scapes
./storage/exampleProgram2.scapes

Files for the Template Method

/program/instruction.h
/program/instruction.cpp

which has a compile() method
and all subclasses

/program/compareinstruction.h
/program/compareinstruction.cpp
/program/declareintegerinstruction.h
/program/declareintegerinstruction.cpp
/program/endinstruction.h
/program/endinstruction.cpp
/program/jumpinstruction.h
/program/jumpinstruction.cpp
/program/jumpmoreinstruction.h
/program/jumpmoreinstruction.cpp
/program/printinstruction.h
/program/printinstruction.cpp
/program/readintegerinstruction.h
/program/readintegerinstruction.cpp

who have a getOperandTypes() method
and optionally a precompile() method
