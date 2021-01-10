#include "questions2.h"

Questions2::Questions2(){
    QStringList tmp;
    runny_nose = false;
    tmp << "1" << "Сколько дней развивалось заболевание? (1 день, 2 дня, 3 дня)";
    body << tmp;
    tmp.clear();

    tmp << "1" << "Давайте измерим температуру! (37 - 40)";
    body << tmp;
    tmp.clear();

    tmp << "2" << "Насморк есть?" << "Да";
    body << tmp;
    tmp.clear();

    tmp << "3" << "Когда появился насморк?\n1. Сразу\n2. Через пару дней";
    body << tmp;
    tmp.clear();

    tmp << "4" << "Чихаете?" << "Чихание";
    body << tmp;
    tmp.clear();

    tmp << "4" << "Болит горло?" << "Боль в горле";
    body << tmp;
    tmp.clear();

    tmp << "4" << "Есть дискомфорт в глазах?" << "Дискомфорт в глазах";
    body << tmp;
    tmp.clear();

    tmp << "4" << "Болит голова?" << "Головная боль";
    body << tmp;
    tmp.clear();

    tmp << "4" << "Быстро устаёте?" << "Повышенная утомляемость";
    body << tmp;
    tmp.clear();

    tmp << "4" << "Плохо спите?" << "Бессонница";
    body << tmp;
    tmp.clear();
}

bool Questions2::getNextQuestion(QString& question){
    if (cur_question == body.size() - 1)
        return false;
    cur_question++;
    question = body[cur_question][1];
    return true;
}

bool Questions2::checkAnswer(QString& answer, QString& message){
    if (cur_question == -1)
        return false;
    int mode = body[cur_question][0].toInt();
    switch (mode) {
        case 1:
            message = answer;
        break;
        case 2:
            if (answer != "Да" && answer != "да")
                cur_question++;
        break;
        case 3:
            if (answer == "1") message = "Насморк сразу";
            else message = "Насморк через пару дней";
        break;
        case 4:
            if (answer == "Да" || answer == "да")
                message = body[cur_question][2];
            else message = "";
        break;
    }
    return true;
}

void Questions2::reset(){
    cur_question = -1;
    runny_nose = false;
}
