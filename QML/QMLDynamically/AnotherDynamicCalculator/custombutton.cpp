#include "custombutton.h"

PadButton::PadButton(QQuickItem *parent) : QQuickItem(parent)
{
    setAcceptedMouseButtons(Qt::LeftButton);
    setAcceptHoverEvents(true);

}

PadButton::PadButton(int number, QQuickItem *parent) : QQuickItem(parent), m_number(number)
{
    setAcceptedMouseButtons(Qt::LeftButton);
    setAcceptHoverEvents(true);
}

void PadButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // Lógica asociada al clic
        qDebug() << "Botón presionado " + QString::number(m_number);
    }

    // Llama al manejador de eventos de la clase base
    QQuickItem::mousePressEvent(event);
}
