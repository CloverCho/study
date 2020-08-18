// 백준 15997번 승부 예측
// 제출 결과: 성공

#include <stdio.h>
#include <string.h>

char country[4][11];
float percentage[4][4]; // percentage[i][j] : i가 j에게 이길 확률
                        //  i가 j에게 질 확률 = j가 i에게 이길 확률 = percentage[j][i]
                        // i와 j가 비길 확률 = 1 - percentage[i][j] - percentage[j][i]

int game[6] = {
    0,
}; // -1: 짐, 0: 비김, 1: 이김
int game_case[6] = {1, 2, 3, 12, 13, 23};
float goal_rate[4] = {
    0.0,
};

void get_percentage()
{
    float value = 1.0;
    int score[4][2]; // score[i][0] : i번째 팀의 승점
                     // score[i][1] : i번째 팀의 인덱스

    for (int i = 0; i < 4; ++i)
    {
        score[i][0] = 0;
        score[i][1] = i;
    }

    int win, lose;

    // 확률 및 승점 계산
    for (int i = 0; i < 6; ++i)
    {
        if (game[i] == 1)
        {
            win = game_case[i] / 10;
            lose = game_case[i] % 10;
            value *= percentage[win][lose];
            score[win][0] += 3;
        }
        else if (game[i] == -1)
        {
            win = game_case[i] % 10;
            lose = game_case[i] / 10;
            value *= percentage[win][lose];
            score[win][0] += 3;
        }
        else
        {
            win = game_case[i] / 10;
            lose = game_case[i] % 10;

            value *= 1 - percentage[win][lose] - percentage[lose][win];
            score[win][0] += 1;
            score[lose][0] += 1;
        }
    }

    int target = score[0][0];

    // 삽입 정렬을 통해 score를 정렬
    for (int i = 1; i < 4; ++i)
    {
        int target = score[i][0];
        int target_index = i;
        for (int j = i - 1; j >= 0; --j)
        {
            if (score[j][0] < target)
            {
                int temp = score[j][0];
                int temp_index = score[j][1];
                score[j][0] = target;
                score[j][1] = target_index;
                score[j + 1][0] = temp;
                score[j + 1][1] = temp_index;
            }
        }
    }

    // 다음 라운드 진출팀 결정
    if (score[0][0] != score[1][0])
    {
        if (score[1][0] != score[2][0])
        { // 상위 2개 팀이 구별되는 경우 (이때 1,2등의 승점이 서로 다름)
            goal_rate[score[0][1]] += value;
            goal_rate[score[1][1]] += value;
        }
        else
        {
            if (score[2][0] != score[3][0])
            { // 1등이 따로 있고, 2, 3등의 승점이 같은 경우
                goal_rate[score[0][1]] += value;
                goal_rate[score[1][1]] += value / 2.0f;
                goal_rate[score[2][1]] += value / 2.0f;
            }
            else
            { // 1등이 따로 있고, 나머지 팀들의 승점이 같은 경우
                goal_rate[score[0][1]] += value;
                goal_rate[score[1][1]] += value / 3.0f;
                goal_rate[score[2][1]] += value / 3.0f;
                goal_rate[score[3][1]] += value / 3.0f;
            }
        }
    }
    else
    {
        if (score[1][0] != score[2][0])
        { // 상위 2개 팀이 구별되는 경우 (이때 1,2등 승점은 동일)
            goal_rate[score[0][1]] += value;
            goal_rate[score[1][1]] += value;
        }
        else
        {
            if (score[2][0] != score[3][0])
            { // 1, 2, 3 등의 승점이 동일하고, 4등이 따로 있는 경우
                goal_rate[score[0][1]] += value * 2.0f / 3.0f;
                goal_rate[score[1][1]] += value * 2.0f / 3.0f;
                goal_rate[score[2][1]] += value * 2.0f / 3.0f;
            }
            else
            { // 1 ~ 4등의 승점이 동일한 경우
                goal_rate[score[0][1]] += value / 2.0f;
                goal_rate[score[1][1]] += value / 2.0f;
                goal_rate[score[2][1]] += value / 2.0f;
                goal_rate[score[3][1]] += value / 2.0f;
            }
        }
    }
}

void dfs(int index, int value)
{
    if (index >= 0)
        game[index] = value;
    if (index == 5)
    {
        get_percentage();
        return;
    }

    dfs(index + 1, 1);
    dfs(index + 1, 0);
    dfs(index + 1, -1);
}

int main()
{
    scanf("%s %s %s %s", country[0], country[1], country[2], country[3]);

    char tempA[11], tempB[11];
    float win_rate, tie_rate, lose_rate;
    int first, second;

    for (int i = 0; i < 6; ++i)
    {
        scanf("%s %s %f %f %f", tempA, tempB, &win_rate, &tie_rate, &lose_rate);
        for (int j = 0; j < 4; ++j)
        {
            if (!strcmp(tempA, country[j]))
            {
                first = j;
            }
            if (!strcmp(tempB, country[j]))
            {
                second = j;
            }
        }
        percentage[first][second] = win_rate;
        percentage[second][first] = lose_rate;
    }

    dfs(-1, 0);

    for (int i = 0; i < 4; ++i)
    {
        printf("%f\n", goal_rate[i]);
    }

    return 0;
}
