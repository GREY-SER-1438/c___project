#include <iostream>
using namespace std;
#include "CoreLocation-8.h"
#include "Game.h"

void CoreLocation::run()
{
    cout << "\n=== ЦЕНТРАЛЬНОЕ ЯДРО ===\n";
    cout << "Пространство дрожит. Время искажено.\n";
    cout << "Перед тобой три слота панели стабилизации.\n\n";

    bool insertedDisk = false;
    bool insertedCatalyst = false;
    bool insertedChip = false;

    // ---------------------------------------------
    // 1) ЖЁСТКИЙ ДИСК — если есть
    // ---------------------------------------------
    if (game.hasResearchDisk)
    {
        cout << "Перед тобой слот данных.\n";
        cout << "1) Вставить жёсткий диск\n";

        ask({1});  // единственный вариант ради интерактива

        cout << "Жёсткий диск установлен. Панель принимает данные.\n\n";
        insertedDisk = true;
    }

    // ---------------------------------------------
    // 2) КАТАЛИЗАТОР — если есть
    // ---------------------------------------------
    if (game.catalystObtained)
    {
        cout << "Слот плазменного контура сияет мягким светом.\n";
        cout << "1) Установить плазменный катализатор\n";

        ask({1});

        cout << "Катализатор встал в паз. Контур стабилизируется.\n\n";
        insertedCatalyst = true;
    }

    // ---------------------------------------------
    // 3) МИКРОСХЕМА — если есть
    // ---------------------------------------------
    if (game.oxygenChipObtained)
    {
        cout << "Перед тобой порт системы жизнеобеспечения.\n";
        cout << "1) Вставить микросхему жизнеобеспечения\n";

        ask({1});

        cout << "Микросхема подключена. Фильтры оживают.\n\n";
        insertedChip = true;
    }

    // ---------------------------------------------
    // Подсчёт вставленных предметов
    // ---------------------------------------------
    int count = 0;
    if (insertedDisk)     count++;
    if (insertedCatalyst) count++;
    if (insertedChip)     count++;

    cout << "Панель анализирует состояние ядра...\n\n";

    // ---------------------------------------------
    // Концовка
    // ---------------------------------------------
    switch(count)
    {
        case 3: idealEnding(); break;
        case 2: twoItemsEnding(insertedDisk, insertedCatalyst, insertedChip); break;
        case 1: oneItemEnding(insertedDisk, insertedCatalyst, insertedChip); break;
        case 0: zeroItemsEnding(); break;
    }

    cout << "\n=== КОНЕЦ ИГРЫ ===\n";
    game.stop();

}

// ------------------ КОНЦОВКИ ------------------

void CoreLocation::idealEnding()
{
    cout << "Все три компонента установлены.\n";
    cout << "Аномалия схлопывается. Станция стабилизирована.\n";
    cout << "Ты спас станцию и выжил.\n";
}

void CoreLocation::twoItemsEnding(bool disk, bool catalyst, bool chip)
{
    // 2А — диск + катализатор
    if (disk && catalyst && !chip)
    {
        cout << "Данные отправлены, контур стабилен.\n";
        cout << "Но система воздуха не работает. Ты задыхаешься.\n";
        return;
    }

    // 2Б — диск + микросхема
    if (disk && chip && !catalyst)
    {
        cout << "Данные отправлены, воздух чист.\n";
        cout << "Но ядро нестабильно. Время сжимается...\n";
        cout << "Ты попал во временную петлю.\n";
        return;
    }

    // 2В — катализатор + микросхема
    if (catalyst && chip && !disk)
    {
        cout << "Контур стабилен, воздух чист.\n";
        cout << "Но исследования потеряны навсегда.\n";
        cout << "Ты выжил, но миссия провалена.\n";
        return;
    }
}

void CoreLocation::oneItemEnding(bool disk, bool catalyst, bool chip)
{
    if (disk)
    {
        cout << "Ты отправил данные.\n";
        cout << "Но воздух ядовит и ядро нестабильно.\n";
        cout << "Ты погиб, но данные спасены.\n";
        return;
    }

    if (catalyst)
    {
        cout << "Контур стабилизирован.\n";
        cout << "Но ты задохнулся — системы воздуха не работали.\n";
        return;
    }

    if (chip)
    {
        cout << "Воздух чист.\n";
        cout << "Но без данных и катализатора ядро взрывается.\n";
        cout << "Ты проваливаешься в аномалию навечно.\n";
        return;
    }
}

void CoreLocation::zeroItemsEnding()
{
    cout << "Ни одного компонента.\n";
    cout << "Ядро выходит из-под контроля.\n";
    cout << "Ты задыхаешься, а станция разрывается во времени.\n";
}


