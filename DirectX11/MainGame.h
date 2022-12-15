#pragma once
class MainGame : public Scene
{
private:
	ObRect rc;
	ObStar st;
	ObCircle cc;

public:
	~MainGame() override;
	//æ¿ √ ±‚»≠
	virtual void Init() override;
	//æ¿ ∞ªΩ≈
	virtual void Update() override;
	//æ¿ √‚∑¬
	virtual void Render() override;
};

