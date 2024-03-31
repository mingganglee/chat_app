#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QFile>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class Chat;
}
QT_END_NAMESPACE

class Chat : public QWidget
{
    Q_OBJECT

public:
    Chat(QWidget *parent = nullptr);
    ~Chat();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Chat *ui;
};
#endif // CHAT_H
