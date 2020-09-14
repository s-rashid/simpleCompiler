
#include "ServiceFactory.h"

Compiler* ServiceFactory::getCompilerInstance() {

  return new ScapesCompiler;
}
