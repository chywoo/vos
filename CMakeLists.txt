CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT( KernelProject )

AUX_SOURCE_DIRECTORY( . test_source )
ADD_EXECUTABLE( kernel ${test_source} kernel.h syscall.h )
