#include <iostream>
using namespace std;

#include "scapescompiler.h"
#include "parser.h"

void ScapesCompiler::compile(Program* program, QString source) {
    InstructionFactory factory;

    Parser parser = Parser();
    QList<ParsedLine*> parsedLines;
    QList<QString> labelNames;

    parser.parse(source, parsedLines, labelNames);

    int lineNumber = 0;

    for(int l=0; l<labelNames.size(); l++) {
        // TODO rethink lineNumber labels
        std::cout << "adding " << labelNames[l].toStdString() << std::endl;
        program->addIdentifier(labelNames[l], new Label(lineNumber, labelNames[l]));
    }

    std::cout << "Compiling..." << std::endl;

    for(int l=0; l<parsedLines.size(); l++) {

        try {
            Instruction* instruc = factory.createInstruction(program, parsedLines[l]->getInstrucType());
            if (!parsedLines[l]->getLabel().isEmpty()) {
                instruc->setLabel(dynamic_cast<Label*>(program->getIdentifier(parsedLines[l]->getLabel())));
            }
            instruc->compile(parsedLines[l]->getOperands());
            lineNumber = program->addInstruction(instruc);

        } catch(SyntaxException& e) {
            QString line = parsedLines[l]->toQString();
            e.setLineNumber(l+1);
            e.setLine(line);
            throw;
        }
    }
}
