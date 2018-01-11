#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <QString>

#define FILE_LOG_NAME   "./a.log"

#define test_debug(msg)  debug_msg(__FILE__,__LINE__,msg)

void debug_msg(QString filename,int line,QString msg);

#endif // LOG_H
