#include "rows.h"

Rows::Rows(QWidget *parent)
    : QWidget{parent}
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    refresh();


}

void Rows::refresh()
{
    clear();
    setLayout(generate_rows());
}

void Rows::clear()
{
    QLayout *oldLayout = layout();
    if (oldLayout)
    {
        setLayout(nullptr);
        delete oldLayout;
    }

    // QLayoutItem* item;
    // while ((item = layout()->takeAt(0)) != nullptr)
    // {

    //     if (QWidget *widget = item->widget())
    //     {
    //         widget->deleteLater();
    //     }
    //     delete item;
    // }
}

QVBoxLayout* Rows::generate_rows()
{
    QVBoxLayout *rows = new QVBoxLayout();
    rows->setContentsMargins(0, 0, 0, 0);
    rows->setSpacing(0);

    ClickedWidget *rowOne = generate_row();
    selectedRow(rowOne);

    rows->addWidget(rowOne);
    rows->addWidget(generate_row());

    return rows;
}

ClickedWidget* Rows::generate_row()
{
    ClickedWidget *row = new ClickedWidget();
    row->setObjectName("Row");
    connect(row, &ClickedWidget::clicked, this, &Rows::clickedRow);

    QHBoxLayout *hbox = new QHBoxLayout();
    // hbox->setContentsMargins(12, 12, 12, 12);

    RoundImage *avatar = new RoundImage();
    avatar->setObjectName("Avatar");
    avatar->setMinimumSize(32, 32);
    avatar->setMaximumSize(32, 32);
    QPixmap pixmap(":/res/pic/avatar.png");
    avatar->setPixmap(pixmap);
    avatar->setScaledContents(true);

    QVBoxLayout *infoContainer = new QVBoxLayout();
    // infoContainer->setContentsMargins(0, 6, 0, 6);
    QLabel *name = new QLabel();
    name->setObjectName("DiscussionsNmae");
    name->setText("Arthur");
    QLabel *content = new QLabel();
    content->setObjectName("DiscussionsContent");
    content->setText("Ok pas de soucis");
    infoContainer->addWidget(name);
    infoContainer->addWidget(content);

    QLabel *date = new QLabel();
    date->setObjectName("DiscussionsDate");
    date->setAlignment(Qt::AlignTop | Qt::AlignRight);
    date->setText("date");

    hbox->addWidget(avatar);
    hbox->addLayout(infoContainer);
    hbox->addWidget(date);

    row->setLayout(hbox);
    return row;
}

void Rows::clickedRow()
{
    qDebug() << "clickedRows";
    ClickedWidget *row = qobject_cast<ClickedWidget*>(sender());
    selectedRow(row);

}

void Rows::selectedRow(ClickedWidget *row)
{
    if (selectedRowItem != nullptr)
    {
        selectedRowItem->setObjectName("Row");
        selectedRowItem->style()->polish(selectedRowItem);
    }

    selectedRowItem = row;
    selectedRowItem->setObjectName("HighlightRow");
    selectedRowItem->style()->polish(selectedRowItem);
}
