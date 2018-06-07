include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES +=INPUTDIR=\\\"$$PWD\\\"

HEADERS +=     tst_test1.h \
    ../app/myfunc.h \
    fibonachi_test.h \
    ../app/common.h \
    ../app/text/text.h \
    ..app/text/_text.h \


SOURCES +=     main.cpp \
    ../app/myfunc.c \
    ../app/text/cursors.c \
    ../app/text/tracer.c \
    ../app/load.c \
    ../app/text/create_text.c \
    ../app/text/remove_all.c \
    ../app/text/append_line.c

INCLUDEPATH += ../app
