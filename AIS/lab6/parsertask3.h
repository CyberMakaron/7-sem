#ifndef PARSERTASK3_H
#define PARSERTASK3_H

#include <QString>
#include <QVector>
#include <QPair>
#include <QStringList>
#include "semanticnetwork.h"

struct pars_struc{
    QStringList partOfList;
    QString p1;
    QStringList isAList;
    QString p2;
};

class ParserTask3{
    QVector<QPair<QString, int>> templates;
    QStringList names;
public:
    ParserTask3(SemanticNetwork& net);
    bool compareStrings(QString str1, QString str2, float perm_perc);
    bool parse(QString input, QVector<pars_struc> &response);
};

#endif // PARSERTASK3_H
