/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Выводит содержимое указанного файла на экран и нумерует
 */
void shownum(text txt);

/**
 * Выводит содержимое файла на экран в обратном порядке
 */

void showrev(text txt);

/**
 * Перемещает курсор на один символ влево
 */

void mcb(text txt);

/**
 * Удаляет последнюю строку
 */

void rt(text txt);


/**
 * Сохраняет в указанный файл
 */

void save(text txt,  char *f);
/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

#endif
