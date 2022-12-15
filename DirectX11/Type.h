#pragma once

class Scene //추상클래스 인터페이스 interface
{
public:

	virtual ~Scene() {};

	//순수가상함수
	//씬 초기화
	virtual void Init() = 0;
	//씬 갱신
	virtual void Update() = 0;
	//씬 출력
	virtual void Render() = 0;
};

template <typename T>
class Singleton
{
public:
    virtual ~Singleton() {};
    static T* GetInstance()
    {
        static T* Instance = new T;
        return Instance;
    };
    void DeleteSingleton()
    {
        delete GetInstance();
    };
};
