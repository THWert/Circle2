#pragma once
class MainGame : public Scene
{
private:
	ObRect rc;
	ObStar st;
	ObCircle cc;

public:
	~MainGame() override;
	//�� �ʱ�ȭ
	virtual void Init() override;
	//�� ����
	virtual void Update() override;
	//�� ���
	virtual void Render() override;
};

