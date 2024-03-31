#ifndef MESSAGEHISTORY_H
#define MESSAGEHISTORY_H

#include <QWidget>
#include <QVBoxLayout>
#include "clickedwidget.h"

class MessageHistory : public QWidget
{
    Q_OBJECT
public:
    explicit MessageHistory(QWidget *parent = nullptr);

    void refresh();


private:
    QVBoxLayout* genreate_history();
    ClickedWidget* generate_row();

signals:
};

#endif // MESSAGEHISTORY_H
