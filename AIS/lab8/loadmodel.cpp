#include "loadmodel.h"

loadModel::loadModel(){

}

void loadModel::loadTask1(ProdModel &model){
    QStringList class_, replacement_optics, artistic_modes, price, camera;
    class_ << "Новичок" << "Любитель" << "Профессионал";
    replacement_optics << "Без сменной оптики" << "Есть сменная оптика";
    artistic_modes << "Нет художественных режимов" << "Есть художественные режимы";
    price << "Небольшая" << "Средняя" << "Высокая";
    camera  << "Riva Zoom100" << "Riva Zoom500" << "Riva Zoom550"
            << "Nikon 1200" << "Kodak 835AF" << "Nikon 1201"
            << "Dynax 404si" << "Dynax 406si" << "Dynax 408si"
            << "Rekam DH300" << "Rekam Max 3" << "Rekam Mega 110"

            << "Konica POP MINI" << "Konica POP EFP-8" << "Konica Centuria-10"
            << "Konica POP BF-8" << "Konica Centuria-20" << "Konica POP ST"
            << "Konica POP ST 80" << "Samsung FINO 15 SE" << "Samsung FINO 20 SE"
            << "Dynax 505si" << "Samsung VEGA 170" << "Pentax ESPIO 200"

            << "Нет подходящей модели" << "Нет подходящей модели" << "Нет подходящей модели"
            << "Нет подходящей модели" << "Нет подходящей модели" << "Нет подходящей модели"
            << "Konica Centuria-60Z" << "Konica Centuria-70Z" << "Olympus ZOOM 80"
            << "Olympus is-300" << "Dynax 7" << "Dynax 9";
    int k = 0;
    for (int i = 0; i < class_.size(); i++)
        for (int j = 0; j < replacement_optics.size(); j++)
            for (int x = 0; x < artistic_modes.size(); x++)
                for(int y = 0; y < price.size(); y++){
                    QStringList rule;
                    rule << class_[i] << replacement_optics[j] << artistic_modes[x] << price[y] << camera[k++];
                    model.addRule(rule);
                }

    QStringList question;
    question << "Покупает впервые" << "Новичок";
    model.addRule(question);
    question.clear();
    question << "Снимает для семейного альбома" << "Любитель";
    model.addRule(question);
    question.clear();
    question << "Печатается в изданиях" << "Любитель";
    model.addRule(question);
    question.clear();

    question << "Будет снимать в разных обстановках" << "Есть сменная оптика";
    model.addRule(question);
    question.clear();
    question << "Будет снимать в одной обстановке" << "Без сменной оптики";
    model.addRule(question);
    question.clear();

    question << "Знает, что такое глубина резкости" << "Есть художественные режимы";
    model.addRule(question);
    question.clear();
    question << "Не знает, что такое глубина резкости" << "Нет художественных режимов";
    model.addRule(question);
    question.clear();
}

void loadModel::loadTask2(ProdModel &model){
    QStringList rule;
    rule << "Ухудшение самочувствия - постепенное" << "Температура - невысокая"
         << "Насморк и заложенность носа - появляется в первые часы"
         << "Чихание - есть"
         << "Боль в горле и его покраснение - да"
         << "Диагноз - простуда";
    model.addRule(rule);
    rule.clear();

    rule << "Ухудшение самочувствия - быстрое" << "Температура - невысокая"
         << "Насморк и заложенность носа - появляется в первые дни"
         << "Чихание - есть"
         << "Боль в горле и его покраснение - да"
         << "Повышенная утомляемость - да"
         << "Диагноз - ОРВИ";
    model.addRule(rule);
    rule.clear();

    rule << "Ухудшение самочувствия - внезапное" << "Температура - высокая"
         << "Насморк и заложенность носа - появляется в первые дни"
         << "Боль в горле и его покраснение - да"
         << "Дискомфорт в глазах - да" << "Головная боль - да" << "Повышенная утомляемость - да"
         << "Бессонница - да"
         << "Диагноз - грипп";
    model.addRule(rule);
    rule.clear();

    rule << "1 день" << "Ухудшение самочувствия - внезапное";
    model.addRule(rule);
    rule.clear();
    rule << "2 дня" << "Ухудшение самочувствия - быстрое";
    model.addRule(rule);
    rule.clear();
    rule << "3 дня" << "Ухудшение самочувствия - постепенное";
    model.addRule(rule);
    rule.clear();

    rule << "37" << "Температура - невысокая";
    model.addRule(rule);
    rule.clear();
    rule << "38" << "Температура - невысокая";
    model.addRule(rule);
    rule.clear();
    rule << "39" << "Температура - высокая";
    model.addRule(rule);
    rule.clear();
    rule << "40" << "Температура - высокая";
    model.addRule(rule);
    rule.clear();

    rule << "Насморк сразу" << "Насморк и заложенность носа - появляется в первые часы";
    model.addRule(rule);
    rule.clear();
    rule << "Насморк через пару дней" << "Насморк и заложенность носа - появляется в первые дни";
    model.addRule(rule);
    rule.clear();

    rule << "Чихание" << "Чихание - есть";
    model.addRule(rule);
    rule.clear();

    rule << "Боль в горле" << "Боль в горле и его покраснение - да";
    model.addRule(rule);
    rule.clear();

    rule << "Дискомфорт в глазах" << "Дискомфорт в глазах - да";
    model.addRule(rule);
    rule.clear();

    rule << "Головная боль" << "Головная боль - да";
    model.addRule(rule);
    rule.clear();

    rule << "Повышенная утомляемость" << "Повышенная утомляемость - да";
    model.addRule(rule);
    rule.clear();

    rule << "Бессонница" << "Бессонница - да";
    model.addRule(rule);
    rule.clear();
}
