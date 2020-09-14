#-------------------------------------------------
#
# Project created by QtCreator 2019-11-11T03:05:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = scapes
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        controller/compileprogcontrol.cpp \
        controller/exitcontrol.cpp \
        controller/manageprogcontrol.cpp \
        controller/runprogcontrol.cpp \
        controller/savefilecontrol.cpp \
	main_ui.cpp \
        program/compareinstruction.cpp \
        program/declareintegerinstruction.cpp \
        program/devenv.cpp \
        program/endinstruction.cpp \
        program/identifier.cpp \
    program/identifierinuseexception.cpp \
        program/instruction.cpp \
        program/instructionfactory.cpp \
        program/integeroperand.cpp \
        program/integervariable.cpp \
        program/invalidlineexception.cpp \
        program/invalidnumoperandsexception.cpp \
        program/jumpinstruction.cpp \
        program/jumpmoreinstruction.cpp \
        program/label.cpp \
        program/labeloperand.cpp \
        program/literalintegeroperand.cpp \
        program/literalstringoperand.cpp \
        program/operand.cpp \
        program/operandfactory.cpp \
        program/parsedline.cpp \
        program/parser.cpp \
        program/printinstruction.cpp \
        program/program.cpp \
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
        storage/storagemanager.cpp \
        ui/mainwindow.cpp

HEADERS += \
    \ \
    controller/compileprogcontrol.h \
    controller/displayerrorprompt.h \
    controller/exitcontrol.h \
    controller/manageprogcontrol.h \
    controller/runprogcontrol.h \
    controller/savefilecontrol.h \
    program/compareinstruction.h \
    program/compiler.h \
    program/declareintegerinstruction.h \
    program/devenv.h \
    program/endinstruction.h \
    program/identifier.h \
    program/identifierinuseexception.h \
    program/instruction.h \
    program/instructionfactory.h \
    program/integeroperand.h \
    program/integervariable.h \
    program/invalidlineexception.h \
    program/invalidnumoperandsexception.h \
    program/jumpinstruction.h \
    program/jumpmoreinstruction.h \
    program/label.h \
    program/labeloperand.h \
    program/literalintegeroperand.h \
    program/literalstringoperand.h \
    program/operand.h \
    program/operandfactory.h \
    program/parsedline.h \
    program/parser.h \
    program/printinstruction.h \
    program/program.h \
    program/readintegerinstruction.h \
    program/scapescompiler.h \
    program/syntaxexception.h \
    program/undeclaredvariableexception.h \
    program/unexpectedprogramendexception.h \
    program/unsupportedoperandexception.h \
    program/unsupportinstructionexception.h \
    program/validoperandtypes.h \
    program/valueoperand.h \
    program/variable.h \
    program/variableoperand.h \
    storage/storagecontrol.h \
    storage/storagemanager.h \
    ui/mainwindow.h

FORMS += \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
