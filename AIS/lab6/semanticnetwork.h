#ifndef SEMANTICNETWORK_H
#define SEMANTICNETWORK_H

#include <QVector>
#include <QPair>
#include <QMap>
#include <QDebug>
#include <QStringList>

class SemanticNetwork{
    //мапа названий объектов и их индексов для оптимизации поиска
    QMap<QString, uint> objIndexes;
    //массивы связей хранят индексы из мапы
    QVector<QPair<uint, uint>*> partOfVec;
    QVector<QPair<uint, uint>*> isAVec;
public:
    SemanticNetwork();
    ~SemanticNetwork();
    void addPartOf(QString a, QString b);
    void addIsA(QString a, QString b);
    QStringList partOfX(QString b);
    QStringList isAX(QString b);
    QStringList partOfY(QString a);
    QStringList isAY(QString a);
    int query(QStringList partOfList, QString p1, QStringList isAList, QString p2, /*QStringList isAConstList,*/ QStringList& res);
    QStringList getNames();

protected:
    QStringList intersection(QVector<QStringList>);
};

#endif // SEMANTICNETWORK_H
