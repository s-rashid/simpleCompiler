#include <iostream>
using namespace std;

#include "scapescompiler.h"
#include "parser.h"
/**
 * @brief ScapesCompiler::compile populates a program object with instruction, variable, and label objects
 * @return program, a program represented loaded in memory as objects
 * @param source, code as a string 
 */
void ScapesCompiler::compile(Program* program, QString source) {
    InstructionFactory factory;
    ProgramContext* context = new ProgramContext;

    Parser parser = Parser();
    QList<ParsedLine*> parsedLines;
    QList<QString> labelNames;

    parser.parse(source, parsedLines, labelNames);

    for(int l=0; l<labelNames.size(); l++) {
        context->addIdentifier(labelNames[l], new Label(labelNames[l]));
    }

    std::cout << "Compiling..." << std::endl;

    for(int l=0; l<parsedLines.size(); l++) {

        try {
            Instruction* instruc = factory.createInstruction(program, parsedLines[l]->getInstrucType(), false);
            if (!parsedLines[l]->getLabel().isEmpty()) {
                Label* label = dynamic_cast<Label*>(context->getIdentifier(parsedLines[l]->getLabel()));
                instruc->setLabel(label);
            }
            program->addInstruction(instruc);
            instruc->compile(context, parsedLines[l]->getOperands());

        } catch(SyntaxException& e) {
            QString line = parsedLines[l]->toQString();
            e.setLineNumber(l+1);
            e.setLine(line);
            e.process();
            throw;
        }
    }
    program->compile(context);
    qDeleteAll(parsedLines);
    parsedLines.clear();
    delete context;
    std::cout << "Compiling Done!" << std::endl;
}
