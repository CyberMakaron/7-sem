#include "parsertask3.h"

ParserTask3::ParserTask3(SemanticNetwork& net){
    templates << QPair<QString, int>("Кто является владельцем <>?", 1);
    templates << QPair<QString, int>("Какими магазинами владеет <>?", 2);
    templates << QPair<QString, int>("Где находится магазин <>?", 3);
    templates << QPair<QString, int>("На каком этаже находится <>?", 4);
    templates << QPair<QString, int>("Что продаётся в <>?", 5);
    templates << QPair<QString, int>("Какой режим работы магазина <>?", 6);
    templates << QPair<QString, int>("Где купить <>?", 7);
    templates << QPair<QString, int>("Какие способы оплаты доступны в <>?", 8);
    templates << QPair<QString, int>("В каких магизанах доступен <> расчёт?", 9);
    names = net.getNames();
}

//ну это очень криво, сплошой стыд
bool ParserTask3::compareStrings(QString str1, QString str2, float perm_perc){
    int len = qMin(str1.length(), str2.length());
    int acceptable = (int)(len * perm_perc); //допустимое количество несоответствий
    int incongruities = 0;// = abs(str1.length() - str2.length()); //количество несоответствий
//    if (incongruities > acceptable)
//        return false;
    for(int i = 0; i < len; i++){
        if (str1[i] != str2[i])
            incongruities++;
        if (incongruities > acceptable)
            return false;
    }
    return true;
}

bool ParserTask3::parse(QString input, QVector<pars_struc> &response){
    QString templ = input;
    templ.remove(templ.indexOf("<") + 1, templ.indexOf(">") - templ.indexOf("<") - 1);
    QString name = input.mid(input.indexOf("<") + 1, input.indexOf(">") - input.indexOf("<") - 1);
    int templ_num = -1;
    int i;

    for (i = 0; i < templates.size(); i++){
        if (compareStrings(templ, templates[i].first, 0.2)){
            templ_num = templates[i].second;
            break;
        }
    }
    if (templ_num == -1)
        return false;
    for (i = 0; i < names.size(); i++){
        if (compareStrings(name, names[i], 0.2)){
            name = names[i];
            break;
        }
    }
    if (i == names.size() && name != names[names.size() - 1])
        return false;
    pars_struc struc;
    switch (templ_num){
        case 1: struc.partOfList.append(name);
                struc.p1 = "1";
                struc.isAList.append("Владелец");
                struc.p2 = "1";
                response << struc;
            break;
        case 2: struc.partOfList.append(name);
                struc.p1 = "2";
                struc.isAList.append("Магазин");
                struc.p2 = "1";
                response << struc;
            break;
        case 3: struc.partOfList.append(name);
                struc.p1 = "1";
                struc.isAList.append("Этаж");
                struc.p2 = "1";
                response << struc;
                struc.partOfList.clear();
                struc.isAList.clear();
                struc.partOfList.append(name);
                struc.p1 = "1";
                struc.isAList.append("Крыло");
                struc.p2 = "1";
                response << struc;
                qDebug() << struc.partOfList<< struc.isAList;
            break;
        case 4: struc.partOfList.append(name);
                struc.p1 = "1";
                struc.isAList.append("Этаж");
                struc.p2 = "1";
                response << struc;
            break;
        case 5: struc.partOfList.append(name);
                struc.p1 = "1";
                struc.isAList.append("Категория товаров");
                struc.p2 = "1";
                response << struc;
            break;
        case 6: struc.partOfList.append(name);
                struc.p1 = "1";
                struc.isAList.append("Режим работы");
                struc.p2 = "1";
                response << struc;
            break;
        case 7: struc.partOfList.append(name);
                struc.p1 = "2";
                response << struc;
            break;
        case 8: struc.partOfList.append(name);
            struc.p1 = "1";
            struc.isAList.append("Способ оплаты");
            struc.p2 = "1";
            response << struc;
            break;
        case 9: struc.partOfList.append(name);
            struc.p1 = "2";
            response << struc;
            break;
    }

    return true;
}
