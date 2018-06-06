/* #ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>

extern "C" {
#include "myfunc.h"
}

TEST(fibonachiTest, num0) {
    ASSERT_EQ(fibonachi(0), 0);
    ASSERT_EQ(fibonachi(1), 1);
    ASSERT_EQ(fibonachi(2), 2);
}

TEST(fibonachiTest, greather2) {
    ASSERT_EQ(fibonachi(5), 5);
    ASSERT_EQ(fibonachi(10), 55);
}

TEST(fibonachiTest, negative) {
    ASSERT_EQ(fibonachi(-1), 0);
}

#endif // FIBONACHI_H
*/

#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


extern "C" {
#include "myfunc.h"
#include "common.h"
#include "text/text.h"
#include "text/_text.h"
}

#define OUTPUT 1
#define STDOUT 1



TEST (group_01, test1)
{
    text txt = create_text();
    ASSERT_EQ(pos_return(txt), 0);

}

TEST(group_01, test2)
{
     int fptr;
     int oldstdout;
     fptr = open("file.test",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
     oldstdout = dup(STDOUT);
     dup2(fptr,STDOUT);
     close(fptr);

     text txt = create_text();
     load(txt,(char *)"file.test");
     dup2(oldstdout,STDOUT);


     FILE *t;
     t = fopen("file.test","r");
     if(t == NULL){
            FAIL();
            return;
     }
     char *buf = (char*)malloc(sizeof(char)*512);
     int readcount = fread(buf,1,512,t);

     FILE *d;
     d =fopen("proverka.test","r");
     if(d == NULL){
            SUCCEED();
            return;
     }
     char *buf2 = (char*)malloc(sizeof(char)*512);
     int readcount2 = fread(buf2,1,512,d);
     fclose(t);
     fclose(d);
     ASSERT_EQ(readcount,readcount2);
}

void compare(char *originFile, char *producedFile) {
    char *file = (char *)malloc(sizeof(char)*1024);
    sprintf(file, "%s/%s", INPUTDIR, originFile);

    int fdOrigin = open(file, O_RDONLY);
    ASSERT_NE(fdOrigin, -1);

    int fdProduced = open(producedFile, O_RDONLY);
    ASSERT_NE(fdProduced, -1);

    char *bufferOrigin =(char *) malloc(512);
    char *bufferProduced =(char *) malloc(512);

    int readOrigin = 0;
    int readProduced = 0;
    do {
        readOrigin = read(fdOrigin, bufferOrigin, 512);
        readProduced = read(fdProduced, bufferProduced, 512);

        ASSERT_EQ(readOrigin, readProduced);

        for (int i = 0; i < readOrigin; i++) {
            ASSERT_EQ(bufferOrigin[i], bufferProduced[i]);
        }
    } while (readOrigin > 0);

    free(bufferOrigin);
    close(fdOrigin);
    close(fdProduced);
}

TEST(group2, test1){

    int fptr;
    int oldstdout;
    fptr = open("file.test",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
    oldstdout = dup(STDOUT);
    dup2(fptr,STDOUT);
    close(fptr);

    text txt = create_text();
    load(txt,(char *)"file.test");
    dup2(oldstdout,STDOUT);
   //howrev(txt);
    SUCCEED();
}
/*
TEST(group2, test2){
        char *file = (char *)malloc(sizeof(char)*1024);
        sprintf(file, "%s/text1.txt", INPUTDIR);

        //2.Создать файл для рез-та
        errno=0;
        int outFd = open("testOutput0.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
        if (outFd < 0)
            ASSERT_EQ(errno, 0);
        int oldOutput = dup(1);
        dup2(outFd, 1);
        ASSERT_EQ(errno, 0);
        close(outFd);


        //4.Запустить show_odd
        text txt = create_text();
        load (txt, file);
        showodd(txt);

        fflush(stdout);
        dup2(oldOutput, 1);
        //

        //5. Закрыть поток, открыть рез-т, сравнить с оригиналом
        SUCCEED();
}
TEST(group2, test3){
    char *file = (char *)malloc(sizeof(char)*1024);
    sprintf(file, "%s/text2.txt", INPUTDIR);

    //2.Создать файл для рез-та
    errno=0;
    int outFd = open("testOutput2.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
    if (outFd < 0)
        ASSERT_EQ(errno, 0);
    int oldOutput = dup(1);
    dup2(outFd, 1);
    ASSERT_EQ(errno, 0);
    close(outFd);


    //4.Запустить show_odd
    text txt = create_text();
    load (txt, file);
    showodd(txt);

    fflush(stdout);
    dup2(oldOutput, 1);

    compare((char *)"outputnoodd.txt",(char *) "testOutput2.txt");
}
TEST(group2, test4){
    char *file = (char *)malloc(sizeof(char)*1024);
    sprintf(file, "%s/text3.txt", INPUTDIR);

    //2.Создать файл для рез-та
    errno=0;
    int outFd = open("testOutput3.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
    if (outFd < 0)
        ASSERT_EQ(errno, 0);
    int oldOutput = dup(1);
    dup2(outFd, 1);
    ASSERT_EQ(errno, 0);
    close(outFd);


    //4.Запустить show_odd
    text txt = create_text();
    load (txt, file);
    showodd(txt);

    fflush(stdout);
    dup2(oldOutput, 1);

    compare((char *)"outputnoodd.txt",(char *) "testOutput3.txt");
}
*/
#endif // FIBONACHI_H
