#include "compileprogcontrol.h"
/**
 * @brief CompilerProgramControl::compileProgram controls the flow of compilation
 * @param prompt, displays errors when needed
 * @param source, source code as a string
 * @param fileName, name of file to complie
 */
void CompilerProgramControl::compileProgram(DisplayErrorPrompt* prompt, QString& source, QString& fileName) {
    DevEnv *devEnv = DevEnv::getInstance();
    Program *program = new Program(fileName);
    Compiler *compiler = new ScapesCompiler;

    try {
        compiler->compile(program, source);
    } catch(SyntaxException& e) {
        delete program;
        delete compiler;
        QString msg = e.what();
        prompt->displayError(msg);
        return;
    }
    //save program in memory for later use
    program->setFileName(fileName);
    devEnv->setFilename(fileName);
    devEnv->setProgram(program);
    devEnv->setSource(source);

    serialize(program, program->getFileName());
    delete compiler;
}

/**
 * @brief CompilerProgramControl::serialize creates json objects from a Program object and saves it in a file
 * @param program, scapl code loaded in memory
 * @param fileName, flip of scapl to serialize
 */
void CompilerProgramControl::serialize(Program *program, QString fileName) {

    QJsonObject programJson;
    program->write(programJson);
    QJsonDocument doc(programJson);
    QString strJson(doc.toJson(QJsonDocument::Indented)); //Indented for readability, Compact probably pretty in practice

    QStringList list = fileName.split('.');
    QString serFileName = list.at(0)  + ".json";
    QString dir = ".";

    SaveFileControl fc;
    fc.saveProgram(serFileName, dir, strJson);
}
