#include "semanticnetwork.h"

SemanticNetwork::SemanticNetwork(){

}

SemanticNetwork::~SemanticNetwork(){
    for (int i = 0; i < partOfVec.size(); i++)
        delete partOfVec[i];
    for (int i = 0; i < isAVec.size(); i++)
        delete isAVec[i];
}

void SemanticNetwork::addPartOf(QString a, QString b){
    uint a_i, b_i;

    if (!objIndexes.contains(a)){
        objIndexes[a] = objIndexes.size();
        qDebug() << a << "is not contains!";
    }
    a_i = objIndexes[a];

    if (!objIndexes.contains(b)){
        objIndexes[b] = objIndexes.size();
        qDebug() << b << "is not contains!";
    }
    b_i = objIndexes[b];

    partOfVec << new QPair<uint, uint>(a_i, b_i);
}

void SemanticNetwork::addIsA(QString a, QString b){
    uint a_i, b_i;

    if (!objIndexes.contains(a))
        objIndexes[a] = objIndexes.size();
    a_i = objIndexes[a];

    if (!objIndexes.contains(b))
        objIndexes[b] = objIndexes.size();
    b_i = objIndexes[b];

    isAVec << new QPair<uint, uint>(a_i, b_i);
}

//Ищем первый аргумент в связях partOf
QStringList SemanticNetwork::partOfX(QString b){
    QStringList list;
    uint b_i;
    if (objIndexes.contains(b))
        b_i = objIndexes[b];
    else
        return list;
    for (int i = 0; i < partOfVec.size(); i++){
        if (partOfVec[i]->second == b_i)
            list << objIndexes.key(partOfVec[i]->first);
    }
    return list;
}

//Ищем первый аргумент в связях isA
QStringList SemanticNetwork::isAX(QString b){
    QStringList list;
    uint b_i;
    if (objIndexes.contains(b))
        b_i = objIndexes[b];
    else
        return list;
    for (int i = 0; i < isAVec.size(); i++){
        if (isAVec[i]->second == b_i)
            list << objIndexes.key(isAVec[i]->first);
    }
    return list;
}

//Ищем второй аргумент в связях partOf
QStringList SemanticNetwork::partOfY(QString a){
    QStringList list;
    uint a_i;
    if (objIndexes.contains(a))
        a_i = objIndexes[a];
    else
        return list;
    for (int i = 0; i < partOfVec.size(); i++){
        if (partOfVec[i]->first == a_i)
            list << objIndexes.key(partOfVec[i]->second);
    }
    return list;
}

//Ищем второй аргумент в связях isA
QStringList SemanticNetwork::isAY(QString a){
    QStringList list;
    uint a_i;
    if (objIndexes.contains(a))
        a_i = objIndexes[a];
    else
        return list;
    for (int i = 0; i < isAVec.size(); i++){
        if (isAVec[i]->first == a_i)
            list << objIndexes.key(isAVec[i]->second);
    }
    return list;
}

//partOfList - набор параметров поиска в связях partOf, p1 - какой параметр будет искомым(1 или 2; кажая цифра соответствует строке из partOfList),
//isAList и p2 - аналогично для свзяей isA, res - результат пересечения найденных по параметрам результатов
int SemanticNetwork::query(QStringList partOfList, QString p1, QStringList isAList, QString p2/*, QStringList isAConstList*/, QStringList& res){
    QVector<QStringList> listsVec;
    for (int i = 0; i < partOfList.size(); i++)
        if (objIndexes.contains(partOfList[i]))
            if (p1[i] == '1') listsVec << partOfX(partOfList[i]);
            else listsVec << partOfY(partOfList[i]);
        else{
            qDebug() << "Нет объекта с именем " << partOfList[i];
            return 1;
        }
    for(int i = 0; i < isAList.size(); i++)
        if (objIndexes.contains(isAList[i]))
            if (p2[i] == '1') listsVec << isAX(isAList[i]);
            else listsVec << isAY(isAList[i]);
        else{
            qDebug() << "Нет объекта с именем " << isAList[i];
            return 1;
        }
//    for(int i = 0; i < isAConstList.size(); i+=2)
//        if (objIndexes.contains(isAConstList[i]) && objIndexes.contains(isAConstList[i+1]))
//            uint a = objIndexes[isAConstList[i]], b = objIndexes[isAConstList[i+1]];
//            listsVec << isAVec.(isAList[i]);
//            else listsVec << isAY(isAList[i]);
//        else{
//            qDebug() << "Нет объекта с именем " << isAList[i];
//            return 1;
//        }
    qDebug() << listsVec;
    for(int i = 0; i < listsVec.size(); i++)
        listsVec[i].removeDuplicates();
    res += intersection(listsVec);
    return 0;
}

QStringList SemanticNetwork::getNames(){
    return objIndexes.keys();
}

//тута ркурсивноделаем попарное пересечение, пока не останется 1 элемент QStringList
QStringList SemanticNetwork::intersection(QVector<QStringList> lists){
    if (lists.size() == 1)
        return lists[0];
    else if (lists.size() == 0){
        QStringList list;
        return list;
    }
    QVector<QStringList> res;
    for (int k = 1; k < lists.size(); k++){
        QStringList list;
        for (int i = 0; i < lists[0].size(); i++)
            if (lists[k].contains(lists[0][i]))
                list << lists[0][i];
        if (list.size() != 0)
            res << list;
    }
    return intersection(res);
}
