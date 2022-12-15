#pragma once
class GameObject
{
public:
	/*Vector3 a;
	Vector4 b;*/

	Vector2 position; //중점
	Vector2 scale; //크기값
	float rotation; //회전값

	Matrix S, R, T, W;

public:
	GameObject();
	virtual ~GameObject();

	//가상함수
	//자식이 재정의 할 것이라고 예상될 때 사용
	virtual void Update();
	virtual void Render();
};

