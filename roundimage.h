#ifndef ROUNDIMAGE_H
#define ROUNDIMAGE_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QPainterPath>

class RoundImage : public QLabel
{
public:
    RoundImage(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // ROUNDIMAGE_H
