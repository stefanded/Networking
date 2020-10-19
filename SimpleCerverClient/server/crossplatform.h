#define LIBRARY_CROSSPLATFORM_H
#ifdef LIBRARY_CROSSPLATFORM_H

#ifdef _WIN32
#include"wsocket.h"
#elif __linux__
#include"lsocket.h"

#endif
#endif
