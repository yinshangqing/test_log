#include "log.h"
#include <QFile>
#include <QCoreApplication>
#include <QDateTime>
#include <QMutex>
#include <QMutexLocker>
QMutex mutex;
QString fmtCurrentTime(char* szFmt){
        QDateTime now = QDateTime::currentDateTime();
        return now.toString(szFmt);
}

bool appAppendFileLine(const QString& relativePath,const QString& line){
    //打开目标文件
    QMutexLocker locker(&mutex);
    QString str = QCoreApplication::applicationDirPath();
    str += relativePath;
    QFile fileTarget(str);
    if(!fileTarget.open(QIODevice::WriteOnly|QIODevice::Append))
        return false;
    fileTarget.write( line.toStdString().data() );
    fileTarget.write("\r\n");
    fileTarget.close();
    return true;

}

void debug_msg(QString filename,int line,QString msg)
{
    QString sline;
    sline.sprintf(" (%d) ",line);
    //去掉换行符
    QString trim_msg = msg;
    trim_msg = trim_msg.replace("\r","");
    trim_msg = trim_msg.replace("\n","");

    QString debug_msg;
    debug_msg = fmtCurrentTime("[hh:mm:ss] ") + filename + sline + trim_msg;
    appAppendFileLine(FILE_LOG_NAME,debug_msg);
}


