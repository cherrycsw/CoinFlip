#ifndef DATACONFIG_H
#define DATACONFIG_H
#include<QMap>
#include<QVector>


class DataConfig
{
public:
    DataConfig();

    QMap<int,QVector<QVector<int>>> mData;//用于存储关卡配置的二维数组
};

#endif // DATACONFIG_H
