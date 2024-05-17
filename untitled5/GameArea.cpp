#include "GameArea.h"
#include <QTimerEvent>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTime>

//默认游戏区域为15*20的单元格，每个单元格尺寸40*40像素
#define MAX_COLUME		15
#define MAX_ROW			20
#define RECT_WIDTH		40
#define RECT_HEIGHT		40

//默认出生点水平中心处
#define DEFAULT_X_POS    (MAX_COLUME / 2 - 1)

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
    mScore = 0;
    mLevel = 1;
    mPaused = false;

    setMinimumSize(MAX_COLUME*RECT_WIDTH, MAX_ROW*RECT_HEIGHT);
}

void GameArea::NewGame()
{
    mFixItems.ClearPoints();

    //mCurItem 和 mNextItem 使用不同随机因子，避免初始一样
    mCurItem.New(QTime::currentTime().msec());
    mCurItem.MoveTo(DEFAULT_X_POS, 1);

    mNextItem.New(QTime::currentTime().second());
    emit sigUpdateNextItem(mNextItem.Type(), mNextItem.Direction());

    mScore = 0;
    mLevel = 1;
    mTimerID = startTimer(GetLevelTime(mLevel));
}

void GameArea::KeyPressed(int key)
{
    int x = 0;
    int y = 0;
    switch (key)
    {
    case Qt::Key_Left:
    {
        x = -1;
        break;
    }
    case Qt::Key_Up:
    {
        mCurItem.ChangeDirection(1);
        if (HitSide() || HitBottom())
        {
            mCurItem.ChangeDirection(-1);
        }
        return;
    }
    case Qt::Key_Right:
    {
        x = 1;
        break;
    }
    case Qt::Key_Down:
    {
        y = 1;
        break;
    }
    case Qt::Key_Space:
    {
        //空格键直接移到底部
        while (1)
        {
            mCurItem.Move(0, 1);
            if (HitSide() || HitBottom())
            {
                mCurItem.Move(0, -1);
                break;
            }
        }
        return;
    }
    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        //暂停
        mPaused = !mPaused;
        break;
    }
    }
    mCurItem.Move(x, y);

    if (HitSide() || HitBottom())
    {
        mCurItem.Move(-x, -y);
    }
}

void GameArea::paintEvent(QPaintEvent *)
{
    //绘制左侧游戏区域
    DrawBKRects();
    DrawFixedRects();
    DrawCurItem();

    //如果暂停了，游戏区中间显示"暂停"大字
    if(mPaused)
    {
        QFont font;
        font.setPixelSize(100);

        QPainter painter(this);
        painter.setFont(font);
        painter.setBrush(Qt::NoBrush);
        painter.setPen(QPen(QColor("#FF3333"), 1));
        painter.drawText(rect(), Qt::AlignCenter, "暂停");
    }

    update();
}

void GameArea::DrawBKRects()
{
    //画背景边框
    QPainter painter(this);
    painter.setBrush(QColor("#696969"));
    painter.setPen(Qt::NoPen);

    for (int i = 0; i < MAX_COLUME; i++)
    {
        for (int j = 0; j < MAX_ROW; j++)
        {
            if (i == 0 || i == MAX_COLUME - 1 || j == 0 || j == MAX_ROW - 1)
            {
                painter.drawRect(i*RECT_WIDTH, j*RECT_HEIGHT, RECT_WIDTH, RECT_HEIGHT);
            }
        }
    }
}

void GameArea::DrawFixedRects()
{
    QPainter painter(this);
    painter.setBrush(QColor("#D3D3D3"));
    painter.setPen(QPen(QColor(Qt::black), 1));

    mFixItems.Draw(painter, 0, 0, RECT_WIDTH, RECT_HEIGHT);
}

void GameArea::DrawCurItem()
{
    QPainter painter(this);
    painter.setBrush(QColor("#FFDEAD"));
    painter.setPen(QPen(QColor(Qt::black), 1));

    mCurItem.Draw(painter, 0, 0, RECT_WIDTH, RECT_HEIGHT);
}

void GameArea::timerEvent(QTimerEvent* e)
{
    if(mPaused)
    {
        return;
    }
    if (e->timerId() == mTimerID)
    {
        mCurItem.Move(0, 1);
        if (HitBottom())
        {
            mCurItem.Move(0, -1);
            AddToFixedRects();
            DeleteFullRows();

            if (HitTop())
            {
                killTimer(mTimerID);
                QMessageBox::information(NULL, "GAME OVER", "GAME OVER", QMessageBox::Yes, QMessageBox::Yes);
                NewGame();
                return;
            }

            mCurItem = mNextItem;
            mCurItem.MoveTo(DEFAULT_X_POS, 1);

            mNextItem.New(QTime::currentTime().msec());
            emit sigUpdateNextItem(mNextItem.Type(), mNextItem.Direction());
        }
    }
}

bool GameArea::HitSide()
{
    for (QPoint p : mCurItem.Points())
    {
        if (p.x() <= 0 || p.x() >= MAX_COLUME - 1)
        {
            return true;
        }
    }
    return false;
}

bool GameArea::HitBottom()
{
    for (QPoint p : mCurItem.Points())
    {
        if (p.y() >= MAX_ROW - 1)
        {
            return true;
        }
        if (mFixItems.Contains(p))
        {
            return true;
        }
    }
    return false;
}

bool GameArea::HitTop()
{
    for (QPoint p : mFixItems.Points())
    {
        if (p.y() <= 1)
        {
            return true;
        }
    }
    return false;
}

void GameArea::AddToFixedRects()
{
    PointList points = mCurItem.Points();
    mFixItems.AddPoints(points);
}

void GameArea::DeleteFullRows()
{
    int nRowsDeleted = 0;
    for (int i = 1; i < MAX_ROW - 1; i++)
    {
        int nCount = 0;
        for (int j = 1; j < MAX_COLUME - 1; j++)
        {
            if (mFixItems.Contains(j, i))
            {
                nCount++;
            }
        }
        if (nCount >= MAX_COLUME - 2)
        {
            mFixItems.DeleteRow(i);
            mFixItems.MoveDown(i, 1);	//消除行之上的内容下移一个单位
            nRowsDeleted++;
        }
    }

    //一次元素落下，最多可能消4行
    //一次消除的越多，得分越多
    if (nRowsDeleted == 1)
    {
        mScore += 100;
    }
    else if (nRowsDeleted == 2)
    {
        mScore += 300;
    }
    else if (nRowsDeleted == 3)
    {
        mScore += 500;
    }
    else if (nRowsDeleted == 4)
    {
        mScore += 700;
    }
    emit sigUpdateScore(mScore);    //更新MainWindow界面得分

    //粗略使用每1000分一关
    if (mScore >= 1000 * mLevel)
    {
        mLevel++;

        //随关卡增加下落速度，即把定时器加快
        killTimer(mTimerID);
       mTimerID = startTimer(GetLevelTime(mLevel));

        emit sigUpdateLevel(mLevel);    //更新MainWindow界面关卡
    }
}

int GameArea::GetLevelTime(int level)
{
    //第1关=1000ms,第2关=900ms 越来越快 第8关=300ms
    //关卡>8后，速度不再增加，保持200ms
    if (level > 8)
    {
        return 200;
    }
    if (level > 0)
    {
        return (11 - level) * 100;
    }
}
