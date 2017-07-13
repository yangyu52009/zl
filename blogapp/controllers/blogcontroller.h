#ifndef BLOGCONTROLLER_H
#define BLOGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT BlogController :
        public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    BlogController() : ApplicationController() {}

public slots:
    void index();//展现全部的文章
    void show(const QString &id); //展现指定的一篇文章
    void create(); //新建一篇文章
    void save(const QString &id); //更新一篇文章
    void remove(const QString &id);  //删除一篇文章
};

#endif // BLOGCONTROLLER_H
