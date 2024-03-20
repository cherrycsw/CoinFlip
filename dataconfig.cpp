#include "dataconfig.h"

DataConfig::DataConfig()
{
    //第一关金银币配置位置矩阵
    int arr1[4][4]={{1,1,1,1},
                    {1,1,0,1},
                    {1,0,0,0},
                    {1,1,0,1}};
    QVector<QVector<int>> v1;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr1[i][j]);
        }
        v1.push_back(v);
    }
    this->mData.insert(1,v1);

    //第二关金银币配置位置矩阵
    int arr2[4][4]={ {0, 1, 0, 1},
                     {1, 0, 0, 0},
                     {1, 0, 0, 0},
                     {0, 1, 0, 1}};
    QVector<QVector<int>> v2;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr2[i][j]);
        }
        v2.push_back(v);
    }
    this->mData.insert(2,v2);

    //第三关金银币配置位置矩阵
    int arr3[4][4]={{1, 0, 1, 1},
                    {1, 1, 0, 0},
                    {0, 0, 1, 1},
                    {1, 1, 0, 1}};
    QVector<QVector<int>> v3;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr3[i][j]);
        }
        v3.push_back(v);
    }
    this->mData.insert(3,v3);

    //第四关金银币配置位置矩阵
    int arr4[4][4]={{0, 1, 1, 1},
                    {1, 1, 0, 1},
                    {1, 0, 1, 1},
                    {1, 1, 1, 0}};
    QVector<QVector<int>> v4;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr4[i][j]);
        }
        v4.push_back(v);
    }
    this->mData.insert(4,v4);

    //第五关金银币配置位置矩阵
    int arr5[4][4]={{1, 0, 0, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {1, 0, 0, 1}};
    QVector<QVector<int>> v5;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr5[i][j]);
        }
        v5.push_back(v);
    }
    this->mData.insert(5,v5);

    //第六关金银币配置位置矩阵
    int arr6[4][4]={{1, 0, 0, 1},
                    {0, 1, 1, 0},
                    {0, 1, 1, 0},
                    {1, 0, 0, 1}};
    QVector<QVector<int>> v6;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr6[i][j]);
        }
        v6.push_back(v);
    }
    this->mData.insert(6,v6);

    //第七关金银币配置位置矩阵
    int arr7[4][4]={{0, 1, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 1, 1, 0}};
    QVector<QVector<int>> v7;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr7[i][j]);
        }
        v7.push_back(v);
    }
    this->mData.insert(7,v7);

    //第八关金银币配置位置矩阵
    int arr8[4][4]={{0, 1, 1, 0},
                    {1, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 1, 1, 0}};
    QVector<QVector<int>> v8;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr8[i][j]);
        }
        v8.push_back(v);
    }
    this->mData.insert(8,v8);

    //第九关金银币配置位置矩阵
    int arr9[4][4]={{0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}};
    QVector<QVector<int>> v9;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr9[i][j]);
        }
        v9.push_back(v);
    }
    this->mData.insert(9,v9);

    //第10关金银币配置位置矩阵
    int arr10[4][4]={{1,1,1,1},
                     {1,1,0,1},
                     {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>> v10;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr10[i][j]);
        }
        v10.push_back(v);
    }
    this->mData.insert(10,v10);

    //第11关金银币配置位置矩阵
    int arr11[4][4]={{1,1,1,1},
                     {1,1,0,1},
                     {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>> v11;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr11[i][j]);
        }
        v11.push_back(v);
    }
    this->mData.insert(11,v11);

    //第12关金银币配置位置矩阵
    int arr12[4][4]={{1,1,1,1},
                     {1,1,0,1},
                     {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>> v12;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr12[i][j]);
        }
        v12.push_back(v);
    }
    this->mData.insert(12,v12);

    //第13关金银币配置位置矩阵
    int arr13[4][4]={{1,1,1,1},
                     {1,1,0,1},
                     {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>> v13;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr13[i][j]);
        }
        v13.push_back(v);
    }
    this->mData.insert(13,v13);

    //第14关金银币配置位置矩阵
    int arr14[4][4]={{1,1,1,1},
                     {1,1,0,1},
                     {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>> v14;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr14[i][j]);
        }
        v14.push_back(v);
    }
    this->mData.insert(14,v14);

    //第15关金银币配置位置矩阵
    int arr15[4][4]={{1,1,1,1},
                     {1,1,0,1},
                     {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>> v15;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr15[i][j]);
        }
        v15.push_back(v);
    }
    this->mData.insert(15,v15);

    //第16关金银币配置位置矩阵
    int arr16[4][4]={{1,1,1,1},
                     {1,1,0,1},
                     {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>> v16;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr16[i][j]);
        }
        v16.push_back(v);
    }
    this->mData.insert(16,v16);

    //第17关金银币配置位置矩阵
    int arr17[4][4]={{1,1,1,1},
                     {1,1,0,1},
                     {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>> v17;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr17[i][j]);
        }
        v17.push_back(v);
    }
    this->mData.insert(17,v17);

    //第18关金银币配置位置矩阵
    int arr18[4][4]={{1,1,1,1},
                     {1,1,0,1},
                     {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>> v18;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr18[i][j]);
        }
        v18.push_back(v);
    }
    this->mData.insert(18,v18);

    //第19关金银币配置位置矩阵
    int arr19[4][4]={{1,1,1,1},
                     {1,1,0,1},
                     {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>> v19;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr19[i][j]);
        }
        v19.push_back(v);
    }
    this->mData.insert(19,v19);

    //第20关金银币配置位置矩阵
    int arr20[4][4]={{1,1,1,1},
                     {1,1,0,1},
                     {1,0,0,0},
                     {1,1,0,1}};
    QVector<QVector<int>> v20;
    for(int i=0;i<4;i++){
        QVector<int> v;
        for(int j=0;j<4;j++){
            v.push_back(arr20[i][j]);
        }
        v20.push_back(v);
    }
    this->mData.insert(20,v20);

}
