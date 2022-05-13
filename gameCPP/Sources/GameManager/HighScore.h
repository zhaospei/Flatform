#pragma once
#include"Singleton.h"
#include<iostream>
#include<fstream>
using namespace std;

#define HS HighScore::GetInstance()

struct Hight_Score {
	string name = "";
	int pickCoin = 0;
	int timeEnd = 0;
};

class HighScore : public CSingleton<HighScore> {
private:
	void Sort() {
		for (int i = 0; i < 6; i++) {
			for (int j = i + 1; j < 6; j++) {
				if (listHightSroce[i].pickCoin == listHightSroce[j].pickCoin) {
					if (listHightSroce[i].timeEnd > listHightSroce[j].timeEnd) {
						swap(listHightSroce[i], listHightSroce[j]);
					}
				}
				else if (listHightSroce[i].pickCoin < listHightSroce[j].pickCoin) {
					swap(listHightSroce[i], listHightSroce[j]);
				}
			}
		}
	}
public:
	string namePlayer;
	int pickCoin, coinReset, heart, map;
	float time;
	bool allowGetName;
	Hight_Score listHightSroce[6];
public:
	HighScore() {
		Init();
	}
	void Init() {
		namePlayer = "";
		pickCoin = 0;
		coinReset = 0;
		heart = 3;
		time = 0.0f;
		allowGetName = false;
		map = 0;
	}
	void setNamePlayer(int input) {
		if (input == 8) {
			if (namePlayer.size() > 0) {
				namePlayer.pop_back();
			}
		}
		else {
			if (input >= 32 && namePlayer.size() < 12 ) {
				namePlayer.push_back(char(input));
			}
		}
	}
	void updateHighScore() {
		listHightSroce[5].name = namePlayer;
		listHightSroce[5].pickCoin = pickCoin;
		listHightSroce[5].timeEnd = int(time);
		readFile();
		Sort();
		writeFile();
	}
	void readFile() {
		fstream myFile;
		myFile.open("../Data/HighScore.txt");
		for (int i = 0; i < 5; i++) {
			myFile >> listHightSroce[i].name;
			myFile >> listHightSroce[i].pickCoin;
			myFile >> listHightSroce[i].timeEnd;
		}
		myFile.close();
	}
	void writeFile() {
		fstream myFile;
		myFile.open("../Data/HighScore.txt");
		for (int i = 0; i < 5; i++) {
			myFile << listHightSroce[i].name << ' ' << listHightSroce[i].pickCoin << ' ' << listHightSroce[i].timeEnd << endl;
		}
		myFile.close();
	}
};

