#include "framework.h"
#include "MainGame.h"

MainGame::~MainGame()
{
}

void MainGame::Init()
{
    //MemDc �޸𸮻��� dc�� �ϳ� �� �߰�
    HBITMAP	 m_hOldBitmap, m_hBitmap;
    HDC	hdc = GetDC(g_hwnd); //���� �ڵ�
    g_MemDC = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 800, 600);
    m_hOldBitmap = (HBITMAP)SelectObject(g_MemDC, m_hBitmap);
    ReleaseDC(g_hwnd, hdc);

    rc.position.x = 100.0f;
    rc.position.y = 300.0f;
    rc.scale = Vector2(100.0f, 100.0f);
    rc.rotation = 0.0f;

    st.position.x = 400.0f;
    st.position.y = 300.0f;
    st.scale = Vector2(100.0f, 100.0f);
    st.rotation = 0.0f;

    cc.position.x = 700.0f;
    cc.position.y = 300.0f;
    cc.scale = Vector2(100.0f, 100.0f);
    cc.rotation = 0.0f;
}

void MainGame::Update()
{
    //Input::GetInstance();
    //Input::GetInstance();

    //GetAsyncKeyState �޽���ť�� ��ġ���ʰ� Ű�Է� �޾ƿ��� �Լ�

    if (INPUT->KeyPress(VK_UP))
    {
        rc.position.y -= 100.0f * DELTA;
    }
    if (INPUT->KeyPress(VK_DOWN))
    {
        rc.position.y += 100.0f * DELTA;
    }
    if (INPUT->KeyPress(VK_LEFT))
    {
        rc.position.x -= 100.0f * DELTA;
    }
    if (INPUT->KeyPress(VK_RIGHT))
    {
        rc.position.x += 100.0f * DELTA;
    }

    if (INPUT->KeyPress('1'))
    {
        rc.scale.x += 0.1f * DELTA;
    }
    if (INPUT->KeyPress('2'))
    {
        rc.scale.x -= 0.1f * DELTA;
    }
    if (INPUT->KeyPress('3'))
    {
        rc.scale.y += 0.1f * DELTA;
    }
    if (INPUT->KeyPress('4'))
    {
        rc.scale.y -= 0.1f * DELTA;
    }
    if (INPUT->KeyPress('5'))
    {
        rc.rotation += 30.0f * ToRadian * DELTA;
    }
    if (INPUT->KeyPress('6'))
    {
        rc.rotation -= 30.0f * ToRadian * DELTA;
    }

    rc.Update();
    st.Update();
    cc.Update();

    //Ű�� ������ �� wm_paint �� �߻� ���Ѷ�
    InvalidateRect(g_hwnd, NULL, false);
}

void MainGame::Render()
{
    PAINTSTRUCT ps;
    //hdc-> ��ȭ��
    g_hdc = BeginPaint(g_hwnd, &ps);

    //������ ���
    PatBlt(g_MemDC, 0, 0, 800, 600, WHITENESS);
    string FPS = "FPS : " + to_string(TIMER->GetFPS());
    TextOutA(g_MemDC, 0, 0, FPS.c_str(), FPS.size());

    rc.Render();
    st.Render();
    cc.Render();

    //��� ���� g_MemDC���� g_hdc��
    BitBlt(g_hdc, 0, 0, 800, 600, g_MemDC, 0, 0, SRCCOPY);

    EndPaint(g_hwnd, &ps);
}