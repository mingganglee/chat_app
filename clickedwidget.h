#ifndef CLICKEDWIDGET_H
#define CLICKEDWIDGET_H

#include <QWidget>
#include <QMouseEvent>

class ClickedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClickedWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void clicked();
};

#endif // CLICKEDWIDGET_H
