#include <iostream>
#include <string>
#include "GameEngine.h"
#include "player.h"
#include "monster.h"
#include "battle.h"
using namespace std;
void GameEngine::GameRun() {
	cout << "IGRPG (부제:IGRUS 동방을 지켜라!)\n";
	cout << "---------------------------------           --- projected by choishun ---\n";
	string start;
	cout << "동아리 가입비 20000원을 내시겠습니까?\n(아무 키나 눌러 가입비를 내세요!)\n->";
	cin >> start;
	player py;
	cout << "당신의 이름은? \n->";
	string name;
	cin >> name;
	py.setName(name);
	monster m[3];
	cout << endl;
	cout << "가입 완료! " << py.getName() << "님 환영합니다!! (:bepdung8: :bepdung8:)\n\n";
	cout << "아무 키나 눌러 게임을 시작하세요: \n->";
	cin >> start;
	cout << "게임 시작!\n";
	cout << "(->뒤로 아무 키나 눌러 게임을 진행 시켜 주세요!)\n";
	cout << "------------------------------------------------\n\n";
	monster ms[3];
	cout << "가입 후 아그둥이 활동을 위해 동방에 처음 방문한 " << py.getName() <<"\n기대를 안고 동방문을 열었는데...\n->";
	cin >> start;
	cout << "...!!!...\n->";
	cin >> start;
	cout<<"\"어으... 이게 대체 무슨 냄새야!!!\"\n->";
	cin >> start;
	cout << endl;
	cout << "전투 시작! \"Lv1 오늘따라 유독 심한 동방 냄새\" \n";
	
	battle b1;
	ms[0].setHp(300);	//Lv1 적 세팅
	ms[0].setAtk(20);
	py.setHp(100);
	while (!b1.battle_start(py, ms[0])) {
		py.setHp(100);			// 재도전 시 플레이어 HP 회복
		
		cout << "아그핑의 가호로 부활했다!\n";
	}
	cout << "전투 종료! \"적절한 환기와 탈취제로 해결했다...! 지하라 어쩔 수 없지만 얼추 해결된 것 같다!\" \n->";
	cin >> start;
	cout << endl;
	cout << "덕분에 즐겁게 아그둥이 활동을 마친 " << py.getName() << "\n활동이 끝나고 동방에 남아 과제를 하던중...\n->";
	cin >> start;
	cout << "...!!!...\n->";
	cin >> start;
	cout<<"\"책상에 저게 다 뭐야!!!\"\n->";
	cin >> start;
	cout << endl;
	cout << "전투 시작! \"Lv2 먹고 나서 안치운 커피와 음료수\" \n";

	battle b2;
	ms[1].setHp(400);		//Lv2 적 세팅
	ms[1].setAtk(30);
	py.setHp(100);
	while (!b2.battle_start(py, ms[1])) {
		py.setHp(100);   // 재도전 시 플레이어 HP 회복
		
		cout << "뱁둥이의 가호로 부활했다!\n";
	}
	cout << "전투 종료! \"내가 먹지는 않았지만 솔선수범하여 치웠다...! 앞으로 내 커피랑 음료수는 마시고 바로바로 치워야겠다!\" \n->";
	cin >> start;
	cout << endl;
	cout << "동방에서 사람들과 즐겁게 과제를 마무리한 " << py.getName() << "\n짐을 챙겨 밖으로 나가는데...\n->";
	cin >> start;
	cout << "...!!!...\n->";
	cin >> start;
	cout<<"\"아으 잠깐만 이건 또 뭐야!!!\"\n->";
	cin >> start;
	cout << endl;
	cout << "전투 시작! \"Lv3 신경 쓰지 않아 덜 닫힌 동방 문\" \n";
	
	battle b3;
	ms[2].setHp(500);		//Lv3 적 세팅
	ms[2].setAtk(40);
	py.setHp(100);
	while (!b3.battle_start(py, ms[2])) {
		py.setHp(100);   // 재도전 시 플레이어 HP 회복
		
		cout << "회장님의 권한으로 부활했다!\n";
	}
	cout << "전투 종료! \"닫히는 소리가 날때 까지 밀어서 잘 닫았다...! 다행히 동방의 냉난방을 지켰다!\" \n->";
	cin >> start;
	cout << endl;
	cout << "모든 역경을 해결한 " << py.getName() << "...\n앞으로 더 즐겁게 아그 동방을 이용할 수 있을 것 같다! \n->";
	cin >> start;
	cout << endl;
	cout << "----------\n";
	cout << "게임 종료!\n";
	cout << "THANKS FOR PLAYING!\n2학기에도 IGRUS와 아그동방 많이 사랑해주세요!!";
}
