OPT = -Wall

OBJS = main.o Program.o Instruction.o MoveInstruction.o Identifier.o Label.o Variable.o ScapesCompiler.o ServiceFactory.o

scapes.exe:	main.o $(OBJS)
	g++ $(OPT) -o scapes.exe $(OBJS)

main.o:	../src/main.cc
	g++ $(OPT) -c ../src/main.cc

Instruction.o: ../src/program/model/Instruction.cc ../src/program/model/Instruction.h
	g++ $(OPT) -c ../src/program/model/Instruction.cc

MoveInstruction.o: ../src/program/model/MoveInstruction.cc ../src/program/model/MoveInstruction.h
	g++ $(OPT) -c ../src/program/model/MoveInstruction.cc

Program.o: ../src/program/Program.cc ../src/program/Program.h
	g++ $(OPT) -c ../src/program/Program.cc

Identifier.o: ../src/program/model/Identifier.cc ../src/program/model/Identifier.h
	g++ $(OPT) -c ../src/program/model/Identifier.cc

Label.o: ../src/program/model/Label.cc ../src/program/model/Label.h
	g++ $(OPT) -c ../src/program/model/Label.cc

Variable.o: ../src/program/model/Variable.cc ../src/program/model/Variable.h
	g++ $(OPT) -c ../src/program/model/Variable.cc

ScapesCompiler.o: ../src/program/ScapesCompiler.cc ../src/program/ScapesCompiler.h ../src/program/Compiler.h
	g++ $(OPT) -c ../src/program/ScapesCompiler.cc

ServiceFactory.o: ../src/ServiceFactory.cc ../src/ServiceFactory.h
	g++ $(OPT) -c ../src/ServiceFactory.cc

run:
	./scapes.exe

clean:
	rm -f $(OBJS) scapes.exe

test:
	./scapes.exe

valgrind:
	valgrind ./scapes.exe
