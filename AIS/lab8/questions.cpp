#include "questions.h"

Questions::Questions(){
    cur_question = -1;
    QStringList tmp;
    class_is_set = false;
    tmp << "Покупаете фотооаппарат впервые?" << "Да" << "Покупает впервые" << "";
    body << tmp;
    tmp.clear();
    tmp << "Снимаете для семейного альбома?" << "Да" << "Снимает для семейного альбома" << "";
    body << tmp;
    tmp.clear();
    tmp << "Печатаетесь в изданиях?" << "Да" << "Печатается в изданиях" << "";
    body << tmp;
    tmp.clear();
    tmp << "Будете снимать в различных обстановках?" << "Да" << "Будет снимать в разных обстановках" << "Будет снимать в одной обстановке";
    body << tmp;
    tmp.clear();
    tmp << "Что такое глубина резкости?\n1. Что-то глуокое и резкое\n2.Диапазон расстояний, в котором все объекты выходят резкими" << "2" << "Знает, что такое глубина резкости" << "Не знает, что такое глубина резкости";
    body << tmp;
    tmp.clear();
    tmp << "Сколько вы готовы заплатить?\n1. До 5000\n2. До 15000\n3. До 50000";
    body << tmp;
    tmp.clear();
}

bool Questions::getNextQuestion(QString& question){
    if (cur_question == body.size() - 1)
        return false;
    if (cur_question <= 2 && class_is_set)
        cur_question = 3;
    else
        if (cur_question == 2 && !class_is_set)
            cur_question = 0;
        else
            cur_question++;
    question = body[cur_question][0];
    return true;
}

bool Questions::checkAnswer(QString& answer, QString& message){
    if (cur_question == -1)
        return false;
    if (cur_question == 5){
        if (answer == "1")
            message = "Небольшая";
        if (answer == "2")
            message = "Средняя";
        if (answer == "3")
            message = "Высокая";
        return true;
    }
    if (answer.compare(body[cur_question][1], Qt::CaseInsensitive) == 0){
        message = body[cur_question][2];
        if (cur_question < 3){
            class_is_set = true;
        }
        return true;
    } else{
        message = body[cur_question][3];
        return true;
    }
}

void Questions::reset(){
    cur_question = -1;
    class_is_set = false;
}
