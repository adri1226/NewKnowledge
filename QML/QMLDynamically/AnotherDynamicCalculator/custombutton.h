#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QQuickItem>
#include <QMouseEvent>
#include <QDebug>

class PadButton : public QQuickItem
{
    Q_OBJECT
public:
    explicit PadButton(QQuickItem *parent = nullptr);
    explicit PadButton(int number, QQuickItem *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    int m_number;

};

#endif // CUSTOMBUTTON_H
