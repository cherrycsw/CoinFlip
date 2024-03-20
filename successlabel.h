#ifndef SUCCESSLABEL_H
#define SUCCESSLABEL_H

#include <QLabel>

class SuccessLabel : public QLabel
{
    Q_OBJECT
public:
    explicit SuccessLabel(QWidget *parent = nullptr);

    //通关label动画
    void zoom();

signals:

};

#endif // SUCCESSLABEL_H
