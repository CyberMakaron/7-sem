#include "loadnetwork.h"

LoadNetwork::LoadNetwork(){

}

void LoadNetwork::loadTask1(SemanticNetwork &net){
    net.addIsA("Тюнинг автомобилей", "Название журнала");
    net.addIsA("Мода", "Название журнала");
    net.addIsA("Компьютерные и видео игры", "Название журнала");
    net.addIsA("Рукоделие", "Название журнала");
    net.addIsA("Фотография", "Название журнала");
    net.addIsA("Кино и музыка", "Название журнала");
    net.addIsA("Мужчины", "Целевая аудитория");
    net.addIsA("Женщины", "Целевая аудитория");
    net.addIsA("140", "Стоимость");
    net.addIsA("90", "Стоимость");
    net.addIsA("65", "Стоимость");
    net.addIsA("45", "Стоимость");
    net.addIsA("100", "Стоимость");
    net.addIsA("30", "Стоимость");
    net.addIsA("170", "Объём страниц");
    net.addIsA("90", "Объём страниц");
    net.addIsA("60", "Объём страниц");
    net.addIsA("50", "Объём страниц");
    net.addIsA("95", "Объём страниц");
    net.addIsA("30", "Объём страниц");
    net.addIsA("Современные технологии тюнинга автомобилей", "Информация");
    net.addIsA("Новейшие тенденции моды", "Информация");
    net.addIsA("Всё о компьютерных и видео играх", "Информация");
    net.addIsA("Эксклюзивные вещи своими руками", "Информация");
    net.addIsA("Основы и секреты фотографиии", "Информация");
    net.addIsA("Только актуальная информация о кино и музыке", "Информация");
    net.addIsA("Да", "Возможна подписка");
    net.addIsA("Нет", "Возможна подписка");

    net.addPartOf("Мужчины", "Тюнинг автомобилей");
    net.addPartOf("140", "Тюнинг автомобилей");
    net.addPartOf("170", "Тюнинг автомобилей");
    net.addPartOf("Современные технологии тюнинга автомобилей", "Тюнинг автомобилей");
    net.addPartOf("Нет", "Тюнинг автомобилей");

    net.addPartOf("Женщины", "Мода");
    net.addPartOf("90", "Мода");
    net.addPartOf("90", "Мода");
    net.addPartOf("Новейшие тенденции моды", "Мода");
    net.addPartOf("Да", "Мода");

    net.addPartOf("Мужчины", "Компьютерные и видео игры");
    net.addPartOf("Женщины", "Компьютерные и видео игры");
    net.addPartOf("65", "Компьютерные и видео игры");
    net.addPartOf("60", "Компьютерные и видео игры");
    net.addPartOf("Всё о компьютерных и видео играх", "Компьютерные и видео игры");
    net.addPartOf("Нет", "Компьютерные и видео игры");

    net.addPartOf("Женщины", "Рукоделие");
    net.addPartOf("45", "Рукоделие");
    net.addPartOf("50", "Рукоделие");
    net.addPartOf("Эксклюзивные вещи своими руками", "Рукоделие");
    net.addPartOf("Да", "Рукоделие");

    net.addPartOf("Мужчины", "Фотография");
    net.addPartOf("Женщины", "Фотография");
    net.addPartOf("100", "Фотография");
    net.addPartOf("95", "Фотография");
    net.addPartOf("Основы и секреты фотографиии", "Фотография");
    net.addPartOf("Да", "Фотография");

    net.addPartOf("Мужчины", "Кино и музыка");
    net.addPartOf("Женщины", "Кино и музыка");
    net.addPartOf("30", "Кино и музыка");
    net.addPartOf("30", "Кино и музыка");
    net.addPartOf("Только актуальная информация о кино и музыке", "Кино и музыка");
    net.addPartOf("Нет", "Кино и музыка");

}

