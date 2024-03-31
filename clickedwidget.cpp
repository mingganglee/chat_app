#include "clickedwidget.h"

ClickedWidget::ClickedWidget(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_StyledBackground);
}


void ClickedWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // 在这里处理点击事件的逻辑
        emit clicked();
    }
}
