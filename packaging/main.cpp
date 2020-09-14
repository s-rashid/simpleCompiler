#include <QCoreApplication>
#include <QJsonDocument>
#include <iostream>

#include "./controller/compileprogcontrol.h"
#include "./controller/runprogcontrol.h"
#include "./controller/manageprogcontrol.h"
#include "./program/compiler.h"
#include "./program/scapescompiler.h"
#include "./program/program.h"
#include "./program/syntaxexception.h"
#include "./program/unsupportinstructionexception.h"
#include "./program/parser.h"

void parserTest(){

    QString str1 = "dci a\n"
                   "dci b\n"
                   "rdi a\n"
                   "jmp L1\n"
                   "end\n"
                   "prt a\n"
                   "L1: prt \"\\nprogramB\"\n"
                   "end";
    std::cout << "parsing" << std::endl;
    Parser p;
    QList<ParsedLine*> pl;
    QList<QString> labels;
    p.parse(str1, pl, labels);
}

void serializeTest(Program* program){
  QJsonObject programJson;
  program->write(programJson);
  QJsonDocument doc(programJson);
  QString strJson(doc.toJson(QJsonDocument::Indented)); //Indented for readability, Compact probably pretty in practice
  std::cout << strJson.toStdString()  << std::endl;
}

void noControlTest() {
    bool serialize = true;

    Compiler* compiler = new ScapesCompiler;

    Program* program = new Program("");
    QString str = "dci a\ndci b\nrdi a\nL1: prt a\nprt \"\\n\"\nend";
    compiler->compile(program, str);

    program->launch();

    if(serialize) serializeTest(program);

    delete compiler;
    delete program;
}

void controlTest() {
    //ScapesControl control;
    ManageProgramControl control;
    QString fileName1 = "str1.txt";
    QString fileName2 = "str2.txt";
    QString str1 = "dci a\n"
                   "dci b\n"
                   "rdi a\n"
                   "jmp L1\n"
                   "end\n"
                   "prt a\n"
                   "L1: prt \"programB\"\n"
                   "end";

    QString str2 = "dci a\n"
                   "dci b\n"
                   "dci b\n"
                   "rdi a\n"
                   "cmp a 2\n"
                   "jmr L1\n"
                   "prt \"less\"\n"
                   "end\n"
                   "L1: prt \"more\"\n"
                   "cmp a 7\n"
                   "jmr L2\n"
                   "prt \"less\"\n"
                   "end\n"
                   "L2: prt \"more\"\n"
                   "end";

    QString unsupportedInstruction = "dci a\n"
                   "dcit b\n"
                   "dci b\n"
                   "rdi a\n"
                   "cmp a 2\n"
                   "jmr L1\n"
                   "prt \"less\"\n"
                   "end\n"
                   "L1: prt \"more\"\n"
                   "cmp a 7\n"
                   "jmr L2\n"
                   "prt \"less\"\n"
                   "end\n"
                   "L3: prt \"more\"\n"
                   "end";

    QString unsupportedOperand1 = "dci a\n"
                   "dci &b\n"
                   "dci b\n"
                   "rdi a\n"
                   "cmp a 2\n"
                   "jmr L1\n"
                   "prt \"less\"\n"
                   "end\n"
                   "L1: prt \"more\"\n"
                   "cmp a 7\n"
                   "jmr L2\n"
                   "prt \"less\"\n"
                   "end\n"
                   "L3: prt \"more\"\n"
                   "end";

    QString unsupportedOperand2 = "dci a\n"
                   "dci b\n"
                   "dci b\n"
                   "rdi a\n"
                   "cmp a 2\n"
                   "jmr L1\n"
                   "prt \"less\"\n"
                   "end\n"
                   "L1: prt \"more\"\n"
                   "cmp &a 7\n"
                   "jmr L2\n"
                   "prt \"less\"\n"
                   "end\n"
                   "L3: prt \"more\"\n"
                   "end";

    QString invalidNumOperands1 = "dci a\n"
                   "dci b c a\n"
                   "dci b\n"
                   "rdi a\n"
                   "cmp a 2\n"
                   "jmr L1\n"
                   "prt \"less\"\n"
                   "end\n"
                   "L1: prt \"more\"\n"
                   "cmp &a 7\n"
                   "jmr L2\n"
                   "prt \"less\"\n"
                   "end\n"
                   "L3: prt \"more\"\n"
                   "end";

    control.compileProgram(str2, fileName1);
    control.runProgram();
    //control.compileProgram(invalidNumOperands1, fileName2);
    control.runProgram();
    control.runProgram();

    control.exitProgram();

    // ScapesControl newControl;
    // supposed to fail as program was cleaned up by .cleanUp()
    // newControl.launchProgram();
}

int main() {

//    cout << "tets" << endl;

//    QString str = "a";
//    QList<QString> list;
//    list.append(str);

//    Program* program = new Program("test");
//    program->addIdentifier(str, new IntegerVariable(str));


//    ValidOperandTypes* types= new ValidOperandTypes;
//    types->validateValueOperand();
//    OperandFactory factory(types);
//    factory.createOperand(program, str);
//    factory.createOperand(program, str);

//    Instruction* instruct = new ReadIntegerInstruction(program);
//    instruct->compile(list);

//    Instruction* instruct2 = new ReadIntegerInstruction(program);
//    instruct2->compile(list);


//    QString str1 = "rdi a\n"
//                   "rdi a";
//    std::cout << "parsing" << std::endl;
//    Parser p;
//    QList<ParsedLine*> pl;
//    QList<QString> labels;
//    p.parse(str1, pl, labels);

//    InstructionFactory iFactory;

//    for(int l=0; l<pl.size(); l++) {

//        try {
//            ReadIntegerInstruction* instruc = new ReadIntegerInstruction(program);
//            instruc->compile(pl[l]->getOperands());
//            program->addInstruction(instruc);

//        } catch(SyntaxException& e) {
//            QString line = pl[l]->toQString();
//            e.setLineNumber(l+1);
//            e.setLine(line);
//            throw;
//        }
//    }

    //parserTest();
    controlTest();
    //noControlTest();
    /*
    QString dir = ".";
    QString fileName2 = "str2.txt";
    QString str1 = "dci a\n"
                   "dci b\n"
                   "rdi a\n"
                   "jmp L1\n"
                   "end\n"
                   "prt a\n"
                   "L1: prt \"programB\"\n"
                   "end";

    ScapesControl control;
    //control.saveProgram(fileName2, dir, str1);
    */

    cout << "end" << endl;
    return 0;
}
