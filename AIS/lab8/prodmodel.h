#ifndef PRODMODEL_H
#define PRODMODEL_H

#include <QVector>
#include <QStringList>
#include <QMap>
#include <QDebug>

class ProdModel{
    QMap<QString, uint> indexes;
    QVector<QVector<uint>> rules;
public:
    ProdModel();
    void addRule(QStringList& rule);
//    void appendToMemory(QStringList& data);
    bool directConclusion(QStringList& initMem, QStringList& response);
    bool checkRule(QVector<uint>& wm, uint rule_num, uint& response);
};

#endif // PRODMODEL_H
