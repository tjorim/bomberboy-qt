#ifndef CURTAIN_H
#define CURTAIN_H

#include <QGraphicsItem>
#include <QTimer>
#include <vector>
#include <QObject>

class Curtain : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Curtain();
    void open(void);
    void close(void);

public slots:
    void nextFrame(void);

private:
    QTimer* timer_;
    std::vector<QGraphicsRectItem*> leftRects_;
    std::vector<QGraphicsRectItem*> rightRects_;
    bool opening_;
    bool closing_;
};

#endif // CURTAIN_H
