#include "compileprogcontrol.h"
/**
 * @brief CompilerProgramControl::compileProgram controls the flow of compilation
 * @param prompt, displays errors when needed
 * @param source, source code as a string
 * @param fileName, name of file to complie
 */
void CompilerProgramControl::compileProgram(UserDisplayPrompt* prompt, QString& source, QString fileName) {
    Program *program = new Program(fileName);
    Compiler *compiler = new ScapesCompiler;

    try {
        compiler->compile(program, source);
    } catch(SyntaxException& e) {
        const char* bytes = e.what();
        QString msg(bytes);
        prompt->displayCompileError(msg);
        delete program;
        delete compiler;
        return;
    }
    program->setFileName(fileName);

    serialize(program, fileName);
    delete compiler;
    prompt->displaySuccessfullCompileMsg(fileName);
}

/**
 * @brief CompilerProgramControl::serialize creates json objects from a Program object and saves it in a file
 * @param program, scapl code loaded in memory
 * @param fileName, flip of scapl to serialize
 */
void CompilerProgramControl::serialize(Program *program, QString& fileName) {

    QJsonObject programJson;
    program->write(programJson);
    QJsonDocument doc(programJson);
    QString strJson(doc.toJson(QJsonDocument::Indented)); //Indented for readability, Compact probably pretty in practice

    QStringList list = fileName.split('.');
    fileName = list.at(0)  + ".json";
    QString dir = ".";

    SaveFileControl fc;
    fc.saveProgram(fileName, dir, strJson);
}
