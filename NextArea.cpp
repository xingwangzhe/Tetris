#include "NextArea.h"

NextArea::NextArea(QWidget *parent) : QWidget(parent)
{
}

void NextArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(QColor("#FFDEAD"));
    painter.setPen(QPen(QColor(Qt::black), 1));

    int xStart = 80;    //为了绘制在显示下一个方块区域的中部
    int yStart = 10;
    int w = 20;
    int h = 20;
    for(QPoint pt : mItem.Points())
    {
        int x = xStart + pt.x() * w;
        int y = yStart + pt.y() * h;
        painter.drawRect(x, y, w, h);
    }

    update();
}

void NextArea::slotUpdateNextItem(ItemType type, ItemDirection direction)
{
    mItem.InitPoints(type, direction);
}
