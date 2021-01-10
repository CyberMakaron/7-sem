#include "prodmodel.h"

ProdModel::ProdModel(){

}

void ProdModel::addRule(QStringList &rule){
    QVector<uint> rule_vec;
    for (int i = 0; i < rule.size(); i++){
        if (!indexes.contains(rule[i]))
            indexes[rule[i]] = indexes.size();
        rule_vec <<indexes[rule[i]];
    }
    rules << rule_vec;
}

bool ProdModel::checkRule(QVector<uint>& wm, uint rule_num, uint& conclusion){
    uint last_num = rules[rule_num].size() - 1;
    for (uint i = 0; i < last_num; i++)
        if (!wm.contains(rules[rule_num][i]))
            return false;
    conclusion = rules[rule_num][last_num];
    return true;
}

bool ProdModel::directConclusion(QStringList &initMem, QStringList &response){
    QVector<uint> wm; //working memory
    for (int i = 0; i < initMem.size(); i++)
        if (indexes.contains(initMem[i]))
            wm << indexes[initMem[i]];
        else{
            qDebug() << "Неизвестный элемент: " << initMem[i];
            return false;
        }
    QVector<bool> rule_is_active(rules.size());

    QString mes = "Рабочая память: ";
    for (int i = 0; i < wm.size(); i++)
        mes += indexes.key(wm[i]) + QString(i==wm.size()-1?"":", ");
    qDebug() << "Заданная рабочая память:";
    qDebug() << mes;
    bool flag = true;
    uint conclusion_index;
    while(flag){
        flag = false;
        for (int i = 0; i < rules.size(); i++)
            if(!rule_is_active[i])
                if (checkRule(wm, i, conclusion_index)){
                    rule_is_active[i] = true;
                    response << indexes.key(conclusion_index);
                    wm << conclusion_index;
                    mes += ", " + indexes.key(conclusion_index);
                    qDebug() << "Пройдёмся по неотмеченным правилам и, если правило выполняеся, то отметим его и добавим консенгент  рабочую память";
                    qDebug() << mes;
                    flag = true;
                }
    }
    qDebug() << "Конец алгоритма прямой цепочки рассуждений (на последнем шаге не было выполнено новых условий)";
    return true;
}
