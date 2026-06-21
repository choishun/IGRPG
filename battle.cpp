#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "monster.h"
#include "battle.h"
using namespace std;

const int CRIT_CHANCE = 30;         // 크리티컬 확률 설정 30% 확률

bool battle::battle_start(player& py, monster& ms) {
    srand((unsigned int)time(nullptr));

    int bonusDmg = 0;   // 2번 집중 공격 보너스
    bool shieldUsed = false; // 3번 방어 쿨다운
    bool playerShielding = false; // 이번 턴 방어 여부

    // 몬스터 측 상태
    int msBonusDmg = 0;
    bool msShieldUsed = false;
    bool msShielding = false;

    while (py.pyAlive() && ms.msAlive()) {

        // ── 1. 몬스터 행동 먼저 결정 (선택만, 실행은 아직) ──
        msShielding = false;
        int msChoice = rand() % 3 + 1;
        if (msChoice == 3 && !msShieldUsed) {
            msShielding = true;
            msShieldUsed = true;
            cout << "[ 몬스터가 뭔가 준비하고 있다... ]\n";  // 방어인지는 숨김
        }
        else {
            if (!msShielding) msShieldUsed = false;
        }

        // ── 2. 상태 출력 + 플레이어 행동 선택 ──
        cout << "\n[ 내 HP: " << py.getHp() << " | 공격력: " << py.getAtk();
        if (bonusDmg > 0) cout << "(+" << bonusDmg << " 집중)";
        cout << " ]\n";
        cout << "[ 몬스터 HP: " << ms.getHp() << " ]\n";
        cout << "------------------------------\n";
        cout << " 1. 공격      (크리티컬 " << CRIT_CHANCE << "%: 데미지 2배)\n";
        cout << " 2. 집중 공격  (다음 공격 +30 데미지)\n";
        if (!shieldUsed)
            cout << " 3. 방어      (이번 턴 피해 0)\n";
        else
            cout << " 3. 방어      (쿨다운 - 사용 불가)\n";
        cout << " -> ";

        int choice;
        cin >> choice;
        playerShielding = false;

        // ── 3. 동시 실행 ──

        // 플레이어 → 몬스터 공격 처리
        if (choice == 1 || (choice == 3 && shieldUsed)) {
            int dmg = py.getAtk() + bonusDmg;
            bonusDmg = 0;
            if ((rand() % 100) < CRIT_CHANCE) { dmg *= 2; cout << "크리티컬!! "; }
            if (msShielding)
                cout << "공격했지만 몬스터가 방어로 막았다! (피해 0)\n";
            else {
                cout << "몬스터에게 " << dmg << " 데미지!\n";
                ms.setHp(ms.getHp() - dmg);
            }
        }
        else if (choice == 2) {
            bonusDmg = 30;
            cout << "집중! 다음 공격에 +30 데미지!\n";
        }
        else if (choice == 3 && !shieldUsed) {
            playerShielding = true;
            shieldUsed = true;
            cout << "방어 자세!\n";
        }
        else {
            cout << "잘못된 입력! 턴을 넘긴다...\n";
        }
        if (!playerShielding) shieldUsed = false;
        if (!ms.msAlive()) break;

        // 몬스터 → 플레이어 공격 처리
        cout << "\n[ 몬스터의 턴 결과 ]\n";
        if (msShielding) {
            cout << "몬스터가 방어 자세를 취했다!\n";
        }
        else if (msChoice == 1) {
            int msDmg = ms.getAtk() + msBonusDmg;
            msBonusDmg = 0;
            if ((rand() % 100) < CRIT_CHANCE) { msDmg *= 2; cout << "몬스터 크리티컬!! "; }
            if (playerShielding)
                cout << "몬스터가 공격했지만 방어로 막았다! (피해 0)\n";
            else {
                cout << "몬스터가 " << msDmg << " 데미지로 공격!\n";
                py.setHp(py.getHp() - msDmg);
            }
        }
        else if (msChoice == 2) {
            msBonusDmg = 30;
            cout << "몬스터가 힘을 모으고 있다...!\n";
        }

        if (!py.pyAlive()) cout << "\n당신은 쓰러졌다...\n";
    }

    if (ms.getHp() <= 0) {
        cout << "승리!\n";
        return true;        //승리시 true
    }
    else {
        cout << "패배...\n";
        return false;          //패배시 false
    }
}