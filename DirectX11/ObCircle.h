#pragma once
class ObCircle : public GameObject
{
public:
	Vector2 vertex[360];

	ObCircle();
	~ObCircle() override;

	void Render() override;
};