void LoadNetwork::loadTask2(SemanticNetwork &net){
    net.addIsA("ООО \"Созвездие\"", "Предприятие");
    net.addIsA("Иванов И.И.", "Директор");
    net.addIsA("Отдел разработки", "Отдел");
    net.addIsA("Отдел маркетинга", "Отдел");
    net.addIsA("Бюро постановки задач", "Подразделение");
    net.addIsA("Бюро программирования", "Подразделение");
    net.addIsA("Бюро сопрвождения", "Подразделение");
    net.addIsA("Петров П.П.", "Начальник отдела");
    net.addIsA("Тошико Ямада", "Начальник отдела");
    net.addIsA("Сидоров С.С.", "Начальник бюро");
    net.addIsA("Брайн Керниган", "Начальник бюро");
    net.addIsA("Билл Гейтс", "Начальник бюро");
    net.addIsA("Директор", "Сотрудник");
    net.addIsA("Начальник отдела", "Сотрудник");
    net.addIsA("Начальник бюро", "Сотрудник");

    net.addIsA("Постановка задачи", "Этап");
    net.addIsA("Программирование", "Этап");
    net.addIsA("Продвижение на рынок", "Этап");
    net.addIsA("Поддержка", "Этап");
    net.addIsA("1", "Номер этапа");
    net.addIsA("2", "Номер этапа");
    net.addIsA("3", "Номер этапа");
    net.addIsA("4", "Номер этапа");

    net.addPartOf("Сотрудник", "ООО \"Созвездие\"");
    net.addPartOf("Отдел разработки", "ООО \"Созвездие\"");
    net.addPartOf("Отдел маркетинга", "ООО \"Созвездие\"");
    net.addPartOf("Бюро постановки задач", "Отдел разработки");
    net.addPartOf("Бюро программирования", "Отдел разработки");
    net.addPartOf("Бюро сопрвождения", "Отдел разработки");
    net.addPartOf("Петров П.П.", "Отдел разработки");
    net.addPartOf("Тошико Ямада", "Отдел маркетинга");
    net.addPartOf("Сидоров С.С.", "Бюро постановки задач");
    net.addPartOf("Брайн Керниган", "Бюро программирования");
    net.addPartOf("Билл Гейтс", "Бюро сопрвождения");

    net.addPartOf("1", "Постановка задачи");
    net.addPartOf("2", "Программирование");
    net.addPartOf("3", "Продвижение на рынок");
    net.addPartOf("4", "Поддержка");
    net.addPartOf("Постановка задачи", "Бюро постановки задач");
    net.addPartOf("Программирование", "Бюро программирования");
    net.addPartOf("Продвижение на рынок", "Отдел маркетинга");
    net.addPartOf("Поддержка", "Бюро сопрвождения");

    //Разработка текстового редактора "Созвездие"
    net.addIsA("Разработка текстового редактора \"Созвездие\"", "Задание");
    net.addPartOf("Разработка текстового редактора \"Созвездие\"", "ООО \"Созвездие\"");
    net.addPartOf("Постановка задачи", "Разработка текстового редактора \"Созвездие\"");
    net.addPartOf("Программирование", "Разработка текстового редактора \"Созвездие\"");
    net.addPartOf("Продвижение на рынок", "Разработка текстового редактора \"Созвездие\"");
    net.addPartOf("Поддержка", "Разработка текстового редактора \"Созвездие\"");
    net.addIsA("01.01.2021", "Срок начала этапа");
    net.addIsA("03.01.2021", "Срок начала этапа");
    net.addIsA("04.02.2021", "Срок начала этапа");
    net.addIsA("01.04.2021", "Срок начала этапа");
    net.addIsA("02.01.2021", "Срок окончания этапа");
    net.addIsA("03.02.2021", "Срок окончания этапа");
    net.addIsA("01.01.2022", "Срок окончания этапа");
    net.addIsA("01.01.2026", "Срок окончания этапа");
    net.addPartOf("01.01.2021", "Постановка задачи");
    net.addPartOf("03.01.2021", "Программирование");
    net.addPartOf("04.02.2021", "Продвижение на рынок");
    net.addPartOf("01.04.2021", "Поддержка");
    net.addPartOf("02.01.2021", "Постановка задачи");
    net.addPartOf("03.02.2021", "Программирование");
    net.addPartOf("01.01.2022", "Продвижение на рынок");
    net.addPartOf("01.01.2026", "Поддержка");
    net.addPartOf("01.01.2021", "Разработка текстового редактора \"Созвездие\"");
    net.addPartOf("03.01.2021", "Разработка текстового редактора \"Созвездие\"");
    net.addPartOf("04.02.2021", "Разработка текстового редактора \"Созвездие\"");
    net.addPartOf("01.04.2021", "Разработка текстового редактора \"Созвездие\"");
    net.addPartOf("02.01.2021", "Разработка текстового редактора \"Созвездие\"");
    net.addPartOf("03.02.2021", "Разработка текстового редактора \"Созвездие\"");
    net.addPartOf("01.01.2022", "Разработка текстового редактора \"Созвездие\"");
    net.addPartOf("01.01.2026", "Разработка текстового редактора \"Созвездие\"");

    //Разработа браузера "Созвездие"
    net.addIsA("Разработка Интернет - браузера \"Созвездие\"", "Задание");
    net.addPartOf("Разработка Интернет - браузера \"Созвездие\"", "ООО \"Созвездие\"");
    net.addPartOf("Постановка задачи", "Разработка Интернет - браузера \"Созвездие\"");
    net.addPartOf("Программирование", "Разработка Интернет - браузера \"Созвездие\"");
    net.addPartOf("Продвижение на рынок", "Разработка Интернет - браузера \"Созвездие\"");
    net.addPartOf("Поддержка", "Разработка Интернет - браузера \"Созвездие\"");
    net.addIsA("01.01.2022", "Срок начала этапа");
    net.addIsA("03.01.2022", "Срок начала этапа");
    net.addIsA("04.02.2022", "Срок начала этапа");
    net.addIsA("01.04.2022", "Срок начала этапа");
    net.addIsA("02.01.2022", "Срок окончания этапа");
    net.addIsA("03.02.2022", "Срок окончания этапа");
    net.addIsA("01.01.2023", "Срок окончания этапа");
    net.addIsA("01.01.2027", "Срок окончания этапа");
    net.addPartOf("01.01.2022", "Постановка задачи");
    net.addPartOf("03.01.2022", "Программирование");
    net.addPartOf("04.02.2022", "Продвижение на рынок");
    net.addPartOf("01.04.2022", "Поддержка");
    net.addPartOf("02.01.2022", "Постановка задачи");
    net.addPartOf("03.02.2022", "Программирование");
    net.addPartOf("01.01.2023", "Продвижение на рынок");
    net.addPartOf("01.01.2027", "Поддержка");
    net.addPartOf("01.01.2022", "Разработка Интернет - браузера \"Созвездие\"");
    net.addPartOf("03.01.2022", "Разработка Интернет - браузера \"Созвездие\"");
    net.addPartOf("04.02.2022", "Разработка Интернет - браузера \"Созвездие\"");
    net.addPartOf("01.04.2022", "Разработка Интернет - браузера \"Созвездие\"");
    net.addPartOf("02.01.2022", "Разработка Интернет - браузера \"Созвездие\"");
    net.addPartOf("03.02.2022", "Разработка Интернет - браузера \"Созвездие\"");
    net.addPartOf("01.01.2023", "Разработка Интернет - браузера \"Созвездие\"");
    net.addPartOf("01.01.2027", "Разработка Интернет - браузера \"Созвездие\"");
}

