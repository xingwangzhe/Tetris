#pragma once
#include <QList>
#include <QPoint>
#include <QMap>
#include <QPainter>
#include <QString>

//元素有6种类型
enum ItemType {
    ItemType_Line = 0,		//直线形
    ItemType_T,				//T形
    ItemType_L1,			//L形1
    ItemType_L2,			//L形2
    ItemType_Square,		//正方形、田字形
    ItemType_Z,				//Z形
    ItemType_MAX,
};

//每种类型的元素都有上下左右4种朝向，一般每种朝向是一个不同形状
//长条元素一共只有2个形状
//田字元素一共只有1个形状
enum ItemDirection {
    ItemDirection_Up = 0,
    ItemDirection_Right,
    ItemDirection_Down,
    ItemDirection_Left,
    ItemDirection_MAX,	//方向总数4
};

typedef	QList<QPoint> PointList;

class Item
{
public:
    Item() {}
    Item(ItemType type, ItemDirection direction);
    ~Item();

    ItemType Type();
    ItemDirection Direction();
    PointList Points();

    void New(int nRandomFactor);				//随机生成新元素，nRandomFactor随机因子
    void InitPoints(ItemType type, ItemDirection direction);	//根据元素类型、方向，初始化4个坐标点

    void ClearPoints();
    void AddPoints(const PointList& points);
    bool Contains(QPoint& point);
    bool Contains(int x, int y);
    void ChangeDirection(int nDirection);		//传1就把方向状态+1，代表旋转90度

    void Move(int x, int y);					//横向移动x格,竖向移动y格
    void MoveTo(int x, int y);					//移动到位置(x,y)格
    void MoveDown(int nRow, int y);				//第nRow行以上的部分下移y个单位，用在消除之后
    void DeleteRow(int y);

    void Draw(QPainter& painter, int nStartX, int nStartY, int nWidth, int nHeight);

private:
    QString GetPointPostionText(ItemType type, ItemDirection direction);
    //将坐标位置的描述文本，转换为坐标点
    PointList TextToPointList(QString strFormat);

private:
    ItemType mType;					//元素类型(6种)
    ItemDirection mDirection;		//每种类型又有4种方向
    QPoint mPosition;				//元素当前的位置
    PointList mPoints;				//元素内4个坐标点，每个点代表一个格子坐标
};
