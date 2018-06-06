TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    myfunc.c \
    showrev.c \
    process_backward.c \
    text/cursors.c \
    text/tracer.c \
    text/create_text.c \
    showupfirst.c

HEADERS += \
    common.h \
    text/text.h \
    text/_text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
