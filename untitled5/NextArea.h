#ifndef NEXTAREA_H
#define NEXTAREA_H

#include "item.h"
#include <QWidget>

//右侧显示下一个元素的自绘widget

class NextArea : public QWidget
{
    Q_OBJECT
public:
    explicit NextArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

public slots:
    void slotUpdateNextItem(ItemType t, ItemDirection direction);

private:
    Item mItem;
};

#endif // NEXTAREA_H
