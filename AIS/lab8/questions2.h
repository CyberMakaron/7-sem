#ifndef QUESTIONS2_H
#define QUESTIONS2_H

#include <QStringList>
#include <QVector>
#include <QDebug>

class Questions2{
    QVector<QStringList> body;
    int cur_question;
    bool runny_nose;
public:
    Questions2();
    bool getNextQuestion(QString& question);
    bool checkAnswer(QString& answer, QString& message);
    void reset();
};

#endif // QUESTIONS2_H
