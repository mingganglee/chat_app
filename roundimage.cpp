#include "roundimage.h"

RoundImage::RoundImage(QWidget *parent): QLabel(parent) {
    setScaledContents(true);
}

void RoundImage::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    // QPixmap pixmap = this->pixmap().scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    QPixmap pixmap = this->pixmap().scaled(32, 32, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    if (pixmap.isNull()) {
        return;
    }

    QPixmap rounded_pixmap(pixmap.size());
    rounded_pixmap.fill(Qt::transparent);

    QPainter painter(&rounded_pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform); // Enable anti-aliasing
    QPainterPath path;
    path.addRoundedRect(0, 0, pixmap.width(), pixmap.height(), 16, 16);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, pixmap);
    painter.end();

    setPixmap(rounded_pixmap);
}
