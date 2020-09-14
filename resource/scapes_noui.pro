QT -= gui
 
CONFIG += c++11 console
CONFIG -= app_bundle


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        controller/compileprogcontrol.cpp \
        controller/exitcontrol.cpp \
        controller/manageprogcontrol.cpp \
        controller/runprogcontrol.cpp \
        controller/savefilecontrol.cpp \
        main.cpp \
        program/addinstruction.cpp \
        program/basicoperandfactory.cpp \
        program/compareinstruction.cpp \
        program/compilationcontext.cpp \
        program/declareintegerinstruction.cpp \
        program/devenv.cpp \
        program/endinstruction.cpp \
        program/identifier.cpp \
        program/identifierfactory.cpp \
        program/identifierinuseexception.cpp \
        program/instruction.cpp \
        program/instructionfactory.cpp \
        program/integeroperand.cpp \
        program/integervariable.cpp \
        program/invalidlineexception.cpp \
        program/invalidnumoperandsexception.cpp \
        program/jumpequalinstruction.cpp \
        program/jumpinstruction.cpp \
        program/jumplessinstruction.cpp \
        program/jumpmoreinstruction.cpp \
        program/label.cpp \
        program/labeloperand.cpp \
        program/literalintegeroperand.cpp \
        program/literalstringoperand.cpp \
        program/moveinstruction.cpp \
        program/operand.cpp \
        program/operandfactory.cpp \
        program/parsedline.cpp \
        program/parser.cpp \
        program/printinstruction.cpp \
        program/program.cpp \
        program/programdeserializer.cpp \
        program/readintegerinstruction.cpp \
        program/scapescompiler.cpp \
        program/syntaxexception.cpp \
        program/undeclaredvariableexception.cpp \
        program/unexpectedprogramendexception.cpp \
        program/unsupportedoperandexception.cpp \
        program/unsupportinstructionexception.cpp \
        program/validoperandtypes.cpp \
        program/valueoperand.cpp \
        program/variable.cpp \
        program/variableoperand.cpp \
        storage/storagecontrol.cpp \
        storage/storagemanager.cpp

HEADERS += \
    controller/compileprogcontrol.h \
    controller/exitcontrol.h \
    controller/manageprogcontrol.h \
    controller/runprogcontrol.h \
    controller/savefilecontrol.h \
    program/addinstruction.h \
    program/basicoperandfactory.h \
    program/compareinstruction.h \
    program/compilationcontext.h \
    program/compiler.h \
    program/declareintegerinstruction.h \
    program/devenv.h \
    program/endinstruction.h \
    program/identifier.h \
    program/identifierfactory.h \
    program/identifierinuseexception.h \
    program/instruction.h \
    program/instructionfactory.h \
    program/integeroperand.h \
    program/integervariable.h \
    program/invalidlineexception.h \
    program/invalidnumoperandsexception.h \
    program/jumpequalinstruction.h \
    program/jumpinstruction.h \
    program/jumplessinstruction.h \
    program/jumpmoreinstruction.h \
    program/label.h \
    program/labeloperand.h \
    program/literalintegeroperand.h \
    program/literalstringoperand.h \
    program/moveinstruction.h \
    program/operand.h \
    program/operandfactory.h \
    program/parsedline.h \
    program/parser.h \
    program/printinstruction.h \
    program/program.h \
    program/programdeserializer.h \
    program/readintegerinstruction.h \
    program/scapescompiler.h \
    program/syntaxexception.h \
    program/undeclaredvariableexception.cpp.autosave \
    program/undeclaredvariableexception.h \
    program/unexpectedprogramendexception.h \
    program/unsupportedoperandexception.cpp.autosave \
    program/unsupportedoperandexception.h \
    program/unsupportinstructionexception.h \
    program/validoperandtypes.h \
    program/valueoperand.h \
    program/variable.h \
    program/variableoperand.h \
    storage/storagecontrol.h \
    storage/storagemanager.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
