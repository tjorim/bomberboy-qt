#include "curtain.h"
#include <QBrush>
#include <QDebug>

Curtain::Curtain()
{
    // create the big rect
    setRect(0,0,800,500);
    QBrush bigBrush;
    bigBrush.setColor(Qt::black);
    bigBrush.setStyle(Qt::SolidPattern);
    setBrush(bigBrush);

    QBrush smallBrush;
    smallBrush.setColor(Qt::white);
    smallBrush.setStyle(Qt::SolidPattern);

    // create left small rects
    QGraphicsRectItem* l1 = new QGraphicsRectItem(this);
    l1->setRect(0,0,400,100);
    l1->setPos(0,100);
    leftRects_.push_back(l1);
    l1->setBrush(smallBrush);

    QGraphicsRectItem* l2 = new QGraphicsRectItem(this);
    l2->setRect(0,0,400,100);
    l2->setPos(0,300);
    leftRects_.push_back(l2);
    l2->setBrush(smallBrush);

    // create right small rects
    QGraphicsRectItem* r1 = new QGraphicsRectItem(this);
    r1->setRect(0,0,400,100);
    r1->setPos(400,100);
    rightRects_.push_back(r1);
    r1->setBrush(smallBrush);

    QGraphicsRectItem* r2 = new QGraphicsRectItem(this);
    r2->setRect(0,0,400,100);
    r2->setPos(400,300);
    rightRects_.push_back(r2);
    r2->setBrush(smallBrush);

    // initialize
    timer_ = new QTimer(this);
    opening_ = false;
    closing_ = false;
}

void Curtain::open(){
    timer_->disconnect();
    opening_ = true;
    closing_ = false;

    connect(timer_,SIGNAL(timeout()),this,SLOT(nextFrame()));
    timer_->start(100);
}

void Curtain::close(){
    timer_->disconnect();
    closing_ = true;
    opening_ = false;

    connect(timer_,SIGNAL(timeout()),this,SLOT(nextFrame()));
    timer_->start(100);
}

/// Moves the curtains outward by a little if opening, inward if NOT opening.
void Curtain::nextFrame(){
    // if it opening
    if (opening_){
        // if its already fully opened, stop opening
        if (leftRects_[0]->x() < -1 * leftRects_[0]->boundingRect().width()){
            timer_->disconnect();
            opening_ = false;
            return;
        }

        // move curtains outward
        for (auto rect:leftRects_){
            rect->setPos(rect->x()-10,rect->y());
        }
        for (auto rect:rightRects_){
            rect->setPos(rect->x()+10,rect->y());
        }
    }

    // if its closing
    if (closing_){
        // if its already fully closed, stop closing
        if (leftRects_[0]->x() > 0){
            timer_->disconnect();
            closing_ = false;
            return;
        }

        // move curtains inward
        for (auto rect:leftRects_){
            rect->setPos(rect->x()+10,rect->y());
        }
        for (auto rect:rightRects_){
            rect->setPos(rect->x()-10,rect->y());
        }
    }
}
