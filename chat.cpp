#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Chat)
{
    ui->setupUi(this);

    // this->setWindowFlags (Qt::FramelessWindowHint);

    QFile file(":/res/qss/style1.qss");
    file.open(QIODevice::ReadOnly);
    QString style = file.readAll();
    file.close();
    this->setStyleSheet(style);

    // ui->MessagesArea->findChild<QVBoxLayout>("VBox");

}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_pushButton_2_clicked()
{
    // QWidget *row = new QWidget();
    // row->setObjectName("RowRight");

    // QHBoxLayout *box = new QHBoxLayout();
    // box->addStretch();
    // // box->setStretch(2, 8);
    // box->setAlignment(Qt::AlignRight);
    // box->setContentsMargins(10,10,10,10);


    QLabel *msg = new QLabel();
    msg->setObjectName("RowRight");
    msg->setWordWrap(true);
    msg->setText(ui->Message->text());

    // TODO: addItem 方式添加 Widget 暂未成功
    // QWidgetItem *item = new QWidgetItem(msg);
    // item->setAlignment(Qt::AlignRight);
    // ui->MessageHistory->layout()->addItem(item);

    // NOTE: 必须在 addWidget 后, 获取 item 对象设置对其方式, 才能生效否则生成的 Label 占一整行
    ui->MessageHistory->layout()->addWidget(msg);
    ui->MessageHistory->layout()->itemAt(ui->MessageHistory->layout()->indexOf(msg))->setAlignment(Qt::AlignRight);

    ui->Message->setText("");
}

void Chat::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        on_pushButton_2_clicked();
    }
    else
    {
        qDebug() << "keyPressEvent";
    }
}
