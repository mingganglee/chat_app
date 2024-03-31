#ifndef DISCUSSIONS_H
#define DISCUSSIONS_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
// #include <QSpacerItem>
#include <QPushButton>


class Discussions : public QWidget
{
    Q_OBJECT
public:
    explicit Discussions(QWidget *parent = nullptr);

    void refresh(QWidget *ui);
    QVBoxLayout* generate_rows();


private:
    void generate_widget();
    void generate_header();
    // QVBoxLayout* generate_rows();
    QWidget* generate_row();

signals:
};

#endif // DISCUSSIONS_H
