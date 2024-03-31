#ifndef ROWS_H
#define ROWS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QStyle>
#include <QDebug>
#include "clickedwidget.h"
#include "roundimage.h"

class Rows : public QWidget
{
    Q_OBJECT
public:
    explicit Rows(QWidget *parent = nullptr);

    void refresh();
    void clear();
    QVBoxLayout* generate_rows();

private slots:
    void clickedRow();

private:
    ClickedWidget *selectedRowItem = nullptr;

    ClickedWidget* generate_row();
    void selectedRow(ClickedWidget *row);

signals:
};

#endif // ROWS_H
