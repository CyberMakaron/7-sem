#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <QStringList>
#include <QVector>
#include <QDebug>

class Questions{
    QVector<QStringList> body;  //messages, positive_answer, text_for_positive_answer, text_for_negative_answer;
    int cur_question;
    bool class_is_set;
public:
    Questions();
    bool getNextQuestion(QString& question);
    bool checkAnswer(QString& answer, QString& message);
    void reset();
};

#endif // QUESTIONS_H
