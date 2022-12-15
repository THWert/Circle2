#include <windows.h>
#include <math.h>
#include <chrono>
#include <string>

using namespace std;

#include "SimpleMath.h"
using namespace DirectX;
using namespace SimpleMath;

#include "Type.h"
#include "Input.h"
#include "Timer.h"

#include "GameObject.h"
#include "ObRect.h"
#include "ObStar.h"
#include "ObCircle.h"

#define ToRadian 0.0174533f
#define INPUT Input::GetInstance()
#define TIMER Timer::GetInstance()
#define DELTA Timer::GetInstance()->GetDeltaTime()

extern HDC g_hdc;
extern HWND g_hwnd;
extern HDC g_MemDC;