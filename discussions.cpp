#include "discussions.h"

Discussions::Discussions(QWidget *parent)
    : QWidget{parent}
{}


void Discussions::refresh(QWidget *ui)
{

}

void Discussions::generate_widget()
{
    QVBoxLayout box;



}

void Discussions::generate_header()
{
    QHBoxLayout *boxTitle = new QHBoxLayout();
    boxTitle->setContentsMargins(0,0,0,0);

    QLabel *title = new QLabel();
    title->setText("Discussions");

    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QPushButton *button = new QPushButton();
    button->setText("");
    button->setMinimumSize(32, 32);
    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    boxTitle->addWidget(title);
    boxTitle->addItem(spacer);
    boxTitle->addWidget(button);
}

QVBoxLayout* Discussions::generate_rows()
{
    QVBoxLayout *rows = new QVBoxLayout();
    rows->addWidget(generate_row());

    return rows;
}

QWidget* Discussions::generate_row()
{
    QWidget *row = new QWidget();
    QHBoxLayout *hbox = new QHBoxLayout();

    QLabel *avatar = new QLabel();

    QVBoxLayout *infoContainer = new QVBoxLayout();
    infoContainer->setContentsMargins(0, 6, 0, 6);
    QLabel *name = new QLabel();
    QLabel *content = new QLabel();
    infoContainer->addWidget(name);
    infoContainer->addWidget(content);

    QLabel *date = new QLabel();

    hbox->addWidget(avatar);
    hbox->addLayout(infoContainer);
    hbox->addWidget(date);

    row->setLayout(hbox);
    return row;
}
