#include "framework.h"

ObCircle::ObCircle()
{
    for (int i = 0; i < 360; i++)
    {
        vertex[i]=Vector2(0.5f * cosf(i * ToRadian), 0.5f * sinf(i * ToRadian));
    }
    vertex[0] = Vector2(0.5f * cosf(0 * ToRadian), 0.5f * sinf(0 * ToRadian));
}

ObCircle::~ObCircle()
{
}

void ObCircle::Render()
{
    Vector2 transformVertex[360];

    for (int i = 0; i < 360; i++)
    {
        transformVertex[i] = Vector2::Transform(vertex[i], W);
    }

    MoveToEx(g_MemDC, transformVertex[0].x, transformVertex[0].y, NULL);

    for (int i = 0; i < 360; i++)
    {
        LineTo(g_MemDC, transformVertex[i].x, transformVertex[i].y);
    }

    LineTo(g_MemDC, transformVertex[0].x, transformVertex[0].y);
    
}