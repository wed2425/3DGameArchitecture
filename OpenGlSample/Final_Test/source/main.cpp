#include <iostream>
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")
#pragma comment(lib, "Winmm.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"
#include "RenderableObj.h"
#include "NonRenderableObj.h"
#include "Time.h"
#include "CompositeObj.h"
#include "../include/BackGround.h"
#include "../include/Keeper.h"
#include "../include/BasketBall.h"
#include "../include/SoccerBall.h"
#include "../include/Victory.h"
#include "../include/Lose.h"

bool BallCollision(CompositeObj* left, CompositeObj* right)
{

	bool collisionX = left->position.x + 1.0 >= (right->position.x) / 2 
						&& (right->position.x) / 2 + 1 >= left->position.x;
	bool collisionY = left->position.y + 1.0 >= (right->position.y) / 2 
						&& (right->position.y) / 2 + 1 >= left->position.y;
	bool collisionZ = left->position.z + 1.0 >= (right->position.z) / 2	
						&& (right->position.z) / 2 + 1 >= left->position.z;
	return collisionX && collisionY && collisionZ;
}

int main()
{
	PlaySound(TEXT("BGM.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	FileManager* filemgr = FileManager::instance();
	Renderer* renderer = Renderer::instance();
	RenderableObj* render_obj = new RenderableObj();
	NonRenderableObj* non_render_obj = new NonRenderableObj();
	Time* time = Time::instance();
	BackGround* background = new BackGround();
	Keeper* keeper = new Keeper();

	Victory* victory = new Victory();
	Lose* lose = new Lose();




	vector<BasketBall*>* basketball = new vector<BasketBall*>();

	for (int i = 0; i < 10; i++)
	{
		basketball->push_back(new BasketBall());
	}

	vector<SoccerBall*>* soccerball = new vector<SoccerBall*>();

	for (int i = 0; i < 3; i++)
	{
		soccerball->push_back(new SoccerBall());
	}

	renderer->init();

	background->setScale(4.5f, 4.5f, 0.1f);
	keeper->setScale(0.3f, 0.3f, 0.3f);

	//스케일
	for (
		vector<BasketBall*>::const_iterator it = basketball->begin();
		it != basketball->end();
		++it
		)
	{
		(*it)->setScale(0.2f, 0.2f, 0.2f);
	}

	for (
		vector<SoccerBall*>::const_iterator it = soccerball->begin();
		it != soccerball->end();
		++it
		)
	{
		(*it)->setScale(0.2f, 0.2f, 0.2f);
	}

	while (true)
	{
		renderer->Clear();

		if (time->IsFixedRendering())
		{
			renderer->update();
		}

		renderer->render();

	

		//축구공 충돌 승리
		for (
			vector<SoccerBall*>::const_iterator it = soccerball->begin();
			it != soccerball->end();
			++it
			)
		{
			if (BallCollision(keeper, (*it)))
			{
			
				keeper->setState(false);
				victory->setGameVictory(false);
			}
		}
		if (victory->getGameVictory() && keeper->getState() == false)
		{
			keeper->init();

			for (
				vector<SoccerBall*>::const_iterator it = soccerball->begin();
				it != soccerball->end();
				++it
				)
			{
				(*it)->init();
			}
		}


		//농구공 충돌 패배
		for (
			vector<BasketBall*>::const_iterator it = basketball->begin();
			it != basketball->end();
			++it
			)
		{
			if (BallCollision(keeper, (*it)))
			{
			
				keeper->setState(false);
				lose->setGameLose(false);
			}
		}

		if (lose->getGameLose() && keeper->getState() == false)
		{
			keeper->init();

			for (
				vector<BasketBall*>::const_iterator it = basketball->begin();
				it != basketball->end();
				++it
				)
			{
				(*it)->init();
			}
		}



		renderer->Out();
	}

	//삭제 처리
	for (
		vector<BasketBall*>::const_iterator it = basketball->begin();
		it != basketball->end();
		++it
		)
	{
		delete (*it);
	}
	

	
	for (
		vector<SoccerBall*>::const_iterator it = soccerball->begin();
		it != soccerball->end();
		++it
		)
	{
		delete (*it);
	}

	

	renderer->shutDown();

	delete background;
	delete keeper;
	delete victory;
	delete lose;
	delete non_render_obj;

	return 0;

}