void LoadNetwork::loadTask3(SemanticNetwork &net){
    net.addIsA("Муравейник", "Название торгового центра");

    net.addIsA("Иванов", "Владелец");
    net.addIsA("Петров", "Владелец");
    net.addIsA("Сидоров", "Владелец");
    net.addIsA("Черёмухина", "Владелец");
    net.addIsA("Полежайкин", "Владелец");

    net.addIsA("Колёсики", "Магазин");
    net.addIsA("Магнеточка", "Магазин");
    net.addIsA("Все карманы", "Магазин");
    net.addIsA("Н.аудио", "Магазин");
    net.addIsA("Беспорядок", "Магазин");
    net.addIsA("1000 и 1 шуруп", "Магазин");
    net.addIsA("Винегрет", "Магазин");

    net.addIsA("Лекартсва", "Категория товаров");
    net.addIsA("Продукты", "Категория товаров");
    net.addIsA("Одежда", "Категория товаров");
    net.addIsA("Электроника", "Категория товаров");
    net.addIsA("Товары для дома", "Категория товаров");
    net.addIsA("Инструменты", "Категория товаров");

    net.addIsA("1", "Этаж");
    net.addIsA("2", "Этаж");
    net.addIsA("3", "Этаж");

    net.addIsA("Левое", "Крыло");
    net.addIsA("Правое", "Крыло");

    net.addIsA("Безналичный", "Способ оплаты");
    net.addIsA("Наличный", "Способ оплаты");

    net.addIsA("пн-пт 10:00-22:00", "Режим работы");
    net.addIsA("пн-пт 10:00-20:00", "Режим работы");
    net.addIsA("пн-пт 8:00-0:00", "Режим работы");
    net.addIsA("сб 10:00-22:00", "Режим работы");
    net.addIsA("сб 10:00-18:00", "Режим работы");
    net.addIsA("сб 8:00-18:00", "Режим работы");
    net.addIsA("вс 10:00-14:00", "Режим работы");
    net.addIsA("вс 8:00-14:00", "Режим работы");

    net.addPartOf("Лекарства", "Колёсики");
    net.addPartOf("1", "Колёсики");
    net.addPartOf("Левое", "Колёсики");
    net.addPartOf("пн-пт 8:00-0:00", "Колёсики");
    net.addPartOf("сб 8:00-18:00", "Колёсики");
    net.addPartOf("вс 8:00-14:00", "Колёсики");
    net.addPartOf("Безналичный", "Колёсики");
    net.addPartOf("Наличный", "Колёсики");
    net.addPartOf("Черёмухина", "Колёсики");

    net.addPartOf("Продукты", "Магнеточка");
    net.addPartOf("1", "Магнеточка");
    net.addPartOf("Правое", "Магнеточка");
    net.addPartOf("пн-пт 10:00-22:00", "Магнеточка");
    net.addPartOf("сб 10:00-22:00", "Магнеточка");
    net.addPartOf("вс 10:00-14:00", "Магнеточка");
    net.addPartOf("Безналичный", "Магнеточка");
    net.addPartOf("Наличный", "Магнеточка");
    net.addPartOf("Сидоров", "Магнеточка");

    net.addPartOf("Одежда", "Все карманы");
    net.addPartOf("2", "Все карманы");
    net.addPartOf("Правое", "Все карманы");
    net.addPartOf("пн-пт 10:00-22:00", "Все карманы");
    net.addPartOf("сб 10:00-18:00", "Все карманы");
    net.addPartOf("Наличный", "Все карманы");
    net.addPartOf("Петров", "Все карманы");

    net.addPartOf("Электроника", "Н.аудио");
    net.addPartOf("2", "Н.аудио");
    net.addPartOf("Левое", "Н.аудио");
    net.addPartOf("пн-пт 10:00-22:00", "Н.аудио");
    net.addPartOf("сб 10:00-18:00", "Н.аудио");
    net.addPartOf("Безналичный", "Н.аудио");
    net.addPartOf("Наличный", "Н.аудио");
    net.addPartOf("Петров", "Н.аудио");

    net.addPartOf("Товары для дома", "Беспорядок");
    net.addPartOf("Электроника", "Беспорядок");
    net.addPartOf("2", "Беспорядок");
    net.addPartOf("Правое", "Беспорядок");
    net.addPartOf("пн-пт 10:00-22:00", "Беспорядок");
    net.addPartOf("сб 10:00-18:00", "Беспорядок");
    net.addPartOf("Безналичный", "Беспорядок");
    net.addPartOf("Наличный", "Беспорядок");
    net.addPartOf("Иванов", "Беспорядок");

    net.addPartOf("Инструменты", "1000 и 1 шуруп");
    net.addPartOf("3", "1000 и 1 шуруп");
    net.addPartOf("Левое", "1000 и 1 шуруп");
    net.addPartOf("пн-пт 10:00-20:00", "1000 и 1 шуруп");
    net.addPartOf("сб 10:00-18:00", "1000 и 1 шуруп");
    net.addPartOf("Наличный", "1000 и 1 шуруп");
    net.addPartOf("Полежайкин", "1000 и 1 шуруп");

    net.addPartOf("Лекартсва", "Винегрет");
    net.addPartOf("Продукты", "Винегрет");
    net.addPartOf("Одежда", "Винегрет");
    net.addPartOf("Товары для дома", "Винегрет");
    net.addPartOf("Электроника", "Винегрет");
    net.addPartOf("Инструменты", "Винегрет");
    net.addPartOf("3", "Винегрет");
    net.addPartOf("Правое", "Винегрет");
    net.addPartOf("пн-пт 10:00-20:00", "Винегрет");
    net.addPartOf("сб 10:00-18:00", "Винегрет");
    net.addPartOf("Наличный", "Винегрет");
    net.addPartOf("Полежайкин", "Винегрет");

}
